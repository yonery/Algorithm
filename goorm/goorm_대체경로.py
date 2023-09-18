from collections import deque
N, M, S, E  = map(int,input().split())
edges = [[] for _ in range(N+1)]
for _ in range(M):
	u, v = map(int, input().split())
	edges[u].append(v)
	edges[v].append(u)

def bfs(x):
	global S, E, N
	if S == x or E == x:
		return -1
	
	q = deque()
	q.append(S)
	visit = [0]*(N+1)
	visit[S] = 1
	result = 1
	while q:
		qn = len(q)
		for _ in range(qn):
			top = q.popleft()
			#print(top, end=" ")
			if top == E:
				return result
			for e in edges[top]:
				if e != x and visit[e] == 0:
					visit[e] = 1
					q.append(e)
		result += 1
	return -1
	

	
for i in range(1, N+1):
	print(bfs(i))
