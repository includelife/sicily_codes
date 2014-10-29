#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int vis[10001];
vector<int> x[10001];
vector<int> dis[10001];
int n,k,maxdis;
void dfs(int k,int distance)
{
	vis[k]=1;
	if(maxdis < distance) maxdis = distance;
	for (int i = 0; i < x[k].size(); ++i){
		if(vis[x[k][i]]!=1)
			dfs(x[k][i],distance+dis[k][i]);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d %d", &n, &k) != EOF){
		
		for(int i=1;i<=n;i++)
		{
			x[i].clear();
			dis[i].clear();
		}
		
			memset(vis,-1,sizeof(vis));
		
		for (int i = 0; i < n-1; ++i){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			x[a].push_back(b);
			x[b].push_back(a);
			
			dis[a].push_back(c);
			dis[b].push_back(c);
			//cin>>x[i]>>y[i]>>dis[i];
		}
		maxdis = 0;
		dfs(k,0);
		printf("%d\n",maxdis);
		//cout<<maxdis<<endl;
	}
	return 0;
}
