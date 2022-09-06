// SWEA 6782번 현주가 좋아하는 제곱근 놀이 (data type)

/*
1. 실수형인 sqrt(N)을 정수형으로 강제 형변환 하면 소수점이 날아가고 n*n <= N < (n+1)*(n+1) 이 되면서 n은 정수형인 경우가 성립한다.
2. 즉 n*n = N 일 경우는 제곱근의 수로 바꿔줄 수 있음
3. 그렇지 않을 경우 N은 +1을 할 수 있는데 다음 제곱근까지의 차이는 (n+1)*(n+1) - N 이 되므로 일일히 계산하지 않고 바로 횟수를 더해줄 수 있음
4. 주어진 N은 2 <= N <= 10^12 로 int형의 범위를 벗어나기에 N과 n은 long long 형으로 선언해야함 

자료형 참고
https://dojang.io/mod/page/view.php?id=45

*/

#include <iostream>
#include <cmath>
using namespace std;
int T, ret;
long long n, N;
int main(){
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ret = 0;
		while (N>2) {			
			n = (long long)sqrt(N);
			if (n*n == N) {
				N = n;
				ret++;
			}
			else {
				ret += (n + 1)*(n + 1) - N;
				N = (n + 1)*(n + 1);
			}
		}
		cout <<"#"<<t<<" "<< ret << "\n";
	}


	return 0;
}
