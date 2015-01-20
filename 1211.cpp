#include <iostream>
#include <cstdio>
#include <cstring>
//using namespace std;
int n,m,l,q;
int road[110][110]={0};//邻接矩阵，road[x][y]表示x到y是否联通。（其他题目里也可以表示路径总数）
int res[110][110]={0}; //结果，res[k][b]表示第k天到达b的路径数目
int A,B;
void slove()
{

	res[0][A]=1;//从A出发，第0天到达A的路线总数为1
	for (int k = 1; k <= l; ++k)  //从第一天开始算，第0天只能是在A
		for (int a = 1; a<=n; ++a) //遍历整个邻接矩阵
			for (int b = 1; b <=n; ++b)
				if(road[a][b]！=0)
				{
					//如果a到b联通，则第k天到达b的路径数目等于k-1天到达a的路径数目加上本来已经有的路径数目
					//其他题目或许可以写成，res[k][b] += res[k-1][a]+road[a][b];
					res[k][b] += res[k-1][a]; 
				}	
	printf("%d\n",res[l][B]);
}
int main()
{
	freopen("1211input.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&l);
	//cin>>n>>m>>l;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		// cin>>a>>b;
		road[a][b]++;
	}
	scanf("%d",&q);
	// cin>>q;
	while(q--)
	{
		scanf("%d %d",&A,&B);
		// cin>>A>>B;
		slove();
		memset(res,0,sizeof(res));
	}
	return 0;
}
