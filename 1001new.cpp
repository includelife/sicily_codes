#include<iostream>
using namespace std;
int fun(string x,int l)
{
	if(l==1) return 1;
	if(l>=2)
	{
		int before=1,now=1,i;
		for (i = 1; i < l; ++i)
		{
			int a=(x[i-1]-'0')*10+x[i]-'0';
			if(x[i]-'0'!=0)
			{
					if(a<=26 && a>=1 )
					{
						int temp=before;
						before=now;
						now=now+temp;
					}
					else if(a>=26 || a>=1 ) {	before = now;}
					cout<<before<<"  "<<now<<endl;
			}
			else if(x[i]-'0'==0)
			{
				int b =(x[i-1]-'0')*10+x[i]-'0';
				if(x[i+1]-'0'==0 || b>26) return 0;
				if(b<=26 && b>=1) { now = before;i++;}
				cout<<before<<"  "<<now<<endl;
			}
		}
		return now;
	}
}
int main()
{
	string x;
	while( cin>>x && x[0]!='0')
	{
		cout<<fun(x,x.length())<<endl; 
	}
	return 0;
}