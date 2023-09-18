N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort(key=lambda x: (-(bin(x).count("1")), -x))
print(A[K-1])
