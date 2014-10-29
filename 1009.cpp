#include<iostream>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;

bool is_prime(ll n)
{
	for (ll i = 2; i*i <= n; ++i)
	{
		if(n % i == 0) return false;
	}
	return n != 1;
}

map<ll,int> prime_factor(ll n)
{
	map<ll,int> res;
	for (ll i = 2; i*i <= n; ++i)
	{
		while(n % i == 0)
		{
			res[i]++;
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

int main()
{
	int t;
	cin>>t;
	for (int i = 1; i < t; ++i)
	{
		if(is_prime(i))
		{
			ll s = (ll)pow(2.0,i)-1;
			if(!is_prime(s))
			{
				map<ll,int> mymap = prime_factor(s);
				map<ll,int>::iterator ite;
				int j = 0;
				for (ite = mymap.begin(); ite != mymap.end(); ++ite)
				{
					cout<<ite->first;
					if(j < mymap.size() - 1) cout<<" * ";
					j++;
				}
				cout<<" = "<<s<<" = ( 2 ^ "<<i<<" ) - 1";
				cout<<endl;
			}
		}
	}
	return 0;
}