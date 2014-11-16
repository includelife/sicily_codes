#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dirx[8]={1,2,2,1,-1,-2,-2,-1};  //每一步横坐标的变化量
int diry[8]={-2,-1,1,2,2,1,-1,-2};  //每一步的纵坐标变化量
int ans[64]; //记录路径
bool visited[64]; //标记是否被搜索
int cal(int x, int y)  //返回x节点下一步可行的节点数
{
	int cnt  = 0;
	for (int i = 0; i < 8; ++i)
	{
		int dx = x + dirx[i];
		int dy = y + diry[i];
		int next = dx*8+dy+1;
		if(dx >= 0 && dx < 8 && dy >= 0 && dy < 8 && !visited[next-1])	cnt++;
	}
	return cnt;
}
struct coord  //节点结构体
{
	int x,y; //横纵坐标
	int cnt; //可行子节点数
	coord(int X,int Y)  //节点构造方法
	{
		x = X;
		y = Y;
		cnt = cal(x,y);
	}
};
bool comp(coord a, coord b)  //排序的比较方法
{
	return a.cnt < b.cnt;  
}
bool dfs(int n,int dis)  //深度优先搜索
{
	visited[n-1] = true;  //打开访问标记
	ans[dis] = n; //记录当前路径
	if(dis >= 63) return true;  //如果搜索到第64个节点
	int i = (n-1)/8;  //横坐标
	int j = (n-1)%8;  //纵坐标
	vector<coord> v;  //存储可行节点 
	for (int k = 0; k < 8; ++k)
	{
		int dx = i + dirx[k];
		int dy = j + diry[k];
		int next = dx*8+dy+1;
		if(dx >= 0 && dx < 8 && dy >= 0 && dy < 8 && !visited[next-1])
		{
			v.push_back(coord(dx,dy));   //如果(dx,dy)可行，则加入v,同时构造方法自动计算了(dx,dy)的下一步可行节点数
		}	
	}
	sort(v.begin(),v.end(),comp);  //排序
	for (int k = 0; k < v.size(); ++k)  //先搜索可行节点数少的节点，大大提高效率
	{
		int next = v[k].x*8+v[k].y+1;      
		if(dfs(next,dis+1)) return true;   //如果搜索成功，返回true
	}
	visited[n-1] = false;  //关闭访问标记
	return false;  //前面都没有返回true,n节点搜索失败
}
int main()
{
	int n;
	while(cin>>n && n!=-1)
	{
		if(n>=1 && n<=64)
		{
			memset(visited,false,sizeof(visited));			
			dfs(n,0);
			for (int i = 0; i < 63; ++i)
			{
				cout<<ans[i]<<" ";
			}
			cout<<ans[63]<<endl;
		}
	}
	return 0;
}
