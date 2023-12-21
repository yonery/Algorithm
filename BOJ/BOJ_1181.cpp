// 1181 단어 정렬 (C++)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, string>> v;
vector <string> vv;
bool compare(const pair<int,string> &a, const pair<int,string> &b){
	return a.second < b.second;
}
int main(){
	cin>>N;   
    for(int i=0; i<N; i++){
        string s;
    	cin>>s;
        if(vv.end()== find(vv.begin(), vv.end(), s)){ 
            vv.push_back(s);
            v.push_back({s.length(), s});
        }
    }
    N = v.size();
    sort(v.begin(), v.end());
    int s =-1, e=-1, len = 0;
    for(int i=0; i<N; i++){
		if(len != v[i].first && s ==-1){
            s = i;
            len = v[i].first;
        }
        if(len != v[i].first && s != -1){
            e = i-1;
        	sort(v.begin()+s, v.begin()+e, compare);
        	s = -1;
        }
    }
    for(int i=0; i<N; i++){
        cout<<v[i].second<<"\n";
    }
    return 0;
}
