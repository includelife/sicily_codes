#include<iostream>
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
	cout<<nx<<endl;
	return nx;
}

int main(int argc, char const *argv[])
{
	string x = "12345678";
	string nx = reverse(x);
	cout<<nx<<endl;
	return 0;
}