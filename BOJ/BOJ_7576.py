# BOJ 7576 토마토 (Python)

from collections import deque

M, N = map(int, input().split())
mp = [list(map(int, input().split())) for _ in range(N)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def bfs():
    global M, N

    tomato = deque()
    not_tomato = 0
    for i in range(N):
        for j in range(M):
            if mp[i][j] == 1:
                tomato.append([i, j])
            if mp[i][j] == -1:
                not_tomato += 1
    cnt = len(tomato)

    if (cnt + not_tomato) == M*N:
        return 0

    day = 1
    while tomato:
        qn = len(tomato)
        for _ in range(qn):
            now = tomato.popleft()
            nx, ny = now[0], now[1]
            for d in range(4):
                tx, ty = nx + dx[d], ny + dy[d]
                if 0 <= tx < N and 0 <= ty < M and mp[tx][ty] == 0:
                    tomato.append([tx, ty])
                    mp[tx][ty] = 1
                    cnt += 1
                    if (cnt + not_tomato) == M * N:
                        return day
        day += 1
        #print(tomato, day, cnt+not_tomato, N*M)
    if (cnt + not_tomato) == M*N:
        return day
    else:
        return -1


print(bfs())
