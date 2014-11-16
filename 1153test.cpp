//经典的深度优先搜索，必须剪枝才能通过，而且剪枝策略十分神奇，先走下一步可行拓展数最少的，看了大牛的题解才会的
//也就是说假如当前结点有8个可以走的拓展点，对每个可行拓展点再计算它的可行拓展数，然后排序，先走那个可行拓展数最小的
//就是先走那个最没前途的点，这样会更快，因为它这么没前途，要从其它点到达它就更难了，所以先走
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int dir[8][2] = {-1,-2,-1,2,-2,1,-2,-1,1,2,1,-2,2,1,2,-1};
bool vis[64];
int ans[64];
bool legal(int x,int y)
{
	if(x < 0 || x > 7 || y < 0 || y > 7)	return false;
	return true;
}
int cal_ok(int x,int y)//计算当前结点的可行可拓展数
{
	int cnt = 0;
	for(int i = 0;i < 8;++i)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];
		if(legal(X,Y) && !vis[X+Y*8])
			++cnt;
	}
	return cnt;
}
struct coord
{
	int x,y;
	int cnt;
	coord(int X,int Y)
	{	x = X;	y = Y;	cnt = cal_ok(X,Y);	}//cnt记录可行拓展数
};
bool cmp(coord a,coord b)
{
	return a.cnt < b.cnt;
}
bool dfs(int x,int y,int cur)//将DFS函数定义为BOOL型，一旦递归成功搜索到解，那么直接通过if函数一层层return回来
{
	vector<coord> v;
	vis[y*8+x] = 1;
	ans[cur] = y*8 + x + 1;
	if(cur == 63)	return true;
	for(int i = 0;i < 8;++i)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];
		if(legal(X,Y) && !vis[X+Y*8])
			v.push_back(coord(X,Y));//构造函数中带有计算可行拓展数
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < v.size();++i)
	{
		if(dfs(v[i].x,v[i].y,cur + 1))
			return true;//拓展成功，跳出当前层
	}
	vis[y*8+x] = 0;
	return false;//当前结点拓展失败
}
int main()
{
	int n;
	while(scanf("%d",&n) && n != -1)
	{
		memset(vis,0,sizeof(vis));
		dfs((n-1) % 8,(n-1)/8,0);
		printf("%d",ans[0]);
		for(int i = 1;i < 64;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}