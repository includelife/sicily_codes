#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[1000];
		int ans=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
		{
			//int key = a[i];
			for(int j=i+1;j<n;j++)
			{
				if(a[i]>a[j]) ans++;	
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
