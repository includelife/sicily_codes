#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n!=0)
	{
		int i,j,k;
		string temp_voter;
		string candidates[120];
		int bestCandidatesId;
		int distance[120];

		memset(distance,0,sizeof(distance));
		bestCandidatesId = 0;
		temp_voter="ABCDE";

		candidates[0] = temp_voter;
		for (int i = 1; next_permutation(temp_voter.begin(),temp_voter.end()); i++)
		{
			candidates[i] = temp_voter;
		}

		while(n--)
		{
			cin>>temp_voter;
			for (i = 0; i < 120; ++i)
				{
					for (j = 0; j < 4; ++j)
					{
						for (k = j+1; k < 5; ++k)
						{
							if(temp_voter.find(candidates[i][j]) > temp_voter.find(candidates[i][k])) distance[i]++;
						}
					}
				}
		}

		//cout<<distance[0]<<endl;
		for (i = 0; i < 120; ++i)
		{
			if(distance[i] < distance[bestCandidatesId]) bestCandidatesId = i;
		}
		cout<<candidates[bestCandidatesId]<<" is the median ranking with value "<<distance[bestCandidatesId]<<"."<<endl;
	}
	return 0;
}