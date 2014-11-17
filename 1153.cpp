#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int ans[64];
bool visited[64];
int dirx[8]={1,2,2,1,-1,-2,-2,-1};
int diry[8]={-2,-1,1,2,2,1,-1,-2};
int cal(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		int dx = x + dirx[i];
		int dy = y + diry[i];  
		int next = dx*8+dy+1;
		if(dx>=0 && dx<8 && dy>=0 && dy<8 && !visited[next-1]) 	cnt++;
	}
	return cnt;
}
struct coord
{
	int x,y;
	int cnt;
	coord(int X,int Y)
	{
		x = X;
		y = Y;
		cnt = cal(x,y); 
	}
};
bool comp(coord a,coord b)
{
	return a.cnt < b.cnt;
}
bool dfs(int n,int dis)
{
	visited[n-1] = true;
	ans[dis] = n;
	if(dis >= 63) return true;
	int i = (n-1)/8;
	int j = (n-1)%8;
	vector<coord> v;
	for (int k = 0; k < 8; ++k)
	{
		int dx = i + dirx[k];
		int dy = j + diry[k];
		int next = dx*8+dy+1;
		if(dx>=0 && dx<8 && dy>=0 && dy<8 && !visited[next-1])
		{	
			v.push_back(coord(dx,dy));
		}
	}	
	sort(v.begin(),v.end(),comp);
	for (int k = 0; k < v.size(); ++k)
	{
		int next = v[k].x*8+v[k].y+1;
		if(dfs(next,dis+1)) return true;
	}
	visited[n-1] = false;
	return false;
}

int main()
{
	int n;
	while(cin>>n && n != -1)
	{
		if(n >= 1 && n <= 64)
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
