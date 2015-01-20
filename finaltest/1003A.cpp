#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int vis[10010];
vector<int> road[10010];
void dfs(int a)
{
	if(vis[a]) return;
	//cout<<"visited "<<a<<endl;
	vis[a] = 1;
	for(int i=0;i<road[a].size();i++)
	{
		int des = road[a][i];
		dfs(des);
	}
	return;
}
int main()
{
	freopen("1.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			road[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			road[a].push_back(b);
			road[b].push_back(a);
		}
		int ok = 1;
//		for(int i=1;i<=n;i++)
//		{
		//	if(!vis[i]){
		//		dfs(road[i][0]);
		//		ok++;
		//	} 
		//}
		dfs(road[1][0]);
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) {ok = 0;break;}	
		}
		if(ok==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
} 
