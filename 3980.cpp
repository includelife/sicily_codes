#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,i;
	cin>>t;
	for (i = 0; i < t; ++i)
	{
		string x;
		cin>>x;
		int j,sum=0,l=x.length();
		for (j = 0; j < l; ++j)
		{
			int a=x[j]-'0';
			sum=sum+int(pow(2,double(l-j-1))*a);
		}
		cout<<sum<<endl;
	}
	return 0;
}