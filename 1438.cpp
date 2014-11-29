#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a,int b)
{
	return a > b;
}
int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin>>n;
		int pi[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>pi[j];
		}
		sort(pi,pi+n,comp);
		int cnt = 0;
		int max=0;
		for (int j = 0; j < n; ++j)
		{
			cnt++;
			if(cnt%3==0)  max += pi[j];
		}
		cout<<max<<endl;
	}
	return 0;
}