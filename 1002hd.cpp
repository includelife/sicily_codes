#include <cstdio>
#include <cstring>
#define N 100000
//using namespace std;
char a[N],b[N],c[N+1];
int s1[N+1],s2[N+1];
void plus(char *a,char *b,char*c)
{
	if(a[0]=='0' && b[0]=='0')
	{
		c[0]='0';
		c[1]='\0';
		return;
	}
	if(a[0]-'0'==0 || b[0]-'0'==0)
	{
		c[0]='0';
		c[1]='\0';
	}
	int ca,cb,cc;
	ca=strlen(a);
	cb=strlen(b);
	if(ca>=cb)
	{
		memset(s1,0,sizeof(s1));
		for(int i=ca;i>0;i--)
		{
			if(i-1>=ca-cb)	s1[i]=(a[i-1]-'0')+(b[i-1-(ca-cb)]-'0');
			else if(i-1>=0) 	
				{
					s1[i]=a[i-1]-'0';
				}
		}
		s1[0] = 0;
		for(int i=ca;i>=1;i--)
		{
			if(s1[i]>9)
			{
				s1[i-1] += s1[i]/10;
				s1[i] %= 10;
			}
		}
		int i=0,j;
		if(s1[i]==0) i++;
		for(j=0;i<ca+1;i++,j++)
		{
			c[j]=s1[i]+'0';
		}
		c[j]='\0';
	}else if(ca<cb)
	{
		memset(s2,0,sizeof(s2));
		for(int i=cb;i>0;i--)
		{
			if(i-1>=cb-ca)	s2[i]=(a[i-1-(cb-ca)]-'0')+(b[i-1]-'0');
			else if(i-1>=0)	s2[i]=b[i-1]-'0';
		}
		s2[0]=0;
		for(int i=cb;i>=1;i--)
		{
			if(s2[i]>9)
			{
				s2[i-1] += s2[i]/10;
				s2[i] %= 10;
			}
		}
		int i=0,j;
		if(s2[i]==0) i++;
		for(j=0;i<cb+1;i++,j++)
		{
			c[j]=s2[i]+'0';
		}
		c[j]='\0';
	}
}
	
int main()
{
	int t;
	scanf("%d",&t);
	for(int case_n = 1;case_n<=t;case_n++)
	{
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		memset(c,'\0',sizeof(c));
		scanf("%s %s",a,b);
		plus(a,b,c);
		printf("Case %d:\n",case_n);
		printf("%s + %s = %s",a,b,c);
		if(case_n!=t)	printf("\n\n");
		else printf("\n");	

	}
	return 0;
}

