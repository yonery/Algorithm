// 14890 경사로 (C++)
#include <iostream>

using namespace std;
int N, X;
int map[101][101];

int main(){

		cin >> N >> X;

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
		cout << num << "\n";

	return 0;
}
