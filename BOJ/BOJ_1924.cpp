// BOJ 1924 2007년 (C++)

#include <iostream>
using namespace std;
int main(){
    int arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31 };
    int x, y, sum = 0;
    cin>>x>>y;
    for(int i=0; i<x-1; i++)
        sum+=arr[i];
    sum+=y;
    sum = sum%7;
    if(sum==1) cout<<"MON";
    else if(sum==2) cout<<"TUE";
    else if(sum==3) cout<<"WED";
    else if(sum==4) cout<<"THU";
    else if(sum==5) cout<<"FRI";
    else if(sum==6) cout<<"SAT";
    else cout<<"SUN";
     
    return 0;
}
