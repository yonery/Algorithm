from collections import deque
N, M = map(int, input().split())
bri = [[0]*(N+1) for _ in range(N+1)]
for _ in range(M):
	s, e = map(int, input().split())
	bri[s][e] = 1
vit = [0]*(N+1)
n = 1
def bfs(x):
	global N, n
	q = deque()
	q.append(x)
	vit[x] = n
	while q:
		top = q.popleft()
		for i in range(1, N+1):
			if bri[top][i] == 1 and bri[i][top] == 1 and vit[i] == 0:
				q.append(i)
				vit[i] = 1
	return
for i in range(1, N+1):
	if vit[i] == 0:
		vit[i] = 1
		bfs(i)
		n += 1
print(n-1)
