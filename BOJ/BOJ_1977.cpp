// BOJ 1977번 완전제곱수

#include <stdio.h>
int main() {
	int M, N;
	scanf("%d", &M);
	scanf("%d", &N);
	int count = 0, sum = 0, min = 10000;
	for (int i = 1; i <= N; i++) {
		int num = i * i;
		if (num >= M && num <= N) {
			count++;
			sum += num;
			if (count == 1)
				min = num;
		}
		if (num > N)
			break;
	}
	if (count == 0)
		printf("-1");
	else {
		printf("%d\n%d", sum, min);
	}
	return 0;
}
