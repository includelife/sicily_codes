#include<iostream>
using namespace std;
int n,m;
char field[100][101];
void dfs(int x,int y)
{
	field[x][y]='.';
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			int nx,ny;
			nx=x+i;
			ny=y+j;
			if(0<=nx && nx<n && 0<=ny && ny<m && field[nx][ny]=='W') 
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}

int main()
{
	int i,j;
	cin>>n>>m;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			cin>>field[i][j];
		}
	}

	int res = 0;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if(field[i][j]=='W') 
				{
					dfs(i,j);
					res++;
				}
		}
	}
	cout<<res<<endl;
	return 0;
}