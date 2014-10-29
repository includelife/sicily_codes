#include<iostream>
#include<cstring>
using namespace std;
int dp[500];
int fun(string s,int l)
{
	if(dp[l]!=0) return dp[l];
	if(l<=1) return 1;
	if(l>=2)
	{
		
		if((s[l-1]-'0')!=0)
		{
			int a=(s[l-2]-'0')*10+(s[l-1]-'0');
			cout<<"a is "<<a<<endl;
			if(a>=1 && a<=26 && s[l-2]-'0'!=0) return dp[l]=(fun(s,l-1)+fun(s,l-2));
			else return dp[l]=fun(s,l-1);
		}
		if((s[l-1]-'0')==0)
		{
			 int a=(s[l-2]-'0')*10+(s[l-1]-'0');
			 cout<<"a is "<<a<<endl;
			 if(a>=1 && a<=26) return dp[l]=fun(s,l-2);
			 else if(a>26||a<1) return dp[l]=0;
		}
	}
}
int main()
{
	string x;
	cin>>x;
	while( x[0]!='0')
	{
		memset(dp,0,sizeof(dp));
		cout<<fun(x,x.length())<<endl; 
		cin>>x;
	}
	return 0;
}