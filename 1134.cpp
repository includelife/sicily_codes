#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int n,s;		
struct Child
{
	int a,b;
};
bool comp(Child x,Child y)
{
	return x.b < y.b;
}
int main()
{
	freopen("1134input.txt","r",stdin);
	while(cin>>n && n!=0 )
	{	
		cin>>s;
		Child child;
		vector<Child> v;
		for (int i = 0; i < n; ++i)
		{
			cin>>child.a>>child.b;
			v.push_back(child); 
		}
		sort(v.begin(),v.end(),comp);
		int i;
		for (i = 0; i < n; ++i)
		{	

			if(s >= v[i].b)	
			{
				s += v[i].a;		
			}
			else break;
		}
		if(i == n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
