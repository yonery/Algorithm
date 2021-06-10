#include <vector>
#include <iostream>
using namespace std;
bool check(int n){      // 2*4 = 4*2 임을 확인하여 반만 검사 
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return false;
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    int N=nums.size();
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            for(int k=j+1;k<N;k++){
                if(check(nums[i]+nums[j]+nums[k]))
                    answer++;
            }
    return answer;
}
