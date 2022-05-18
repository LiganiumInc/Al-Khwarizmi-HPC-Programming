def iter_factorial(n : int):
    fact = 1
    for i in range(2,n+1):
        fact *= i 
    return fact
