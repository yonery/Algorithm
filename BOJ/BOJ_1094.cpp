// BOJ  1094 막대기 (C++)

#include <iostream>
using namespace std;

int main() {
	int za = 64, count = 1, min = 64;
	int x;
	cin >> x;
	
	while (1) {
		if (za == x)
			break;
		min /= 2;
		count++;
		if ((za-min) >= x) {
			za -= min;
			count--;
		}	
	}
	cout << count << endl;
	return 0;
}
