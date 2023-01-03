import random
N = random.randint(4, 100)
A = [random.randint(1, 1000000) for i in range(N * 2)]
print(N)
print(*A)
