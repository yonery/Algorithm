// BOJ 3190번 뱀 (Simulation)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K, L, time, dir;
int map[101][101] = { 0 };
vector <pair<int, int>> apple;
vector<pair<int, char>> snake;
queue <pair<int, int>> q;

struct Point {
	int xpos;
	int ypos;
};

Point head;

int direction(int dir, char but) {
	if (but == 'L') {
		if (dir == 1)
			return 4;
		else if (dir == 2)
			return 1;
		else if (dir == 3)
			return 2;
		else if (dir == 4)
			return 3;
	}
	if (but == 'D') {
		if (dir == 1)
			return 2;
		else if (dir == 2)
			return 3;
		else if (dir == 3)
			return 4;
		else if (dir == 4)
			return 1;
	}
	if (but == 'A')
		return dir;
}

void check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		apple.push_back({ a,b });
		map[a][b] = 1;
	}
	cin >> L;
	time = 0;
	for (int j = 0; j < L; j++) {
		int a;
		char b;
		cin >> a >> b;
		snake.push_back({ a,b });
		time = a;
	}
	map[1][1] = 2;

	int t = 1, idx = 0;
	q.push({ 1,1 });
	dir = 1, head.xpos = 1, head.ypos = 1;
	while(1) {
		//check();

		if (dir == 1) {
			if (head.ypos + 1 > N) 
				break;
			else if (map[head.xpos][head.ypos + 1] == 2)
				break;
			else if (map[head.xpos][head.ypos + 1] == 1) {
				head.ypos = head.ypos + 1;
				map[head.xpos][head.ypos ] = 2;
				q.push({ head.xpos, head.ypos });
			}
			else {
				head.ypos = head.ypos + 1;
				map[head.xpos][head.ypos] = 2;
				q.push({ head.xpos, head.ypos});
				auto tt = q.front();
				q.pop();
				map[tt.first][tt.second] = 0;		
				

			}
				

		}
		else if (dir == 2) {
			if (head.xpos + 1 > N) 
				break;
			else if (map[head.xpos + 1][head.ypos] == 2)
				break;
			else if (map[head.xpos + 1][head.ypos] == 1) {
				head.xpos = head.xpos + 1;
				map[head.xpos][head.ypos] = 2;
				q.push({ head.xpos, head.ypos });
			}
			else {
				head.xpos = head.xpos + 1;
				map[head.xpos][head.ypos] = 2;
				q.push({ head.xpos, head.ypos });
				auto tt = q.front();
				q.pop();
				map[tt.first][tt.second] = 0;
				
			}

		}
		else if (dir == 3) {
			if (head.ypos - 1 < 1)
				break;
			else if (map[head.xpos][head.ypos - 1] == 2)
				break;
			else if (map[head.xpos][head.ypos - 1] == 1) {
				map[head.xpos][head.ypos - 1] = 2;
				head.ypos = head.ypos - 1;
				q.push({ head.xpos, head.ypos });

			}
			else {
				head.ypos = head.ypos - 1;
				map[head.xpos][head.ypos] = 2;
				q.push({ head.xpos, head.ypos });
				auto tt = q.front();
				q.pop();
				map[tt.first][tt.second] = 0;
				
			}
		}
		else if (dir == 4) {
			if (head.xpos - 1 < 1)
				break;
			else if (map[head.xpos - 1][head.ypos] == 2)
				break;
			else if (map[head.xpos - 1][head.ypos] == 1) {
				map[head.xpos - 1][head.ypos] = 2;
				head.xpos = head.xpos - 1;
				q.push({ head.xpos, head.ypos });

			}
			else {
				head.xpos = head.xpos - 1;
				map[head.xpos][head.ypos] = 2;
				q.push({ head.xpos, head.ypos });
				auto tt = q.front();
				q.pop();
				map[tt.first][tt.second] = 0;
				
			}
		}

		if (snake[idx].first == t) {
			dir = direction(dir, snake[idx].second);
			idx++;
			if (idx == L) {
				snake.push_back({ dir, 'A' });
			}
		}
		t++;
	}
	
	cout << t;
	
	return 0;
}
