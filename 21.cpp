#include<iostream>
#include<cstring>
using namespace std;
int main()
{	
	char ch;
	int array[26];
	memset(array,0,sizeof(array));
	//cin>>ch;
	while(cin>>ch)
	{
		if(ch =='?') break;
		if(ch >= 'a' && ch <= 'z')
		{
			for (char i = 'a'; i <= 'z'; ++i)
			{
				if(ch == i) array[i-'a']++;
			}
		}
		//cin>>ch;
	}

	for (char i = 'a'; i <= 'z'; ++i)
	{
		cout<<i<<" number is "<<array[i-'a']<<endl;
	}
	return 0;
}