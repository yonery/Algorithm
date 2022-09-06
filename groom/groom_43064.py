N = int(input())
arr = list(map(int, input().split()))
num = int(input())

l, r = 0, N-1
while l <= r:
	m = int((l+r)/2)
	if arr[m] == num:
		print(m+1)
		break
	elif arr[m] > num:
		r = m - 1
	else:
		l = m + 1
else:
	print("X")
