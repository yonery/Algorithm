// BOJ 15954 인형들 (C++)

#include <iostream>
#include <cmath>
using namespace std;
long long N, K, arr[501], sumarr[501];
double ret;
int main(void)
{
	cin >> N >> K;
	cin >> arr[0];
	sumarr[0] = arr[0];
	for (int i = 1; i < N; i++)	cin >> arr[i], sumarr[i] = sumarr[i - 1] + arr[i];
	ret = 2147283647;
	for (int i = 0; i <= N - K; i++) {
		for (int j = i + K - 1; j < N; j++) {
			double cnt = j - i + 1, avg = (sumarr[j]-sumarr[i-1]) / cnt, m = 0;
			for (int k = i; k <= j; k++) m += (arr[k] - avg)*(arr[k] - avg);
			m = sqrt(m/cnt);
			if (ret > m) ret = m;
		}

	}

	cout << fixed;
	cout.precision(11);
	cout << ret << "\n";

	return 0;
}
