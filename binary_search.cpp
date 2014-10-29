#include<iostream>
using namespace std;
int k[10];

bool binary_search(int x)
{
	int l=0,r=10;
	while(r-l>=1)
	{
		int m=(r+l)/2;
		if(k[m]==x) return true;
		else if(k[m]<x) l=m+1;
		else r=m;
	}
	return false;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		cin>>k[i];
	}
	int x;
	cin>>x;
	bool a = binary_search(x);
	if(a) puts("yes");
	else puts("no");
	return 0;
}