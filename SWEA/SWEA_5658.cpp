// SWEA 5658번 보물상자 비밀번호
// char to int에서 '1'을 1로 바꾸려면 (int) (a -'0')해주면 됩니다. 아스키 코드 번호에서 0보다 몇번째인지가 나오는거니까요


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
vector <char> v;
vector<int> mx;

int con(char a) {
	if (a == 'A')
		return 10;
	else if (a == 'B')
		return 11;
	else if (a == 'C')
		return 12;
	else if (a == 'D')
		return 13;
	else if (a == 'E')
		return 14;
	else if (a == 'F')
		return 15;
	
	return (int)(a - '0');
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		mx.clear();
		v.clear();
		for (int i = 0; i < N; i++) {
			char a;
			cin >> a;
			v.push_back(a);
		}
		int m = N / 4;

		for (int i = 0; i < v.size(); i++) {
			int num = 0;
			for (int j = i; j < (i+m); j++) {
				int k = m - (j - i) -1;
				int r = (j%N);
				num += con(v[r]) * pow(16, k);
			}

			if(mx.end()==find(mx.begin(), mx.end(), num))
				mx.push_back(num);		
		}
		
		sort(mx.begin(), mx.end());

		cout << "#" << t << " " << mx[mx.size() - K] << "\n";

	}
	return 0;
}
