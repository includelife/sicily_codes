#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
int n,mark=1;
double month[13];
double money[13];
double lastmonth,lastmoney;
int main()
{
	//freopen("1017in.txt","r",stdin);
	while(cin>>n && n!=-1)
	{
		for(int i=1;i<=n;i++){
			cin>>month[i]>>money[i];
		}
		cin>>lastmonth>>lastmoney;
		double upper,low,mid;
		upper=2;
		low=1;
		//当答案范围大于1e-6，继续二分查找 
		while(upper-low>1e-6)
		{
			double sum=0;
			mid=(upper+low)/2;
			for(int i=1;i<=n;i++){
				//pow函数的两个参数都是double型 
				sum+=money[i]*pow(mid,lastmonth-month[i]+1);
			}
			if(sum<lastmoney) low=mid;
			else	upper=mid;
		}
		if(mark>1) cout<<endl;
		//fixed，setprecision(n)设置小数点位数，最后结果四舍五入,如果没有fixed为整个数的位数 
		cout<<"Case "<<mark++<<": "<<fixed<<setprecision(5)<<mid-1<<endl;	
	}
	return 0;
}
