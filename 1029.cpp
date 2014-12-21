#include <iostream>
#include <cstring>
using namespace std;
string a[101];
string add(string str1,string str2)  //大数相加
{
	int l1=str1.length();
	int l2=str2.length();
	while(str1.length() < str2.length())
	{
		str1="0"+str1;
	}
	while(str2.length() < str1.length())
	{
		str2="0"+str2;
	}
	str1="0"+str1;  //将两个数的位数对齐，前面再加一个0,因为加法最多只可能进一位
	str2="0"+str2;
	for (int i = str1.length()-1; i >0 ; i--)
	{
		str1[i] += str2[i]-'0';
		if(str1[i]>'9')
		{
			str1[i] -= 10;
			str1[i-1] ++;
		} 
	}
	if(str1[0]=='0')
	{
		str1 = str1.substr(1,str1.length()-1);
	}
	return str1;

}
// 递推公式 a[i]=a[i-1]+a[i-m]
string cal(int m,int d)
{
	int i;
	for (i = 1; i <=d; ++i)
	{
		if(i<m)
		{
			a[i] = add(a[i-1],"1"); //注意一开始的兔子是成年的，每个月可以加1
		}else{
			a[i] = add(a[i-1],a[i-m]);
		}
	}
	return a[i-1];
}

int main()
{
	int m,d;
	a[0]="1"; //初始值 
	while(cin>>m>>d && m!=0 && d!=0)
	{
		string ans = cal(m,d);
		//string ans = add("1234567","12356");
		cout<<ans<<endl;
	}
	return 0;
}
