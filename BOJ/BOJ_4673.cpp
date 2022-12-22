// BOJ 4673 셀프 넘버 (C++)

#include <iostream>
#include <string>
using namespace std;
int arr[10000];
void dfs(int n) {
	if (n >= 10000) return;
	string tmp = to_string(n);
	int num = n;
	for (int i = 0; i < tmp.length(); i++) {
		num += (int)(tmp[i] - '0');
	}
	arr[num] = 1;
	dfs(num);
	return;
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
			dfs(i);
		}
	}
	return 0;
}
