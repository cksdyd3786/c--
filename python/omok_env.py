import numpy as np
import gymnasium as gym
from gymnasium import spaces

class OmokEnv(gym.Env):
    def __init__(self, board_size=15):
        super(OmokEnv, self).__init__()
        self.board_size = board_size
        self.board = np.zeros((board_size, board_size), dtype=int)
        self.current_player = 1  # 1: 흑, -1: 백

        # 행동 공간: 가능한 위치
        self.action_space = spaces.Discrete(board_size * board_size)
        
        # 관찰 공간: 15x15 크기의 오목판 (빈칸: 0, 사용자: 1, AI: -1)
        self.observation_space = spaces.Box(low=-1, high=1, shape=(board_size, board_size), dtype=int)

    def reset(self, seed=None, options=None):
        self.board.fill(0)
        self.current_player = 1
        return self.board.copy(), {}

    def step(self, action):
        x, y = divmod(action, self.board_size)

        # 잘못된 위치에 돌을 두면 패널티 부여
        if self.board[x, y] != 0:
            return self.board.copy(), -10, False, False, {}  # 패널티 적용

        self.board[x, y] = self.current_player
        done, reward = self.check_winner(x, y)

        # **턴 교대 (Self-Play 핵심)**
        self.current_player *= -1  
        return self.board.copy(), reward, done, False, {}

    def check_winner(self, x, y):
        directions = [(1, 0), (0, 1), (1, 1), (1, -1)]  # 가로, 세로, 두 대각선
        for dx, dy in directions:
            count = 1
            for d in [-1, 1]:
                nx, ny = x + dx * d, y + dy * d
                while 0 <= nx < self.board_size and 0 <= ny < self.board_size and self.board[nx, ny] == self.current_player:
                    count += 1
                    nx, ny = nx + dx * d, ny + dy * d
                if count >= 5:
                    return True, 100  # 승리 시 보상
        return False, 0  # 계속 진행

    def block_or_win_reward(self, x, y, player):
        # 상대방의 승리를 막거나 자신의 승리를 준비하는 위치에 돌을 두면 보상
        directions = [(1, 0), (0, 1), (1, 1), (1, -1)]  # 가로, 세로, 두 대각선
        reward = 0
        for dx, dy in directions:
            for direction in [-1, 1]:
                count = 1
                empty_spots = 0
                for d in range(1, 5):
                    nx, ny = x + dx * direction * d, y + dy * direction * d
                    if not (0 <= nx < self.board_size and 0 <= ny < self.board_size):
                        break
                    if self.board[nx, ny] == player:
                        count += 1
                    elif self.board[nx, ny] == 0:
                        empty_spots += 1
                    else:
                        break
                if count >= 4 and empty_spots >= 1:
                    reward += 10  # 승리를 준비하는 곳에 돌을 두면 보상

        return reward

    def render(self):
        print(self.board)