#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];
void slove(string s1,string s2)
{
	for(int i=0;i<s1.length();i++)
	{
		for(int j=0;j<s2.length();j++)
		{
			if(s1[i]==s2[j]) 
			{
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	cout<<dp[s1.length()][s2.length()]<<endl;
}
int main()
{
	int n,m;
	string x,y;
	while(cin>>n>>m)
	{
		memset(dp,0,sizeof(dp));
		cin>>x>>y;
		slove(x,y);		
	}
	return 0;
}
