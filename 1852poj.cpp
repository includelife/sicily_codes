#include<iostream>
using namespace std;
int main()
{
	int p[1000000];
	int i,c;
	cin>>c;
	for (i = 0; i < c; ++i)
	{
		int l,n,j;
		cin>>l>>n;
		//int p[c];
		for (j = 0; j < n; ++j)
		{
			cin>>p[j];
		}
		int mi=0,ma=0;
		for (j = 0; j < n; ++j)
		{
			mi=max(mi,min(p[j],l-p[j]));
		}
		for (j = 0; j < n; ++j)
		{
			ma=max(ma,max(p[j],l-p[j]));
		}
		cout<<mi<<" "<<ma<<endl;
	}
	return 0;
}
