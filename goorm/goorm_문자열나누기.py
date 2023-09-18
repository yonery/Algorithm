N = int(input())
S= input()

P = set()
for i in range(1, N-1):
	for j in range(i+1, N):
		P.add(''.join(S[:i]))
		P.add(''.join(S[i:j]))
		P.add(''.join(S[j:]))

R = sorted(list(P))
result = 0
for i in range(1, N-1):
	for j in range(i+1, N):
		result = max(result, R.index(S[:i]) + R.index(S[i:j]) + R.index(S[j:]))
		
print(result+3)
