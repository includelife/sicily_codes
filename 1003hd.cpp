#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[100001],case_num;
int main(int argc, char const *argv[])
{
	freopen("1003hdin.txt","r",stdin);
	cin>>t;
	case_num=0;
	while(t--)
	{
		case_num++;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		int max=-10001,sum=0,temp=1;
		int beg=1,end=1;
		for (int i = 0; i < n; ++i)
		{
			// temp += a[i];
			// if(temp > max_sum) {	end = i+1;}
			// max_sum=max(max_sum,temp);
			if(sum>=0) {	sum += a[i];	}
			else {	sum=a[i],temp=i+1;	}
			if(sum>max) {	max=sum,beg=temp,end=i+1;	}
		}
		cout<<"Case "<<case_num<<":"<<endl;
		cout<<max<<" "<<beg<<" "<<end<<endl;
		if(t >0) cout<<endl;
	}
	return 0;
}