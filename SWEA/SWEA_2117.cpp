// SWEA 2117번 홈 방범 서비스

/*
완탐인데 수학적 원리로 더 빠르게 풀었습니다. 이게 맞을까 했는데 맞더라구요;;
원래 각 좌표마다 t를 늘려서 포함되는 집의 갯수를 체크해서 비교해주는게 정석적인 완탐입니다.

1. 각 좌표에서 모든 집의 위치의 거리에 +1 한 것을 벡터에 넣습니다.
 -> 생각해보면 각 좌표에서 저 거리만큼의 마름모를 만들었을 때 마름모의 K는 위의 위치 값 +1 이 됩니다.
2. 정렬하여 조건에 해당하면 해당 집의 인덱스를 비교 할당합니다. (집의 인덱스 +1 = 해당 K 마름모 안의 집의 갯수)
 -> K가 작은 값의 집들은 K가 큰 값의 마름모에 무조건 안에 들어있습니다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt;
int map[100][100];
vector<pair<int, int>> h;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1, 0, 0 };
int km(int K) {
	if (K <= 0)
		return 0;
	return (K * K + (K - 1) * (K - 1));
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		h.clear();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					h.push_back({ i,j });
			}
		}

		vector<int> kk;
		int mx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//cout << i << " " << j << "=";
				for (int m = 0; m < h.size(); m++) {
					int hx = h[m].first, hy = h[m].second;
					kk.push_back(abs(hx - i) + abs(hy - j) + 1);
				}

				sort(kk.begin(), kk.end());

				for (int k = 0; k < kk.size(); k++) {

					if (km(kk[k]) <= ((k+1) * M)) {
						mx = max(mx, k + 1);
					}
				}
				kk.clear();


			}
		}
		cout << "#" << t << " " << mx << "\n";
	}
	return 0;
}
