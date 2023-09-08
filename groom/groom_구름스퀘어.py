# 회의실 배정 (탐욕 알고리즘)

N = int(input())
event = [list(map(int, input().split())) for _ in range(N)]

event.sort(key=lambda x:(x[1], x[0]))
e = event[0][1]
result = 1
for i in range(1, N):
	if e < event[i][0]:
		result += 1
		e = event[i][1]

print(result)
