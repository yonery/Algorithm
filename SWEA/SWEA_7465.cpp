// SWEA_7465 창용 마을 무리의 개수 (Union Find)

/*
유니온 파인드 실습도 했으면 Union 부분은 자꾸 헷갈린다... 
깊이가 더 낮은 것을 큰 트리에 붙이는 것.... 기억하기....
무리의 갯수는 루트노드가 자기 자신인 것만 카운트하면 됨
*/

#include <iostream>
#include <vector>
using namespace std;
#define swap(a, b){int t =a; a=b; b= t;}
int T, N, M, a, b, arr[101], level[101];
int Find(int x) {
	if (x == arr[x]) return x;
	return arr[x] = Find(arr[x]);
}
void Union(int x, int y) {
   //각 x, y의 루트노드 가져오기
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	//x가 항상 더 작은 트리가 되야함
	if (level[x] > level[y])
		swap(x, y);
	// x의 루트가 y가 되도록
	arr[x] = y;
	// x와 y 깊이가 같으면 y 늘려주기
	if (level[x] == level[y])
		++level[y];
	return;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio("false");
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			arr[i] = i, level[i] = 1;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			Union(a, b);
		}
		int num = 0;
		for (int i = 1; i <= N; i++) {
			arr[i] = Find(i);
			if (arr[i] == i) num++;
		}
		cout << "#" << t << " " <<num<< "\n";
	}

	return 0;
}
