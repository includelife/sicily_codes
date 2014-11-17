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
	return x.b > y.b;
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
		for (int i = n-1; i >= 0; i--)
		{	
			//cout<<v[i].b<<endl;
			if(s >= v[i].b)	
			{
				s += v[i].a;
				//cout<<s<<" "<<v.begin()->a<<" "<<v.begin()->b<<endl;
				v.pop_back();   //用v.erase(v.begin())删除第一个元素，会越界，因为删除了元素，数组下标会前移
			}
		}
		if(v.size() == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
