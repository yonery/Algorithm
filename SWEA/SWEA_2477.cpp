// SWEA 2477번 차량 정비소 (Priority Queue)

/*
우선순위큐를 이용해 구현한 차량 정비소입니다. 
예전에 풀었을 때에는 우선순위큐를 사용하는 법을 몰라서 매번 정렬하거나 검색해서 사용했는데 우선순위 큐를 사용하니 편리하긴 하네요...


* 고객 클래스 =  도착시간, 접수 창구 이용 번호, 정비 창구 이용 번호, 정비까지 전부 끝났는지 
* arr[i][0] = 해당 창구에서 걸리는 시간,  arr[i][1] = 현재 이용중인 고객에게 남은 시간, arr[i][2] = 이용중인 고객 번호
* brr 은 arr과 동일 

1. 우선순위큐에 해당 시간에 도착하는 고객 번호를 넣어줌
2. 작은 순대로 뽑아서 접수 창구가 비어있으면 할당해 줍니다
   -> 여기서 비어있는 곳 할당과 시간이 끝나면 비어있게 만드는 과정을 거꾸로해서 해맸어여.... 
   먼저 카운트-- 해서 비워주고 할당해야합니다.
   아니면 비어도 바로바로 접수를 못 받고 1초를 대기하는 상황이 발생합니다.
3. 접수 과정이 끝난 고객은 정비 대기 큐에 넣어줍니다.
4. 앞 과정과 똑같이 비면 채워주고 안 비어있으면 시간을 카운트 , 카운트가 다 되면 큐에 새 고객 할당하기 
5. 창구에 할당 시  a, b에 각각 접수하고 정비 받은 데스크 번호를 저장해서 기록해서 마지막에 비교


+ 우선순위 큐 임의 정렬 참고
http://hochulshin.com/cpp-priority-queue/
https://www.acmicpc.net/blog/view/22

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T, N, M, K, A, B, x, arr[11][3], brr[11][3];
class customer {
public:
	int t;
	int a;
	int b;
	bool fin;
};
vector<customer> v;
priority_queue<int, vector<int>, greater<int>> wait1;
queue<int> wait2;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		cin >> N >> M >> K >> A >> B;
		for (int i = 0; i < N; i++) {
			cin >> arr[i][0];
			arr[i][1] = arr[i][2] = 0;
		}
		for (int i = 0; i < M; i++) {
			cin >> brr[i][0];
			brr[i][1] = brr[i][2] = 0;
		}
		for (int i = 0; i < K; i++) {
			cin >> x;
			v.push_back({ x, -1, -1, false });
		}

		int time = 0;
		while (1) {
			bool end = true;
			for (int i = 0; i < K; i++) {
				if (v[i].fin == false) end = false;
				if (time == v[i].t) {
					wait1.push(i + 1);
				}
			}
			if (end) break;
			//접수 창구 
			// 고객번호 낮은 순
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i][2] != 0) {
					arr[i][1]--;
					if (arr[i][1] == 0) {
						wait2.push(arr[i][2]);
						arr[i][2] = 0;
					}
				}				
				if (arr[i][1] == 0 && wait1.size() > 0) {
					arr[i][1] = arr[i][0];
					arr[i][2] = wait1.top();
					v[wait1.top() - 1].a = i + 1;
					wait1.pop();
				}
			}
			//정비 창구
			//들어온 순
			for (int i = 0; i < M; i++) {
				if (brr[i][2] != 0) {
					brr[i][1]--;
					if (brr[i][1] == 0) {
						v[brr[i][2] - 1].fin = true;
						brr[i][2] = 0;
					}
				}
				if (brr[i][1] == 0 && wait2.size() > 0) {
					brr[i][1] = brr[i][0];
					brr[i][2] = wait2.front();
					v[wait2.front() - 1].b = i + 1;
					wait2.pop();
				}
			}
			time++;

		}
		int num = 0;
		for (int i = 0; i < K; i++) {
			if (v[i].a == A && v[i].b == B) num += (i + 1);
		}
        if(num==0) num = -1;
		cout << "#" << t << " "<< num<< "\n";
	}
	return 0;
}
