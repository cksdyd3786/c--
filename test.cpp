import numpy as np
import matplotlib.pyplot as plt

def solve_heat_conduction(L, N, Ta, h_prime, T_left, T_right):
    dx = L / (N + 1)
    lam = h_prime
    A = -lam * dx**2 * Ta
    
    
    a = np.ones(N-1)              
    b = -(2 + lam * dx**2) * np.ones(N)  
    c = np.ones(N-1)              
    d = A * np.ones(N)          

    
    d[0] -= T_left
    d[-1] -= T_right

    for i in range(1, N):
        w = a[i-1] / b[i-1]
        b[i] -= w * c[i-1]
        d[i] -= w * d[i-1]

    T_internal = np.zeros(N)
    T_internal[-1] = d[-1] / b[-1]
    for i in range(N-2, -1, -1):
        T_internal[i] = (d[i] - c[i] * T_internal[i+1]) / b[i]

    
    T = np.concatenate(([T_left], T_internal, [T_right]))
    x = np.linspace(0, L, N+2)

    return x, T


L = 1.0           
N = 10           
Ta = 300          
h_prime = 5.0     
T_left = 400      
T_right = 350    

x, T = solve_heat_conduction(L, N, Ta, h_prime, T_left, T_right)

plt.plot(x, T, marker='o')
plt.xlabel('x (m)')
plt.ylabel('Temperature (K)')
plt.title('온도 분포')
plt.grid(True)
plt.show()