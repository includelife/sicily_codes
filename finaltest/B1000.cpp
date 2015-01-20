#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int origin[3][3]={1,2,3,4,5,6,7,8,0};
int goal[3][3]={0};
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
struct Node{
	int m[3][3];
};
Node start;
Node end;
queue<Node> qu[10];
int finished(Node node)
{
	int ok=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			{
				if(node.m[i][j]!=end.m[i][j]){ return 0;}
			}
	return ok;
}
void bfs()
{
	for(int level=0;level<=6;level++)
		{
			while(!qu[level].empty())
			{
				Node cu = qu[level].front();
				qu[level].pop();
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(cu.m[i][j]==0)
						{												
							for(int k=0;k<4;k++)
							{
								int dx = i+dirx[k];
								int dy = j+diry[k];	
								if(dx>=0 && dx<3 && dy>=0 && dy<3)
								{							
									Node next = cu;
									swap(next.m[i][j],next.m[dx][dy]);
									if(finished(next)) { cout<<level+1<<endl;return;}
									else qu[level+1].push(next);
								}
							}
						}	
					}
				}
			}		
		}
		return;	
}
int main()
{
	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	while(n--)
	{
		int k=1;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(k==9) start.m[i][j]=0;
				else start.m[i][j] = k;
				k++;
				cin>>end.m[i][j];	
			}
		qu[0].push(start);
		if(finished(start)) cout<<0<<endl;
		else bfs();
	}
	return 0;
}
