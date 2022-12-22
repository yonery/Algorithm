// BOJ 1032 명령 프롬프트 (C++)

#include <iostream>
#include <string>
using namespace std;
int N;
string ret, tmp;
int main() {
	cin >> N;
	ret = "";
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (ret == "") {
			ret = tmp;
		}
		else {
			int n = tmp.length();
			for (int i = 0; i < n; i++) {
				if (ret[i] != tmp[i]) {
					ret[i] = '?';
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}

