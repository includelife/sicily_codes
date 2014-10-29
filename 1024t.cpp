//深度优先搜索求一颗树的最长路
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int _max;
int n,k,u,v,d;
struct Edge
{
	int u,v,d;
	Edge(int uu,int vv,int dd)
	{	u = uu;	v = vv;	d = dd;	}
};
vector<Edge> E[10010];
bool vis[10010];
void dfs(int u,int dis)
{
	if(dis > _max)	_max = dis;
	vis[u] = 1;
	for(int i = 0;i < E[u].size();++i)
	{
		int v = E[u][i].v;
		int d = E[u][i].d;
		if(vis[v])	continue;
		dfs(v,dis + d);
	}
	vis[u] = 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&k) != EOF)
	{
		_max = 0;
		memset(E,0,sizeof(E));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i < n;++i)
		{
			scanf("%d%d%d",&u,&v,&d);
			E[u].push_back(Edge(u,v,d));
			E[v].push_back(Edge(v,u,d));
		}
		dfs(k,0);
		printf("%d\n",_max);
	}
	return 0;
}