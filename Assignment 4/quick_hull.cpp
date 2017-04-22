#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct pnt{
	double x,y;
	pnt(double X=0, double Y=0) : x(X), y(Y){}
};

double area(pnt p1, pnt p2, pnt p3){
	p2.x -= p3.x;	p2.y -= p3.y;
	p1.x -= p3.x;	p1.y -= p3.y;
	return 0.5*(p1.x*p2.y-p1.y*p2.x);
}

bool compare(const pnt &a, const pnt &b, const pnt &c){
	return area(a,b,c)>0;
}

pnt leftMost(vector<pnt> &s){
	pnt left = s[0];
	for(int i=1; i<s.size(); i++){
		if(s[i].x>left.x)	continue;
		if(s[i].x==left.x&&s[i].y>left.y)	continue;
		left = s[i];
	}
	return left;
}

int lowerMost(vector<pnt> &s){
	int j=0;
	for(int i=1; i<s.size(); i++){
		if(s[i].y>s[j].y)	continue;
		if(s[i].y==s[j].y&&s[i].x>s[j].x)	continue;
		j=i;
	}
	return j;
}

vector<pnt> quick(pnt a, pnt b, vector<pnt> &s){
	if(s.size()<2)	return s;
	vector<pnt> p;
	int j=0;
	for(int i=1; i<s.size(); i++)	if(area(a,b,s[i])>area(a,b,s[j]))	j=i;
	pnt farthest = s[j];
	vector<pnt> t;
	for(int i=0; i<s.size(); i++)	if(area(farthest,b,s[i])>0)	t.push_back(s[i]);
	p = quick(farthest,b,t);
	p.push_back(farthest);
	t.clear();
	for(int i=0; i<s.size(); i++)	if(area(a,farthest,s[i])>0)	t.push_back(s[i]);
	vector<pnt> ans = quick(a,farthest,t);
	p.insert(p.end(),ans.begin(),ans.end());
	t.clear();
	return p;
}
vector<pnt> quickHull(vector<pnt> &s){
	int n = s.size();
	if(n<4)	return s;
	vector<pnt> p;
	int j = lowerMost(s);
	swap(s[j],s.back());
	p.push_back(s.back());
	s.pop_back();
	j=0;
	for(int i=1; i<s.size(); i++)	if(compare(p[0],s[i],s[j]))	j = i;
	swap(s[j],s.back());
	p.push_back(s.back());
	s.pop_back();
	vector<pnt> ans = quick(p[0],p[1],s);
	p.insert(p.end(),ans.begin(),ans.end());
	return p;
}
int main() {
	int n=0;
	cin>>n;
	vector<pnt> s;
	pnt temp;
	while(n--){
		cin>>temp.x>>temp.y;
		s.push_back(temp);
	}
	return 0;
}
