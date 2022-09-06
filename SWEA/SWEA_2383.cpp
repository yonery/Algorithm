// SWEA 2382번 점심 식사시간

/*
완탐 + 계산 했습니다.

비트연산자를 이용해 학생들이 어디 계단으로 향하는지 조합해주고 해당 계단에 도착했을 경우 수행되는 시간을 연산했습니다.
차량정비소를 푼 직후에 이 문제를 풀었더니 자꾸 계단마다 큐를 만들려고 해서 시간 초과났습니다....

+ 맵을 초기화할 때 <cstring> 의 memset을 이용하곤 했는데 그러면 시간을 많이 잡아먹습니다.
귀찮더라도 for문으로 초기화해주는 것이 좋습니다. 시뮬레이션 같은 경우는 해당 원소의 위치만 초기화.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MX 10000001
using namespace std;
int N, ax, ay, bx, by, res, at, bt;
int map[10][10];
vector<pair<int, int>> p;

int chk(int vit) {
	int n = 0;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < p.size(); i++) {
		if ((vit & (1 << i)) > 0) {
			a.push_back(abs(p[i].first - ax)+abs(p[i].second-ay));
		}
		else {
			b.push_back(abs(p[i].first-bx)+abs(p[i].second -by));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int an = 0, bn = 0;
	if (a.size() > 0) {
		for (int i = 3; i < a.size(); i++) {
			int t = a[i - 3] + at;
			if (t > a[i])
				a[i] = t;
		}

		an = a.back() + at;
	}
	if (b.size() > 0) {
		for (int i = 3; i < b.size(); i++) {
			int t = b[i - 3] + bt;
			if (t > b[i])
				b[i] = t;
		}
		bn = b.back() + bt;
	}
	
	return max(an, bn) + 1;
}


void dfs(int idx, int visit) {
	if (idx == p.size()) {
		res = res < chk(visit) ? res : chk(visit);
		return;
	}
	dfs(idx + 1, (visit | (1 << idx)));
	dfs(idx + 1, visit);

	return;
}


int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                map[i][j] =0;
        p.clear();
     
		ax = -1, ay = -1, bx = -1, by = -1, res = MX, at = 0, bt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					p.push_back({ i,j });
				}
				else if (map[i][j] > 1) {
					if (ax < 0) {
						ax = i, ay = j;
						at = map[i][j];
					}
					else {
						bx = i, by = j;
						bt = map[i][j];
					}
				}
			}
		}

		dfs(0, 0);
		cout << "#" << t << " " << res << "\n";
	}

	return 0;
}
