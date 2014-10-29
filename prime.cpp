#include<iostream>
#include<vector>
#include<map>
using namespace std;
//假设输入都是正数
//素性测试
bool is_prime(int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if(n % i == 0) return false;
	}
	return n != 1;
}
//约束枚举O(根号n)
vector<int> divisor(int n)
{
	vector<int> res;
	for (int i = 2; i*i <= n; ++i)    //floor(sqrt(n)+0.5);
	{
		if(n % i == 0)
		{
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
	return res;
}
//整数分解O(根号n)
map<int,int> prinme_factor(int n)
{
	map<int,int> res;
	for (int i = 2; i*i <= n; ++i)
	{
		while(n % i == 0)
		{
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res; 
}

int main()
{
	map<int, int> mymap;
	mymap = prinme_factor(8);
	map<int, int>::iterator ite;
	int i = 1;
	for (ite = mymap.begin(); ite != mymap.end(); ++ite)
	{
		printf("%d %d\n",ite->first,ite->second);
	}
	return 0;
}