// BOJ 3048번 개미

/*
 -> 오른방향으로 움직이는 개미 
        - 시작점 :  n1-1-i
        - 자신의 오른쪽에 위치한 개미의 수만큼 오른쪽으로 덜 움직이기에  T-i 만큼 더해줌
        - 위치할 수 있는 좌표 : n1-1-i+T-i

 -> 왼방향으로 움직이는 개미
       - 시작점 : n1+j
       - 자신의 왼쪽에 위치한 개미의 수만큼 왼쪽으로 덜 움직이기에 -T+j 만큼 더해줌
       - 위치할 수 있는 좌표 : n1+j-T+j

 -> n1 와 n2의 수가 동일하지 않더라도, 각 개미의 앞에서 같은 방향으로 움직이는 개미를 앞지를 수 없기에 움직이더라고 개미의 순서는 같다. 
 그리고 T값을 더해 움직일 수 있는 최종 범위를 구해주고 정렬하면 순서가 나옴
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string N1, N2;
int T, n1, n2;
int main() {
	cin >> n1 >> n2 >> N1 >> N2 >> T;
	vector<pair<int, char>> v;
	for (int i = 0; i < n1; i++) v.push_back({ n1 - 1 - i - i + T, N1[i] });
	for (int j = 0; j < n2; j++) v.push_back({ n1 + j + j - T, N2[j] });
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i].second;

	return 0;
}
