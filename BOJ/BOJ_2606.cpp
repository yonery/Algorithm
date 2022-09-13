// BOJ 2606번 바이러스 (Union Find)

#include <iostream>
using namespace std;
int par[101];
int Find(int x){
	if(x == par[x]){
		return x;
	}
	else{
		int y = Find(par[x]);
		par[x] = y;
		return y;
	}
}
void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x!=y){
		par[y] = x;
	}
}

int main() {

    int n, m;
    cin>>n>>m;

	// 초기화
	for(int i=0; i<=n; i++){
		par[i] = i;
	}

	int a, b;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		Union(a,b);
	}

	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(Find(1) == Find(i)) cnt++;
	}

	printf("%d\n", cnt-1);

	return 0;
}
