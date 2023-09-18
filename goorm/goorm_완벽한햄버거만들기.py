N = int(input())
K = list(map(int, input().split()))

k = K.index(max(K))

for i in range(k, N-1):
	if K[i+1] - K[i] > 0:
		print("0")
		break
else:
	for i in range(k):
		if K[i+1] - K[i] < 0 :
			print("0")
			break
	else:
		print(sum(K))
