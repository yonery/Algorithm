// SWEA 1890번 점프 (DP)

/*
1. 각각의 위치에 올 수 있는 방법의 수를 더해서 해당 위치에 올 수 있는 방법의 수를 구함
2. bfs, dfs로 했더니 둘 다 시간 초과남. 된다면 왜 되는지 좀 알아봐야겠음
3. 그래서 dp처럼 풀었더니 시간 초과 해결됨

*/

#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
//int visit로 하면 범위를 벗어나서 문제를 틀림
long visit[101][101] = { 0 };
 
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	visit[1][1] = 1;
    
// 큐를 이용해서 풀었더니 메모리 초과남
// bfs, dfs 로 하니 시간 초과남 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0 || visit[i][j]==0) 
				continue;
			
			int a = arr[i][j];
			int d = a + i;
			int r = a + j;
			if (d <= N) {
				visit[d][j] += visit[i][j];

			}
			if (r <= N) {
				visit[i][r] += visit[i][j];

			}

		}
	}
	
		


	printf("%ld", visit[N][N]);

	return 0;
}
