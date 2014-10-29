#include<iostream>
#include<stack>
using namespace std;
int couples[200002];
int main()
{
	int n,i;
	while(cin>>n && n!=0)
	{
		stack<int> mystack;
		for (i = 0; i < n; ++i)
		{
			int a,b;
			cin>>a>>b;
			couples[a]=b;
			couples[b]=a;
		}
		for (i = 1; i <= 2*n; ++i)
		{
			if(!mystack.empty() && mystack.top()==couples[i])	mystack.pop();
			else mystack.push(i);
		}
		if(mystack.empty()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}