#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x[3];
		cin>>x[0]>>x[1]>>x[2];
		if((x[0]+x[1]>x[2])&&(x[0]+x[2]>x[1])&&(x[1]+x[2]>x[0])) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}