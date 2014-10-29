#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int m;
		set<int>s;
		for (int i = 0; i < n; ++i)
		{
			cin>>m;
			if(s.count(m)) s.erase(m);
			else s.insert(m);

		}
		cout<<*s.begin()<<endl;
	}
	return 0;
}