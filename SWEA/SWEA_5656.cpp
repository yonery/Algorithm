// SWEA 5656번 벽돌 깨기
// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo&categoryId=AWXRQm6qfL0DFAUo&categoryType=CODE

/* 
시뮬레이션 문제입니다. 구현은 1시간 내에 끝냈는데 중간에 i와  j를 거꾸로 쓰는 오타가 나서 30분 이상을 더 잡아먹었습니다 ㅠㅠ 
가로 인덱스의 경우를 dfs로 완전 탐색 해주고 변형되는 map을 계속 파라미터로 넘겼습니다.
큐에 추가적으로 깨뜨릴 구슬을 넣어서 깨주고, 구슬을 배열하는 것이 중요한데 큐를 이용해서 한쪽으로 밀었습니다.

*/

#include <iostream>
#include <cstring>
#include <queue>
#define INF 10000000
using namespace std;
int N, W, H, res;
int emap[16][13];
void check(int map[][13]) {
	int num = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] != 0)
				num++;

		}
	}

	res = res < num ? res : num;
	return;
}

void play(int idx, int map[][13]) {
	queue <pair<int, int>> q;

	//처음 부딪히는 구슬
	for (int i = 1; i <= H+1; i++) {
		if (i > H) {
			return;
		}
		if (map[i][idx] == 0)
			continue;
		if (map[i][idx] != 0) {
			q.push({ i, idx });
			break;
		}
	}

	//연관된 구슬깨기
	while (!q.empty()) {
		auto now = q.front();
		int x = now.first, y = now.second;
		int t = map[x][y];
		q.pop();
		map[x][y] = 0;
		if (t == 1)
			continue;
		if (t > 1) {
			for (int i = 1; i < t; i++) {
				if (x + i <= H) {
					q.push({ x + i, y });
				}
				if (x - i >= 1) {
					q.push({ x - i, y });
				}
				if (y + i <= W) {
					q.push({ x, y + i });
				}
				if (y - i >= 1) {
					q.push({ x, y - i });
				}

			}
		}


	}

	//깨진 구슬 다시 배열
	for (int i = 1; i <= W; i++) {
		queue <int> tmp;
		for (int j = H; j >= 1; j--) {
			if (map[j][i] != 0)
				tmp.push(map[j][i]);
		}
		for (int k = H; k >= 1; k--) {
			if (tmp.empty())
				map[k][i] = 0;
			else {
				map[k][i] = tmp.front();
				tmp.pop();
			}
		}
	}
	return;

}

void dfs(int cnt, int total, int map[][13]) {
	if (cnt >= total) {
		check(map);
		return;
	}

	for (int i = 1; i <= W; i++) {
		int arr[16][13];
		memcpy(arr, map, sizeof(arr));
		play(i, arr);

		check(arr);
		dfs(cnt + 1, total, arr);
	}

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		res = INF;
		emap[16][13] = { 0 };
		cin >> N >> W >> H;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> emap[i][j];
			}
		}

		dfs(0, N, emap);

		cout << "#" << test_case << " " << res << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
