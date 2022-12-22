// BOJ 5565 영수증 (C++)

#include <iostream>
using namespace std;

int main(){
	int sum, num;
    cin>>sum;
    for(int i=0; i<9; i++){
    	cin>>num;
        sum-=num;
    }
    cout<<sum<<"\n";
    return 0;
}
