import pygame
import numpy as np
from stable_baselines3 import PPO

# 게임 설정
BOARD_SIZE = 15
CELL_SIZE = 40
MARGIN = 20
WIDTH = HEIGHT = BOARD_SIZE * CELL_SIZE + 2 * MARGIN

# 색상 정의
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LINE_COLOR = (0, 0, 0)
STONE_COLORS = {1: (0, 0, 0), -1: (255, 255, 255)}

class OmokGUI:
    def __init__(self, model_path="omok_ppo"):
        pygame.init()
        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        pygame.display.set_caption("오목 AI 대결")
        self.clock = pygame.time.Clock()
        self.board = np.zeros((BOARD_SIZE, BOARD_SIZE), dtype=int)
        self.current_player = 1  # 1: 사용자(흑), -1: AI(백)
        self.model = PPO.load(model_path)

    def draw_board(self):
        self.screen.fill(WHITE)
        for i in range(BOARD_SIZE):
            pygame.draw.line(self.screen, LINE_COLOR, (MARGIN, MARGIN + i * CELL_SIZE), (WIDTH - MARGIN, MARGIN + i * CELL_SIZE))
            pygame.draw.line(self.screen, LINE_COLOR, (MARGIN + i * CELL_SIZE, MARGIN), (MARGIN + i * CELL_SIZE, HEIGHT - MARGIN))
        
        for x in range(BOARD_SIZE):
            for y in range(BOARD_SIZE):
                if self.board[x, y] != 0:
                    color = STONE_COLORS[self.board[x, y]]
                    pygame.draw.circle(self.screen, color, (MARGIN + y * CELL_SIZE, MARGIN + x * CELL_SIZE), CELL_SIZE // 2 - 2)

    def get_board_position(self, pos):
        x = (pos[1] - MARGIN + CELL_SIZE // 2) // CELL_SIZE
        y = (pos[0] - MARGIN + CELL_SIZE // 2) // CELL_SIZE
        return int(x), int(y)

    def user_move(self, x, y):
        if 0 <= x < BOARD_SIZE and 0 <= y < BOARD_SIZE and self.board[x, y] == 0:
            self.board[x, y] = 1
            return True
        return False

    def ai_move(self):
        obs = self.board.copy().reshape(1, BOARD_SIZE, BOARD_SIZE)
        action, _ = self.model.predict(obs, deterministic=True)
        x, y = divmod(action, BOARD_SIZE)

        while self.board[x, y] != 0:
            action = np.random.choice(np.where(self.board.flatten() == 0)[0])
            x, y = divmod(action, BOARD_SIZE)

        self.board[x, y] = -1  # AI(백) 차례

    def check_winner(self):
        directions = [(1, 0), (0, 1), (1, 1), (1, -1)]
        for x in range(BOARD_SIZE):
            for y in range(BOARD_SIZE):
                if self.board[x, y] == 0:
                    continue
                player = self.board[x, y]
                for dx, dy in directions:
                    count = 1
                    for d in [-1, 1]:
                        nx, ny = x + dx * d, y + dy * d
                        while 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and self.board[nx, ny] == player:
                            count += 1
                            nx, ny = nx + dx * d, ny + dy * d
                        if count >= 5:
                            return player
        return 0

    def play(self):
        running = True
        while running:
            self.draw_board()
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.MOUSEBUTTONDOWN and self.current_player == 1:
                    x, y = self.get_board_position(event.pos)
                    if self.user_move(x, y):
                        if self.check_winner():
                            print("🎉 당신이 승리했습니다!")
                            running = False
                        else:
                            self.ai_move()
                            if self.check_winner():
                                print("😢 AI가 승리했습니다!")
                                running = False

        pygame.quit()

if __name__ == "__main__":
    game = OmokGUI()
    game.play()