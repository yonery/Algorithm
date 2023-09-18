N, K = map(int, input().split())
M = [list(map(int, input().split())) for _ in range(N)]
k = [[0]*N for _ in range(N)]
dx = [0, 0, 1, -1, 1, -1, 1, -1]
dy = [1, -1, 0, 0, 1, 1, -1, -1]

G = []
for x in range(N):
	for y in range(N):
		if M[x][y] == 1:
			for d in range(8):
				tx, ty = x + dx[d], y + dy[d]
				if 0 <= tx < N and 0 <= ty < N and M[tx][ty] == 0:
					k[tx][ty] += 1

result = 0
for i in range(N):
	for j in range(N):
		if k[i][j] == K:
			result += 1
print(result)
