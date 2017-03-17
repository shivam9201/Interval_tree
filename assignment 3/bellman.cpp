#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
#define MP make_pair

using namespace std;

vector<pair<pair<int,int>,int> > edges; 
int num_of_vertices,num_of_edges;

void bellman_ford(int start){
	long long* dist = new long long[num_of_vertices+1];
	for(int i = 0;i<=num_of_vertices;i++){
		dist[i] = INT_MAX;
	}
	dist[start] = 0;
    
	for(int i = 0;i<num_of_vertices-1;i++){
		for(int j = 0;j<edges.size();j++){
			if(dist[edges[j].F.F]!=INT_MAX && dist[edges[j].F.S]>(dist[edges[j].F.F]+edges[j].S)){
				dist[edges[j].F.S] = dist[edges[j].F.F]+edges[j].S;
			}
		}
	}
	// for(int i = 1;i<=num_of_vertices;i++){
 //       if(i==start)continue;
 //       if(dist[i] != INT_MAX)
	// 	cout<<dist[i]<<" ";
 //       else cout<<(-1)<<" ";
	// }
	// cout<<endl;
	
}


int main() {
	int t;
	cin>>t;
	while(t--){
		edges.clear();
		cin>>num_of_vertices>>num_of_edges;
		for(int i = 0;i<num_of_edges;i++){
			int src,des,weight;
			cin>>src>>des>>weight;
			edges.PB(MP(MP(src,des),weight));
			edges.PB(MP(MP(des,src),weight));
		}
		int start;
		cin>>start;
		clock_t start_time = clock();
		bellman_ford(start);
		double time_taken = ((double)(clock() - start_time)/CLOCKS_PER_SEC)*1000;
		
		cout<<"time taken is "<<time_taken<<" for "<<num_of_vertices<<" nodes and "<<num_of_edges<<" edges and "<<num_of_edges*num_of_vertices<<" is product of vertices and edges."<<endl;
		
	}
	return 0;
}
