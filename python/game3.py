from stable_baselines3 import PPO
from stable_baselines3.common.env_util import make_vec_env
from omok_env import OmokEnv

env = make_vec_env(OmokEnv, n_envs=4)
model = PPO("MlpPolicy", env, verbose=1)
model.learn(total_timesteps=100000)  # 학습

model.save("omok_ppo")  # 모델 저장