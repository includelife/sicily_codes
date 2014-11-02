#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int maritx[65];
bool visited[65];
int dirx[8]={1,2,2,1,-1,-2,-2,-1};
int diry[8]={-2,-1,1,2,2,1,-1,-2};
vector<int> st;
int flag;
void dfs(int x,int y,int cnt)
{
	if( cnt > 63) flag = 1;
	if(flag == 1) {
	while(!st.empty())
	 	{
	 		cout<<st.front()<<" ";
	 		st.erase(st.begin());
	 	}
	 	cout<<endl;
	 	return;
	}

	int n = x*8+y+1;
	for (int i = 0; i < 8; ++i)
	{
		int dx = x+dirx[i];
		int dy = y+diry[i];
		int sum = dx*8+dy+1;
		if(dx >= 0 && dx <= 7 && dy >= 0 && dy <= 7 && !visited[sum]) 
		{
			visited[sum] = true;
			st.push_back(sum);
			dfs(dx,dy,cnt+1);
			if(st.empty()) return;
			st.pop_back();
			visited[sum] = false;
		}
	}
}

int main()
{
	int n;
	for (int i = 1; i <= 64; ++i)
	{
		maritx[i] = i;
	}
	while(cin>>n && n!= -1){
		if(n>=1 && n<=64)
		{
			memset(visited,false,sizeof(visited));
			flag = 0;
			st.push_back(n);
			int i = (n-1)/8;
			int j = n-(i*8)-1;
			visited[n] = true;
			dfs(i,j,1);
		}
	}
	return 0;
}
