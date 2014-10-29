#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		int a=n*n-1;
		if(a%2==0) cout<<"BOb"<<endl;
		else cout<<"Alice"<<endl;
	}
	return 0;
}