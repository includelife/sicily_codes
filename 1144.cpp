#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[10],b,count=0;
	for (int i = 0; i < 10; ++i)
	{
		cin>>a[i];
	}
	cin>>b;
	for (int i = 0; i < 10; ++i)
	{
		if(b+30>=a[i]) count++;
	}
	cout<<count<<endl;
	return 0;
}