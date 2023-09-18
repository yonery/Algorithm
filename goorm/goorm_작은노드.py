N, M, K = map(int, input().split())
nodes = [[] for _ in range(N+1)]
for _ in range(M):
	s, e = map(int, input().split())
	nodes[s].append(e)
	nodes[e].append(s)
	
visit = [0]*(N+1)
visit[K] = 1
n = 1
pre = -1
while pre != K:
	if nodes[K]:
		nodes[K].sort()
		m = 0
		for k in nodes[K]:
			if visit[k] == 0:
				m = k
				visit[m] = 1
				n += 1
				pre = K
				K = m
				break
		else:
				break
	else:
		break


print(n, K)
