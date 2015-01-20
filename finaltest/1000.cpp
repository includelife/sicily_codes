#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> ss;
set<string>::iterator iter;
void dfs(string s, int index, int length)
{
	if(index == length) // ½áÊøÌõ¼ş
	{
		if(ss.end() == ss.find(s))
			ss.insert(s);
	}
	else
	{
		if(s[index] == '?')
		{
		//cout<<"trun 0"<<endl;
		s[index] = '0';
		dfs(s,index+1,length);

		//cout<<"trun 1"<<endl;	
		s[index] = '1';
		dfs(s,index+1,length);

		}
		else
		{
			//	cout<<"Not ?"<<endl;
			dfs(s,index+1,length);
		}
	}
}
int main()
{
	int m,n;
	while(cin >> m >> n && !(m==0 && n == 0))
	{
		string s[3000];
		for(int i = 0; i < n; i++)
		{
			cin >> s[i];
		}	
		for(int i =0; i < n; i++)
		dfs(s[i], 0, m);
		cout<<ss.size()<<endl;
		ss.clear();
	}
	return 0;
}
