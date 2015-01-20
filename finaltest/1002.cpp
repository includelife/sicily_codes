#include <iostream>
#include <algorithm>
#include <set>
#include<vector>
using namespace std;
void slove(int n)
{
	vector<int> ans[1001];
	int k = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i*i+j*j==(n-i-j)*(n-i-j)){
				ans[k].push_back(i);
				ans[k].push_back(j);
				ans[k].push_back(n-i-j);
				sort(ans[k].begin(),ans[k].end());
				int ok = 1; 
				for(int l=0;l<k;l++)
				{
					if(ans[l][0]==ans[k][0]) {
						ok = 0;
						break;
					}	
				}
			    if(ok) cout<<ans[k][0]<<" "<<ans[k][1]<<" "<<ans[k][2]<<endl;
			    k++;
			}
}
int main()
{
	int t;
	cin>>t;
	int a[t];
	for(int i = 0;i < t; i++)
	{
		cin>>a[i];
		slove(a[i]);
		cout<<endl;
	}
	return 0;
}


