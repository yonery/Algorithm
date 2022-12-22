// 1009 분산처리 (C++)

#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	for(int t=1; t<=T; t++){
		int a, b, n;
		cin>>a>>b;
		n = a;
		for(int i=1; i<b; i++){
			n *= a;
			n %= 100;
		}
		n %= 10;
		if(n==0) n = 10;
		cout<<n<<"\n";
	}
	return 0;
}
