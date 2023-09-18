N, K, Q = map(int, input().split())
mp = [list(input()) for _ in range(N)]
xyq = [input().split() for _ in range(Q)]
vit = [[0]*N for _ in range(N)]
res = 0

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def dfs(x, y, n):
	global N, res
	res += 1
	for d in range(4):
		tx, ty = x + dx[d], y + dy[d]
		if 0 <= tx < N and 0 <= ty < N and mp[tx][ty] == n and vit[tx][ty]== 0:
			vit[tx][ty] = 1
			dfs(tx, ty, n)
			
def rem(x, y, n):
	global N
	mp[x][y] = '.'
	for d in range(4):
		tx, ty = x + dx[d], y + dy[d]
		if 0 <= tx < N and 0 <= ty < N and mp[tx][ty] == n:
			rem(tx, ty, n)

def chk():
	global K, N, res
	for i in range(N):
		for j in range(N):
			vit[i][j] = 0 
	for i in range(N):
		for j in range(N):
			if vit[i][j] == 0 and mp[i][j] != '.':
				res = 0
				vit[i][j] = 1
				dfs(i, j, mp[i][j])
				if res >= K:	
					rem(i, j, mp[i][j])

				

for q in xyq:
	mp[int(q[0])-1][int(q[1])-1] = q[2]
	chk()
	
for i in range(N):
	print(*mp[i], sep='')
