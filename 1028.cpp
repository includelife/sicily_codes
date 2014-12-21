#include <iostream>
#include <cstring>
using namespace std;
int cal(string s)
{
	int l =s.length();
	int ans = 1;
	while((s[l-1]-'0')%2==0)
	{
		ans++;
		int remain = 0;
		for (int i = 0; i < l; ++i)
		{
			remain = remain*10+s[i]-'0';
			s[i] = remain/2+'0';
			remain %= 2;
		}
	}
	return ans;	
}
int main()
{
	int t;
	cin>>t;
	int case_num = 1;
	while(t--)
	{		
		string p;
		cin>>p;
		int cnt = cal(p);
		cout<<"Case "<<case_num++<<": "<<cnt<<endl;
		if (t!=0)
		{
			cout<<endl;
		}
	}
	return 0;
}
