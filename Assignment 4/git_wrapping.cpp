#include <bits/stdc++.h>
using namespace std;
 
#define INF 100005
 
struct Point{
        int x;
        int y;
};
 
int fo(Point p, Point q, Point r){
    int sl = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (sl == 0)
        return 0; 
    return (sl > 0) ? 1 : 2;
}
 
void convexHull(Point points[], int n){
    if (n < 3)
        return;
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1; 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do{      
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (fo(points[p], points[i], points[q]) == 2)
                q = i; 
        next[p] = q; // Add q to result as a next point of p
        p = q; 
    }
    while (p != l); 	
 	int cnt = 0;   
    for (int i = 0; i < n; i++){
        if (next[i] != -1){
        	cnt++;
        	cout << "(" << points[i].x << ", " << points[i].y << ")\n";
        }
    }    
    cout<<cnt<<endl;
}
 

int main(){
    int n;
	cin>>n;
	
	Point points[n];
	
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		points[i] = {x, y};
	}
    convexHull(points, n);    
    return 0;
}
