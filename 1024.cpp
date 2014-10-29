#include<cstdio>
#include<cstring>
int x[10001],y[10001],dis[10001],vis[10001];
int n,k,maxdis;
void dfs(int k,int distance)
{
	if(maxdis < distance) maxdis = distance;
	for (int i = 0; i < n-1; ++i){
		if(x[i] == k && vis[i] != 1){
			//x[i] = -1;
			vis[i] = 1;
			dfs(y[i],distance+dis[i]);
		}
		else if(y[i] == k && vis[i] != 1){
			//x[i] = -1;
			vis[i] = 1;
			dfs(x[i],distance+dis[i]);
		}

	}
}
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d %d", &n, &k) != EOF){
			memset(vis,-1,sizeof(vis));

		for (int i = 0; i < n-1; ++i){
			scanf("%d %d %d",&x[i],&y[i],&dis[i]); 
			//cin>>x[i]>>y[i]>>dis[i];
		}
		maxdis = 0;
		dfs(k,0);
		printf("%d\n",maxdis);
		//cout<<maxdis<<endl;
	}
	return 0;
}