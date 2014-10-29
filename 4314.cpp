#include<iostream>
using namespace std;
int gcd(int x,int y)
{
 int t;
 while (y) t=x, x=y, y=t%y;
 return x;
}
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x[2],max,min;
		cin>>x[0]>>x[1];
		if(gcd(x[0],x[1])==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}