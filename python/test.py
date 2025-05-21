import numpy as np

x = np.array([0.6, 1.5, 1.6, 2.5, 3.5])
fx = np.array([0.9036, 0.3734, 0.3261, 0.08422, 0.01596])

df_numeric = np.zeros_like(fx)

for i in range(len(x)):
    if i == 0:
        h = x[i+1] - x[i]
        df_numeric[i] = (fx[i+1] - fx[i]) / h
    elif i == len(x)-1:
        h = x[i] - x[i-1]
        df_numeric[i] = (fx[i] - fx[i-1]) / h
    else:
        h1 = x[i] - x[i-1]
        h2 = x[i+1] - x[i]
        df_numeric[i] = ((-h2)*fx[i-1] + (h2 - h1)*fx[i] + h1*fx[i+1]) / (h1*h2*(h1 + h2)) * (h1 + h2)

df_true = -10 * np.exp(-2 * x)

print("   x     |  Numeric df  |  True df     | Error")
print("-----------------------------------------------")
for i in range(len(x)):
    print(f"{x[i]:7.2f} | {df_numeric[i]:12.6f} | {df_true[i]:12.6f} | {abs(df_numeric[i] - df_true[i]):.6f}")