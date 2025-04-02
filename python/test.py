import math


Q = 0.3  
epsilon = 0.26e-3  
nu = 0.001 / 998  
g = 9.81  
hL_per_L_max = 0.006  


def colebrook(f, Re, epsilon, D):
    return 1 / math.sqrt(f) + 4.0 * math.log10((epsilon / (3.7 * D)) + (1.26 / (Re * math.sqrt(f))))


D = 0.01  
D_step = 0.001  

while True:
    
    A = math.pi * (D ** 2) / 4
    v = Q / A
    
   
    Re = v * D / nu
    
    
    f_guess = 0.005  
    for _ in range(20):  
        f_new = 1 / (4 * (math.log10((epsilon / (3.7 * D)) + (1.26 / (Re * math.sqrt(f_guess))))) ** 2)
        if abs(f_new - f_guess) < 1e-6:  
            break
        f_guess = f_new
    f = f_guess
    
    
    hL_per_L = f * (2 * v**2) / (D * g)
    
    
    if hL_per_L <= hL_per_L_max:
        break
    
    
    D += D_step


print(f"최소 파이프 내경: {D:.4f} m")