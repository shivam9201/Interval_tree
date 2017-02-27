#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	pair<int,int>* b = new pair<int,int>[n];
	b[0] = make_pair(1,1);
	for(int i = 1;i<n;i++){
		b[i] = make_pair(0,0);
		for(int j = i-1;j>=0;j--){
			 if(a[j] > a[i]){
			 	b[i].first = max(b[i].first,b[j].second+1);
			 }
			 else if(a[j]<a[i]){
			 	b[i].second = max(b[i].second,b[j].first+1);
			 }
		}
	}
	
	cout<<max(b[n-1].first,b[n-1].second);
	return 0;
}