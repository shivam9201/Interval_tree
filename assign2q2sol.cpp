#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;												// n is num of rows, m is num of columns
	map<pair<pair<int,int>,pair<int,int> > , int> mp;  		// map of all bad edges
	int k; 													// number of bad edges
	cin>>k;
	for(int i = 0;i<k;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		mp[MP(MP(x1,y1),MP(x2,y2))] = 1;
		mp[MP(MP(x2,y2),MP(x1,y1))] = 1;
	}
	long long int ans[n+1][m+1];
	ans[0][0] = 1;
	for(int i = 1;i<=m;i++){
		ans[0][i] = 0;
		if(mp[MP(MP(0,i),MP(0,i-1))]!=1){
			ans[0][i] = ans[0][i-1];
		}
	}
	for(int i = 1;i<=n;i++){
		ans[i][0] = 0;
		if(mp[MP(MP(i,0),MP(i-1,0))]!=1){
			ans[i][0] = ans[i-1][0];
		}
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			ans[i][j] = 0;
			if(mp[MP(MP(i-1,j),MP(i,j))]!=1){
				ans[i][j]+=ans[i-1][j];
			}
			if(mp[MP(MP(i,j-1),MP(i,j))]!=-1){
				ans[i][j]+=ans[i][j-1];
			}
		}
	}
	cout<<ans[n][m]<<endl;
	return 0;
}