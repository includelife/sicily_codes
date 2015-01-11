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
		//���𰸷�Χ����1e-6���������ֲ��� 
		while(upper-low>1e-6)
		{
			double sum=0;
			mid=(upper+low)/2;
			for(int i=1;i<=n;i++){
				//pow������������������double�� 
				sum+=money[i]*pow(mid,lastmonth-month[i]+1);
			}
			if(sum<lastmoney) low=mid;
			else	upper=mid;
		}
		if(mark>1) cout<<endl;
		//fixed��setprecision(n)����С����λ�����������������,���û��fixedΪ��������λ�� 
		cout<<"Case "<<mark++<<": "<<fixed<<setprecision(5)<<mid-1<<endl;	
	}
	return 0;
}
