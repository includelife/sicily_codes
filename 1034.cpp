/*
有根树，边得方向已经确定
判断是否为森林：入度为0的点都做dfs,为每个点计算深度，判断最后是否所有点都被访问到
*/
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<int> E[101]; //图的邻接表
bool vis[101],ok; 
int n,m,D,W,width[101],in[101]; //width存储森林的宽度,in存储入度
void dfs(int u,int d)
{
	if(vis[u]) { ok=false;return; } //如果访问过u节点,则说明存在环,返回
	vis[u]=true;	//标记为访问过

	if(d>D) D=d;   //记录深度

	width[d]++;    //宽度加1
	if(width[d]>W) W=width[d];	//记录深度为d的宽度
	for (int i = 0; i < E[u].size(); ++i)
	{
		if(!ok) return;  //多余的判断
		int v=E[u][i];
		dfs(v,d+1);
	}
}
int main()
{
	freopen("1034input.txt","r",stdin);
	while(scanf("%d %d",&n,&m) && n)
	{
		ok=true;
		D=W=0;
		memset(vis,false,sizeof(vis));
		memset(E,0,sizeof(E));
		memset(in,0,sizeof(in));
		memset(width,0,sizeof(width));
		if(m>=n) ok=false;	//边大于等顶点数，肯定存在环（存在入口）
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			E[a].push_back(b);
			in[b]++;    //入度加1
		}
		for (int i = 1; i <= n; ++i)   //如果入度为0，则对该点进行dfs
		{
			if(in[i]==0)
			{
				dfs(i,0);
			}
		}
		for (int i = 1; i <= n; ++i)	//如果搜索完还有点未遍历过，证明存在环（闭合环，不存在入口）
		{
			if(!vis[i]) ok=false;
		}
		if(!ok) printf("INVALID\n");
		else printf("%d %d\n",D,W);
	}
	return 0;
}
