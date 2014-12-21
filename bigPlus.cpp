#include <stdio.h>
#include <string.h>
#define N 1000
char a1[N],b1[N],c1[N+1];
void plus(char *a,char *b,char *c)
{
	int ca,cb,i,p=0;
	ca=strlen(a)-1;
	cb=strlen(b)-1;
	for (i = 0; ca>=0 || cb>=0; i++,ca--,cb--)
	{
		if(ca>=0 && cb>=0) 	c[i]=a[ca]+b[cb]-'0'+p;
		else if(ca>=0 && cb<0)	c[i]=a[ca]+p;
		else if(ca<0 && cb>=0)	c[i]=b[cb]+p;
		p=0;
		if(c[i]>'9') 	{	c[i]=c[i]-10;p=1;}
	}
	if(p==1) 
	{
		c[i]='1';
		i++;
	} 
	// while(i--)
	// {
	// 	printf("%c",c[i]);
	// }
	// printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",a1,b1);
		plus(a1,b1,c1);
		int cc=strlen(c1);
		for (int i = cc-1; i >= 0; i--)
		{
			printf("%c",c1[i]);
		}
		printf("\n");
	}
	return 0;
}