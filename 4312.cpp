#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>

using namespace std;

string reverse(string x)
{
	int l = 0;
	int r = x.length();
	char nx[r+1];
	for (int i = l; i < r; ++i)
	{
		nx[i] = x[r-i-1];
	}
	nx[r] = '\0';
	//cout<<nx<<endl;
	return nx;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		string x11,x21;
		cin>>x11>>x21;
		// reverse(x1.begin(),x1.end());
		// reverse(x2.begin(),x2.end());
		
		string x1 = reverse(x11);
		string x2 = reverse(x21);

		//cout<<x1<<endl;
		int l1=x1.length(),l2=x2.length();
		int a = 0,b = 0;

		for (int i = 0; i < l1; ++i)
		{
			int temp = x1[l1-1-i]-'0';
			a += temp*pow(10.0,i);
		}

		for (int i = 0; i < l2; ++i)
		{
			int temp = x2[l2-1-i]-'0';
			b += temp*pow(10.0,i);
		}
		// a = atoi(x1.c_str());
		// b = atoi(x2.c_str());
		cout<<a+b<<endl;
	}
	return 0;
}