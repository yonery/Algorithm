// SWEA 5644번 무선 충전

/*
지난번 나무재테크 처럼 검사 방법 2처럼 풀려다가 BC 갯수가 적길래 그냥 매 BC마다 되는걸 검사해줬습니다.

1. 해당 위치에서 접속 가능한 BC를 각 an, bn 벡터에 삽입
2. an, bn 에서 각 사용자가 접속할 수 있는 BC 에 접속했을 경우의 최대값 구하기 
3. 최대값을 더해주고 이동

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int T, M, A, x, y, z, w, arr[101], brr[101];
class AP {
public:  
	int x;
	int y;
	int C;
	int P;
};
int dx[] = { 0, -1, 0, 1, 0 };
int dy[] = { 0, 0, 1, 0, -1 };
vector<AP> v;
vector<int> an, bn;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		cin >> M >> A;
		
		for (int i = 0; i < M; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> brr[i];
		}
		for (int i = 0; i < A; i++) {
			cin >> x >> y >> z >> w;
			v.push_back({ y, x, z, w });
		}
		// 검사 방법 1. 모든 AP와 비교하여 가능한 것 찾기
		//			 2. 3차원 벡터를 만들어서 해당 좌표에 할당하기
		int aum = 0, bum = 0, ax = 1, ay = 1, bx = 10, by = 10;
		for (int m = 0; m <= M; m++) {
			an.clear();
			bn.clear();
			for (int i = 0; i < A; i++) {
				int nx = v[i].x, ny = v[i].y, nc = v[i].C;
				if (abs(nx - ax) + abs(ny - ay) <= nc) an.push_back(i);
				if (abs(nx - bx) + abs(ny - by) <= nc) bn.push_back(i);
			}
			int na = 0, nb = 0, mx = 0;
			if (bn.size() == 0) {
				for (int i = 0; i < an.size(); i++) {
					if (mx < v[an[i]].P) mx = v[an[i]].P;
				}
				na = mx, nb = 0;
			}
			else if (an.size() == 0) {
				for (int i = 0; i < bn.size(); i++) {
					if (mx < v[bn[i]].P) mx = v[bn[i]].P;
				}
				na = 0, na = mx;
			}
			else{
				for (int i = 0; i < an.size(); i++) {
					for (int j = 0; j < bn.size(); j++) {
						if (an[i] != bn[j]) {
							int n = v[an[i]].P + v[bn[j]].P;
							if (mx < n) mx = n, na = v[an[i]].P, nb = v[bn[j]].P;
						}
						else {
							int n = v[an[i]].P;
							if (mx < n) mx = n, na = mx / 2, nb = mx / 2;
						}
					}
				}
			}
			aum += na, bum += nb;
			if (m == M) break;
			ax = ax + dx[arr[m]], ay = ay + dy[arr[m]], bx = bx + dx[brr[m]], by = by + dy[brr[m]];
		}
		cout << "#" << t << " " << aum + bum << "\n";
	}
	return 0;
}
