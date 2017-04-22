#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct pnt{
    int x, y;
};
pnt p0;
pnt secondtop(stack<pnt> &S){
    pnt p = S.top();
    S.pop();
    pnt res = S.top();
    S.push(p);
    return res;
}
 
int swap(pnt &p1, pnt &p2){
    pnt temp = p1;
    p1 = p2;
    p2 = temp;
}

int SquareDistance(pnt p1, pnt p2){
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
int angle(pnt p, pnt q, pnt r){
    int sl = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y); 
    if (sl == 0) return 0;  
    return (sl > 0)? 1: 2; 
} 

bool comp(const pnt& p1, const pnt& p2){
   int o = angle(p0, p1, p2);
   if (o == 0)
     return (SquareDistance(p0, p2) >=  SquareDistance(p0, p1));
   return (o == 2);
}
 

void convexHull(pnt pnts[], int n){
   int ymin = pnts[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = pnts[i].y;
 
     if ((y < ymin) || (ymin == y &&
         pnts[i].x < pnts[min].x))
        ymin = pnts[i].y, min = i;
   }
 
   swap(pnts[0], pnts[min]);

   p0 = pnts[0];
   sort(pnts+1, pnts + n,  comp);
 
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++){
       while (i < n-1 && angle(p0, pnts[i],
                                    pnts[i+1]) == 0)
          i++;
 
 
       pnts[m] = pnts[i];
       m++; 
   }
 
   if (m < 3) return;
 
   stack<pnt> S;
   S.push(pnts[0]);
   S.push(pnts[1]);
   S.push(pnts[2]);
   for (int i = 3; i < m; i++){
      while (angle(secondtop(S), S.top(), pnts[i]) != 2)
         S.pop();
      S.push(pnts[i]);
   }
 
   
   while (!S.empty())
   {
       pnt p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 

int main(){
	int n;
	cin>>n;
	
    pnt pnts[n];
    
    for(int i=0; i<n; i++){
    	int x, y;
    	cin>>x>>y;
    	pnts[i] = {x,y};
    }
    convexHull(pnts, n);
    return 0;
}
