#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	string x;
	while(cin>>x && x[0]-'0'!=0)
	{
		int l=x.length(),i;
		int sum=0;
		for (i = 0; i < l; ++i)
		{
			int a=x[i]-'0';
			if(a<4) sum += int(a*pow(9,double(l-i-1)));
			else if(a>4 ) sum += int((a-1)*pow(9,double(l-i-1)));
			//else if(a>8) sum += (a-2)*pow(8,double(l-i-1));

		}
		cout<<x<<":"<<sum<<endl;
	}
	return 0;
}