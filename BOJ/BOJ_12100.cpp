// BOJ 12100번 2048(easy) 

/*
단순 시뮬레이션인데 몇날 며칠 고생한 이유
(1)  i랑 j 를 거꾸로 쓰거나 i만 두 번 쓴 거 찾느라 
(2) 4방향 다 조건을 맞춰줘야하는 방향 중 하나에서 조건이나 수행하는 함수 하나가 빠져있는데 그 방향의 모든 함수가 수행 되지 않는다면 왜 그런지 모름;;
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N;
vector<vector<int>> map;
void print(vector<vector<int>> tt) {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tt[i][j] << " ";
		}
		cout << "\n";
	}
	
	return;
}
int bfs() {
	int ret = 0;
	queue <vector<vector<int>>> q;
	q.push(map);

	for (int r = 0; r <= 5; r++) {
		int qs = q.size();
		while (qs--) {
			vector<vector<int>> v = q.front();
			q.pop();
			for (int i = 0; i < N; i++) 
				for (int j = 0; j < N; j++) 
					ret = ret > v[i][j] ? ret : v[i][j];

			//print(v);

			vector<vector<int>> vv;
			vv.resize(N);
			
			

			//up
			for (int j = 0; j < N; j++) {
				queue <int> qa;
				int n = 0;
				for (int i = 0; i < N; i++) {
					if (v[i][j] != 0) {
						if (n == 0) {
							n = v[i][j];
						}
						else {
							if (n == v[i][j]) {
								qa.push(n * 2);
								n = 0;
							}
							else {
								qa.push(n);
								n = v[i][j];
							}
						}
					}
					if (i == (N - 1) && n != 0)
						qa.push(n);

				}
				for (int i = 0; i < N; i++) {
					if (!qa.empty()) {
						vv[i].push_back(qa.front());
						qa.pop();
					}
					else {
						vv[i].push_back(0);
					}


				}
			}
			
			q.push(vv);
			vv.clear();
			vv.resize(N);

			
			
			//down
			for (int j = 0; j < N; j++) {
				queue <int> qa;
				int n = 0;
				for (int i = (N - 1); i >= 0; i--) {
					if (v[i][j] != 0) {
						if (n == 0) {
							n = v[i][j];
						}
						else {
							if (n == v[i][j]) {
								qa.push(n * 2);
								n = 0;
							}
							else {
								qa.push(n);
								n = v[i][j];
							}
						}	
					}
					if (n != 0 && i == 0)
						qa.push(n);
				}
				for (int i = (N - 1); i >= 0; i--) {
					if (!qa.empty()) {
						vv[i].push_back(qa.front());
						qa.pop();
					}
					else {
						vv[i].push_back(0);
					}
				}
			}
			q.push(vv);
			vv.clear();
			vv.resize(N);
			
			
			//left
			for (int i = 0; i < N; i++) {
				int n = 0;
				queue<int> qa;
				for (int j = 0; j < N; j++) {
					if (v[i][j] != 0) {
						if (n == 0) {
							n = v[i][j];
						}
						else {
							if (n == v[i][j]) {
								qa.push(n * 2);
								n = 0;
							}
							else {
								qa.push(n);
								n = v[i][j];
							}
						}
					}
					if (n != 0 && j == (N - 1)) {
						qa.push(n);
					}
				}

				for (int j = 0; j < N; j++) {
					if (!qa.empty()) {
						vv[i].push_back(qa.front());
						qa.pop();
					}
					else {
						vv[i].push_back(0);
					}
				}
			}

			q.push(vv);
			vv.clear();
			
			vv.resize(N);
			
			//right;
			for (int i = 0; i < N; i++) {
				int n = 0;
				stack <int> qa;
				for (int j = (N - 1); j >= 0; j--) {
					if (v[i][j] != 0) {
						if (n == 0) {
							n = v[i][j];
						}
						else {
							if (n == v[i][j]) {
								qa.push(n * 2);
								n = 0;
							}
							else {
								qa.push(n);
								n = v[i][j];
							}
						}
						
					}
					if (n != 0 && j == 0)
						qa.push(n);
				}
				
				int qas = qa.size();
				for (int j = 0; j < N; j++) {
					if (j < (N - qas)) {
						vv[i].push_back(0);
					}
					else {
						vv[i].push_back(qa.top());
						qa.pop();
					}
				}			

			}

			q.push(vv);
			vv.clear();
			
		}
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> ele;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			ele.push_back(a);
		}
		map.push_back(ele);
	}

	cout<<bfs();

	return 0;
}
