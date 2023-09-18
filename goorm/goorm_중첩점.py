N, M = map(int,input().split())
mp = [[[0]*N for _ in range(N)] for _ in range(2)]
direc = {'R':0, 'D':1, 'L':2, 'U':3}
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


for _ in range(M):
	sx, sy, d =  input().split()
	x = int(sx)-1
	y = int(sy)-1

	while 0 <= x < N and 0 <= y < N:
		if d == 'R' or d == 'L':
			mp[0][x][y] += 1
		else:
			mp[1][x][y] += 1
		x = x + dx[direc[d]]
		y = y + dy[direc[d]]


result = 0
for i in range(N):
	for j in range(N):
		result += (mp[0][i][j] * mp[1][i][j])
		
print(result) 
