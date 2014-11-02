#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int maritx[31];
bool visited[31],dfsed[31];
int dirx[8]={1,2,2,1,-1,-2,-2,-1};
int diry[8]={-2,-1,1,2,2,1,-1,-2};
vector<int> st;
int flag;
void dfs(int x,int y,int cnt)
{
	if( cnt > 29) flag = 1;
	if(flag == 1) {
	while(!st.empty())
	 	{
	 		cout<<st.front()<<" ";
	 		st.erase(st.begin());
	 	}
	 	cout<<endl;
	 	return;
	}
	//  bool k = false;
	// for (int i = 1; i <= 30; ++i)
	// {
	// 	if(dfsed[i]) {k=true;}
	// }
	// if(!k) cout<<"-1"<<endl;
	//else
	{

		int n = x*6+y+1;
		for (int i = 0; i < 8; ++i)
		{
			int dx = x+dirx[i];
			int dy = y+diry[i];
			int sum = dx*6+dy+1;
			if(dx >= 0 && dx <= 4 && dy >= 0 && dy <= 5 && !visited[sum]) 
			{

				visited[sum] = true;
				st.push_back(sum);
				dfsed[sum] = true;
				dfs(dx,dy,cnt+1);
				if(st.empty()) return;
				st.pop_back();
				visited[sum] = false;
			}
		}
	}
}

int main()
{
	int n;
	for (int i = 1; i <= 31; ++i)
	{
		maritx[i] = i;
	}
	while(cin>>n && n!= -1){
		if(n>=1 && n<=30)
		{
			memset(visited,false,sizeof(visited));
			memset(dfsed,false,sizeof(dfsed));
			flag = 0;
			st.push_back(n);
			int i = (n-1)/6;
			int j = n-(i*6)-1;
			visited[n] = true;
			dfsed[n] = true;
			dfs(i,j,1);
		}
	}
	return 0;
}
