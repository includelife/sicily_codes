#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		int n,i,j,k;
		cin>>n;
		string x[n];
		//输入
		for (i = 0; i < n; ++i)
		{
			cin>>x[i];
		}
		//简单选择排序
		string temp;
		for (i = 0; i < n-1; ++i)
		{
			k=i;
			for (j = i+1; j < n; ++j)
			{
				if(x[k]+x[j]<x[j]+x[k]) { k=j;}
			}
			if(k!=i) {	temp=x[k];x[k]=x[i];x[i]=temp;}
		}

		// for (i = 0; i < n-1; ++i)
		// {
		// 	for (j = 0; j < n-1-i; ++j)
		// 	{
		// 		if(x[j]+x[j+1]>x[j]+x[j+1])
		// 		{
		// 			temp=x[j];
		// 			x[j]=x[j+1];
		// 			x[j+1]=temp;
		// 		}
		// 	}
		// }
		//输出
		for (i = 0; i < n; ++i)
		{
			cout<<x[i];
		}
		cout<<endl;
	}
	return 0;
}