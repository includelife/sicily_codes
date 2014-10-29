#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	string kw;
	while(cin>>kw && kw!="THEEND")
	{
		int lk = kw.length();
		string text;
		cin>>text;
		int lt = text.length();
		int n = lt/lk;
		string yt[lk],rt[lk];

		int i,j,k;
		for (i = 0; i < lk; ++i)
		{
			yt[i] = text.substr(i*n,n);
		}
		
		string skw = kw;
		sort(skw.begin(),skw.end());

		int count[lk];
		k=0;
		for (i = 0; i < lk; ++i)
		{
			for (j = 0; j < lk; ++j)
			{
				while(skw[i]==skw[i+1])
				{
					i++;
				}

				if(skw[i]==kw[j]) 
					{	
						count[k]=j;
						k++;
					} 
			}
		}

		for (i = 0; i < lk; ++i)
		{
			rt[count[i]] = yt[i];
		}

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < lk; ++j)
			{
				cout<<rt[j][i];
			}
		}
		cout<<endl;
	}
	return 0;
}