// BOJ 10451번 순열 사이클

#include <iostream>
#include <queue>
using namespace std;



int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {

		int N;
		scanf("%d", &N);
		int arr[1001] = { 0 };
		int chk[1001] = { 0 };
		queue <int> q;

		for (int i = 1; i <= N; i++) 
			scanf("%d", &arr[i]);

		int cnt = 0;
		int max = 0;

		for (int i = 1; i <= N; i++) {
			if (chk[i] == 0) {
				cnt++;
				chk[i] = cnt;
				q.push(i);
				while (!q.empty()) {
					int a = q.front();
					int b = arr[a];
					q.pop();

					if (chk[b] == 0) {
						chk[b] = cnt;
						q.push(b);
					}		
				}
			}
			max = max > chk[i] ? max : chk[i];
		}



		printf("%d\n", max);

	}
	return 0;
}
