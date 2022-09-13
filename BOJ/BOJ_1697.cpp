// BOJ 1697번 숨바꼭질 (BFS)

#include <iostream>
#include <queue>
using namespace std;
int visit[100001];
#define MAXN 100000
int main()
{
	int N, K;
	cin >> N >> K;
	int s = 0;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int qn = q.size();
		for (int i = 0; i < qn; i++) {
			int n = q.front();
			q.pop();
			if (n == K) {
				while (!q.empty())
					q.pop();
				break;
			}
			else {
                if(n-1>=0 && visit[n-1]==0){
                    q.push(n-1);
                    visit[n-1] = 1;
                }
                if(n+1<=MAXN && visit[n+1]==0){
                    q.push(n+1);
                    visit[n+1] = 1;
                }
				if(2*n <=MAXN && visit[2*n]==0){
                    q.push(2*n);
                    visit[2*n] = 1;
                }
			}
		}
		s++;
	}
	cout << s-1 << endl;
	return 0;
}
