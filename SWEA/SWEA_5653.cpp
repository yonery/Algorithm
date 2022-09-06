// SWEA 5653번 줄기세포배양

/*
그리고 저는 뒤에서부터 리스트 제거를 시도했지만 
보통 erase를 이용해 지우면 그 뒤의 인덱스들이 다 앞으로 당겨져오느리 O(n)이 걸립니다. 그
래서 값을 맨 뒤로 보내버리고 pop_back() 하는 방법으로 시간 단축하여 vector 리스트의 원소를 지우는 방법을 추천합니다

*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int map[651][651];
int res, N, M, K;

struct sta {
	int origin;
	int xpos;
	int ypos;
};

vector <sta> unuse;
vector <sta> use;
vector <sta> tmp;
vector<sta> tmp2;
vector <int> era;
vector <int> era2;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int find_func(int ix, int iy, int n) {
	for (int b = 0; b < unuse.size(); b++) {
		// 동시간대 미리 심어진 번식 세포
		if (unuse[b].xpos == ix && unuse[b].ypos == iy) {

			// 동시간대 번식 세포보다 크면 지울 인덱스 반환
			if (map[ix][iy] < n) {
				return b;
			}
			else
				return -1;
		}
	}
	return -1;
}

void print() {
	for (int i = 295; i <= 315; i++) {
		for (int j = 295; j <= 315; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		memset(map, 0, sizeof(map));
		res = 0;
		unuse.clear();
		use.clear();

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[300 + i][300 + j];
				if (map[300 + i][300 + j] != 0) {			
					unuse.push_back({ map[300 + i][300 + j], 300+i, 300+j });

				}
			}
		}

		// -1 소멸상태

		for (int k = 0; k < K; k++) {
			//print();
			tmp.clear();
			tmp2.clear();
			era.clear();
			era2.clear();
			

			//활성세포
			for (int i = 0; i < use.size(); i++) {
				int so = use[i].origin, sx = use[i].xpos, sy = use[i].ypos;
				for (int d = 0; d < 4; d++) {
					int dix = sx + dx[d], diy = sy + dy[d];

				// 번식 가능한 셀 추가
					if (map[dix][diy] == 0) {
						tmp.push_back({so, dix, diy});
					}
				}
				if (map[sx][sy] > 0)
					map[sx][sy]--;

				//활성이 끝나고 죽은 세포
				if (map[sx][sy] == 0) {
					era.push_back(i);
					map[sx][sy] = -1;
				}
			}
			//죽은 세포를 활성세포 배열에서 제거
			for (int r = era.size() - 1; r >= 0; r--) {
				use.erase(use.begin() + era[r]);
			}

			//비활성 세포
			for (int i = 0; i < unuse.size(); i++) {
				int eo = unuse[i].origin, ex = unuse[i].xpos, ey = unuse[i].ypos;
				if (map[ex][ey] > 0)
					map[ex][ey]--;
				//비활성->활성세포
				if (map[ex][ey] == 0) {
					map[ex][ey] = eo;
					use.push_back({ eo, ex, ey });
					era2.push_back(i);
				}
			}
			// 비활성 세포 리스트에서 제거
			for (int r = era2.size() - 1; r >= 0; r--) {
				unuse.erase(unuse.begin() + era2[r]);
			}

			//번식한 세포
			for (int r = 0; r < tmp.size(); r++) {
				int to = tmp[r].origin, tx = tmp[r].xpos, ty = tmp[r].ypos;
				if (map[tx][ty] == 0) {
					map[tx][ty] = to;
					unuse.push_back({ to, tx, ty });
				}

				//동시간대 세포 경쟁
				else {
					int b = find_func(tx, ty, to);
					if (b != -1) {
						unuse.erase(unuse.begin() + b);
						map[tx][ty] = to;
						unuse.push_back({ to, tx, ty });
					}
				}
			}
			//cout << unuse.size() << " " << use.size() << "\n\n";
		}

	
		res = unuse.size() + use.size();
		cout << "#" << t << " " << res << "\n";
	}
	return 0;
}
