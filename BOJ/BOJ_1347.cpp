// 1347번 미로만들기
// https://www.acmicpc.net/problem/1347

// 최대 50만큼 움직일 수 있으니 100*100 맵의 중심점 (50,50)에서 이동만큼 '.'을 찍어줍니다.
// 그리고 그때 구한 최소값과 최대값의 x, y 범위 사이를 출력하면 됩니다. 

#include <iostream>
using namespace std;
int N, mxx, mxy, mnx, mny;
char arr[50], map[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> N;
	mxx = 50, mxy = 50, mnx = 50, mny = 50;
	int x = 50, y = 50, d = 2;
	map[x][y] = '.';
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 'R') {
			d++;
			if (d == 4) d = 0;
		}
		else if (arr[i] == 'L') {
			d--;
			if (d < 0) d = 3;
		}
		else if (arr[i] == 'F') {
			x = x + dx[d], y = y + dy[d];
			if (mxx < x) mxx = x;
			if (mxy < y) mxy = y;
			if (mnx > x) mnx = x;
			if (mny > y) mny = y;
		}
		map[x][y] = '.';
	}
	for (int i = mnx; i <= mxx; i++) {
		for (int j = mny; j <= mxy; j++) {
			if (map[i][j] == '.') cout << '.';
			else cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
