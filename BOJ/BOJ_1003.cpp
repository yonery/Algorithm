// BOJ 1003 피보나치 (C++)

#include<iostream>
using namespace std;

int main() {
	int T, N, fib[42] = { 1,0,1 };
	for (int i = 3; i < 42; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << fib[N] << " " << fib[N + 1] << endl;
	}
	return 0;

}
