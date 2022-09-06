#include <iostream>
using namespace std;
int R, C, mx, my, zx, zy, dir;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
char map[26][26];
int make_dir(int x, int y, int d) {
	char m = map[x][y];
	if (d == 0) {
		if (m == '|' ||m=='+') return 0;
		else if (m == '1') return 1;	
		else if (m == '4') return 3;
	}
	else if (d == 1) {
		if (m == '-' || m=='+') return 1;
		else if (m == '3') return 0;
		else if (m == '4') return 2;
	}
	else if (d == 2) {
		if (m == '|'||m=='+') return 2;
		else if (m == '2') return 1;
		else if (m == '3') return 3;
	}
	else {
		if (m == '-'||m=='+') return 3;
		else if (m == '1') return 2;
		else if (m == '2') return 0;
	}
	return d;
}

void move(int x, int y, int d) {
	if (map[x][y] == '.') {
		cout << x << " " << y << " ";
		bool chk[] = { false, false, false, false };
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx <= 0 || tx > R || ty <= 0 || ty > C) continue;
			else if (map[tx][ty] != '.') {
				if (i == 0 && (map[tx][ty] == '|' || map[tx][ty] == '+' || map[tx][ty] == '1' || map[tx][ty] == '4')) chk[i] = true;
				else if (i == 1 && (map[tx][ty] == '-' || map[tx][ty] == '+' || map[tx][ty] == '3' || map[tx][ty] == '4')) chk[i] = true;			
				else if (i == 2 && (map[tx][ty] == '|' || map[tx][ty] == '+' || map[tx][ty] == '2' || map[tx][ty] == '3')) chk[i] = true;	
				else if (i==3 && (map[tx][ty] == '-' || map[tx][ty] == '+' || map[tx][ty] == '1' || map[tx][ty] == '2')) chk[i] = true;				
			}
		}
		if (chk[0] && chk[1] && chk[2] && chk[3]) cout << "+";
		else if (chk[0] && chk[1]) cout << "2";
		else if (chk[0] && chk[2]) cout << "|";
		else if (chk[0] && chk[3]) cout << "3";
		else if (chk[1] && chk[2]) cout << "1";
		else if (chk[1] && chk[3]) cout << "-";
		else if (chk[2] && chk[3]) cout << "4";
		return;
	}
	int tx = x + dx[d], ty = y + dy[d], td = make_dir(tx, ty, d);
	move(tx, ty, td);
	return;
}
// dir : 0 북 1 동 2 남 3 서
int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') mx = i, my = j;
			if (map[i][j] == 'Z') zx = i, zy = j;
		}
	}
	for (int i = 0; i < 4; i++) {
		int tx = mx + dx[i], ty = my + dy[i]; 
		if (tx <= 0 || tx > R || ty <= 0 || ty > C) continue;
		else if(map[tx][ty] != '.') {
			if (tx == mx) {
				if (ty == my + 1) dir = 1;
				else if (ty == my - 1) dir = 3;
			}
			else if (ty == my) {
				if (tx == mx - 1) dir = 0;
				else if (ty == mx + 1) dir = 2;
			}
		}
	}

	move(mx, my, dir);

	return 0;
}
