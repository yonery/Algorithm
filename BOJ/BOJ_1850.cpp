// BOJ 1850번 최대공약수 (유클리드 호제법)

#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	long long A, B;
	cin >> A >> B;
	long long C = gcd(A, B);
	for (int i = 0; i < C; i++) {
		cout << "1";
	}

	return 0;
}
