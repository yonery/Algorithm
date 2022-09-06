// SWEA 5648번 원자 소멸 시뮬레이션

/*
 전형적인 시뮬레이션 문제입니다.  알고리즘은 30분만에 해결해서 풀었지만 50개중에 22개 맞음.... 
1. 시뮬레이션의 특성 고려하기
 - 중간에 가다가 0.5의 위치에서 부딪힐 수도 있는데 그걸 고려해주지 않았더니 틀렸네요...
=> 해결방법 : (-1000 ~1000) 의 시작 좌표에서 1000을 더해서 (0~2000) 범위의 수를 만들고 2배를 해서 4000 * 4000 map에 저장해줍니다. 
그러면 각각 0.5씩 이동하기 때문에 좌표 사이에서 부딪힐 경우도 해결 가능!

2. 초기화 신경쓰기
 - 저는 폭발이 일어난 후 배열에서 해당 원자를 지워버렸는데 그랬더니 원자가 이동 후의 map 초기화를 못 하더군요..
 나중에 발견하고 허탈.... 배열에서 지우기전에 지울 원자의 map을 먼저 초기화해줘서 해결했습니다.
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
struct at {
	int x;
	int y;
	int d;
	int k;
};
int map[4001][4001];
vector<at> v;

int rem(int rx, int ry) {
	int n = 0;
	for (int i = 0; i < v.size(); i++) {
		if (rx == v[i].x && ry == v[i].y) {
			n += v[i].k;
			v[i].k = 0;
		}
	}
	return n;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		memset(map, 0, sizeof(map));
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y, d, k;
			cin >> y >> x >> d >> k;
			v.push_back({ 2 * (x + 1000), 2 * (y + 1000), d, k });
		}
		int m = 0, res = 0;
		while (++m) {
			if (v.size() == 0)
				break;

			for (int i = 0; i < v.size(); i++) {
				map[v[i].x][v[i].y] = 0;
			}
			//가는 중에 격자 가운데서 부딪힐수도 있음

			vector<pair<int, int>> era;
			for (int i = 0; i < v.size(); i++) {
				int tx = v[i].x + dx[v[i].d], ty = v[i].y + dy[v[i].d];			
				//cout << tx << " " << ty << " : " << v[i].d << "\n";
				if (tx < 0 || tx>4000 || ty < 0 || ty>4000) {
					v[i].k = 0;
				}
				else {
                    v[i].x = tx, v[i].y = ty;
					map[tx][ty]++;
					if (map[tx][ty] > 1) {
						era.push_back({ tx,ty });

					}
				}
			}
			for (int i = 0; i < era.size(); i++)
				res += rem(era[i].first, era[i].second);

			int vs = v.size() - 1;
			for (int i = vs; i >= 0; i--) {
				if (v[i].k == 0) {
					map[v[i].x][v[i].y] = 0;
					v.erase(v.begin() + i);
				}
			}

			era.clear();

		}
		cout << "#" << t << " " << res << "\n";
	}
	return 0;
}

