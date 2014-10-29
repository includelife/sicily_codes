#include<stdio.h>
#include<stack>
int res[5],target;

int dfs(int x, int target)
{
	for (int i = 0; i < 5; ++i)
	{
		
	}
}

int main(int argc, char const *argv[])
{
	int n,i,j;
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		int a[5],target;
		scanf("%d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&target);
		for ( j = 0; j < 5; ++j)
		{	
			res[j] = dfs(a[j],target);
		}

	}
	return 0;
}