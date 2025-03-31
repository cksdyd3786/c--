import gymnasium as gym
import ale_py

# Bank Heist 환경 생성
env = gym.make("ALE/Assault-v5", render_mode="human")

# 환경 초기화
obs, info = env.reset()

# 500 스텝 동안 실행
for _ in range(500):
    env.render()  # 화면 렌더링
    action = env.action_space.sample()  # 랜덤 액션 선택
    obs, reward, done, truncated, info = env.step(action)  # 환경 업데이트

    if done:  # 게임이 끝나면 재시작
        obs, info = env.reset()

env.close()  # 환경 종료
