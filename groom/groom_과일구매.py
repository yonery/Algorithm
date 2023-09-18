N, K = map(int, input().split())
fruit = [list(map(int, input().split())) for _ in range(N)]
feel = [[fruit[i][1]/fruit[i][0], i] for i in range(N)]
feel.sort(key=lambda x: (-x[0], -fruit[x[1]][0]))
idx = 0
result = 0
while idx < N and K > 0 :
	if fruit[feel[idx][1]][0] != 0:
		if fruit[feel[idx][1]][0] <= K:
			result += (fruit[feel[idx][1]][1])
			K -= fruit[feel[idx][1]][0]
			fruit[feel[idx][1]][0] = 0
		else:
			result += int((fruit[feel[idx][1]][1]/fruit[feel[idx][1]][0])*K)
			K = 0
	#print(K, result, feel[idx][1], fruit)
	idx += 1
			
print(result)
