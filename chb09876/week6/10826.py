import sys
sys.setrecursionlimit(10**6)

def fibo(N):
  if N == 0:
    return 0
  if not fibonacci[N]:
    fibonacci[N] = fibo(N - 1) + fibo(N - 2)
  return fibonacci[N]

fibonacci = [0] * 10001;
fibonacci[0] = 0;
fibonacci[1] = 1;
n = int(input())
print(fibo(n))
