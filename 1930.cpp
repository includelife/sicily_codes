#include<iostream>
#define LOCAL
using namespace std;
int main(int argc, char const *argv[])
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		int k,count = 0;
		for (int i = 0; i < n; ++i)
		{
			k = i;
			for (int j = i+1; j < n; ++j)
			{
				if(a[j] <= a[k]) {	k = j; count++;}
			}
			if(k!=i)
			{
				int temp = a[k];
				a[k] = a[i];
				a[i] = temp;

			}
		}
		cout<<count<<endl;
	}
	return 0;
}