// 4014번 활주로 건설

/*
아무 생각없이 가로 세로 탐색함
*/


#include <iostream>
using namespace std;
int N, X;
int map[20][20];

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int num = 0;
		
		//가로 검사
		for (int i = 0; i < N; i++) {
			bool chk = true;
			int m = map[i][0], n = 1;
			for (int j = 1; j < N; j++) {
				if (abs(map[i][j] - m) > 1) {
					chk = false;
					break;
				}
				else if (map[i][j] == m) {
					n++;
					continue;
				}
				else if (map[i][j] == (m + 1) ) {
					if (n < X) {
						chk = false;
						break;
					}
					else {
						n = 1;
						m = m + 1;
						continue;
					}
				}
				else if (map[i][j] == (m - 1)) {
					for (int x = 1; x < X; x++) {
						if ((j + x) >= N) {
							chk = false;
							break;
						}
						if (map[i][j + x] != (m - 1)) {
							chk = false;
							break;
						}
					}
					if (chk == true) {
						j = j + X -1;
						n = 0;
						m = m - 1;
					}
					else
						break;
				}

			}
			if (chk == true)
				num++;
			

		}
		
		//세로 검사
		for (int j = 0; j < N; j++) {
			bool chk = true;
			int m = map[0][j], n = 1;
			for (int i = 1; i < N; i++) {
				if (abs(map[i][j] - m) > 1) {
					chk = false;
					break;
				}
				else if (map[i][j] == m) {
					n++;
					continue;
				}
				else if (map[i][j] == (m + 1)) {
					if (n < X) {
						chk = false;
						break;
					}
					else {
						n = 1;
						m = m + 1;
						continue;
					}
				}
				else if (map[i][j] == (m - 1)) {
					for (int x = 1; x < X; x++) {
						if ((i + x) >= N) {
							chk = false;
							break;
						}
						if (map[i + x][j] != (m - 1)) {
							chk = false;
							break;
						}
					}
					if (chk == true) {
						i = i + X -1;
						n = 0;
						m = m - 1;
					}
					else
						break;
				}

			}
			if (chk == true)
				num++;


		}
		cout << "#" << t << " " << num << "\n";
	}

	return 0;
}
