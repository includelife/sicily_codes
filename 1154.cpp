#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int s[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>s[i];
		}
		sort(s,s+n);
		for (int i = 0; i < n; ++i)
		{
			cout<<s[i]<<endl;
		}
	}
	return 0;
}