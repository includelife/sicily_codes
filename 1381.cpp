#include <stdio.h>
#include <string.h>
#define N 106
void multiply(char *a,char *b,char *c)
{
	if(a[0]=='0' || b[0]=='0')
	{
		c[0] = '0';
		c[1] = '\0';
		return;
	}
	int ca,cb;
	ca = strlen(a);
	cb = strlen(b);
	int s[ca+cb];
	memset(s,0,sizeof(s));
	for (int i = 0; i < ca; ++i)
	{
		for (int j = 0; j < cb; ++j)
		{
			s[i+j+1] += (a[i]-'0') * (b[j]-'0');
		}
	}
	for (int i = ca+cb-1; i >0 ; i--)
	{
		if(s[i]>9)
		{
			s[i-1] += s[i] / 10;
			s[i] %= 10;
		}
	}
	int i = 0,j;
	if(s[i] == 0) i++;
	for (j = 0; i < ca+cb; ++j,++i)
	{
		c[j] = s[i] + '0';
	}
	c[j] = '\0';
}
int main()
{
	int t;
	scanf("%d",&t);
	char a[N],b[N],c[2*N];
	while(t--)
	{
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		memset(c,'\0',sizeof(c));
		scanf("%s %s",a,b);
		multiply(a,b,c);
		printf("%s\n",c );
	}
	return 0;
}