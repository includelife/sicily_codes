#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
string origin;
int output;
int fun(string s)
{
	int l=s.length();
	for (int i = l-1; i >= 0; i--)
	{
		int tmp=0;
		if(s[i]-'0'>4) tmp=s[i]-'0'-1;
		else if(s[i]-'0'<4) tmp=s[i]-'0';
		output += tmp*int(pow(9.0,l-i-1));
	}
	return output;
}

int main()
{
	while(cin>>origin && origin!="0"){
		output=0;
		output=fun(origin);
		cout<<origin<<": "<<output<<endl;	
	}
	return 0;
}