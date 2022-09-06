// SWEA 13458번 시험 감독 (data type)

/*
간단한 연산 문제.

+ 신경써야 할 부분은 응시자수를 가지고 연산하는 과정에서 필요한 숫자를  int형으로 선언해주면 데이터 범위를 벗어나서 fail..
+ long이나 long long 처리해줘야 pass
+ 데이터 타입 범위에 관한 문제
*/

#include <iostream>
using namespace std;

int N, B, C;
int arr[1000000];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> B >> C;

	long cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] > 0) {
            cnt++;
		    arr[i] = arr[i] - B;
            
            if(arr[i]>0){
                if (arr[i] <= C) {
				    cnt++;
			    }
			    else {	
				    cnt = cnt + (arr[i]/C);
				    arr[i] = arr[i] % C;
				    if (arr[i] > 0)
					    cnt++;
				    else
					    continue;
			}
        
            }	
		}	
	}
	cout << cnt;
	return 0;
}
