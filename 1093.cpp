#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("1093input.txt","r",stdin);
	int w[4],r[5],set_number =0,weight,bound[3];
	while(cin>>w[1]>>r[1]>>w[2]>>r[2]>>w[3]>>r[3]>>r[4])
	{
		w[1]++;
		w[2]++;
		w[3]++;
		set_number++;
		for (int i = 0; i < 3; ++i)
		{
			bound[i] = w[i+1] * r[i+2];
		}
		cout<<"Set number "<<set_number<<":"<<endl;
		while(cin>>weight && weight != 0)
		{
			if(weight < w[1])
			{
				int min_bound = bound[0];
				for (int i = 1; i < 3; ++i)
				{
					if(bound[i]<min_bound)	min_bound = bound[i];
				}
				if(weight*r[1] <= min_bound) 
				{
					cout<<"Weight ("<<weight<<") has best price $"<<weight*r[1]<<" (add 0 pounds)"<<endl;
				}else if(min_bound == bound[0])
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[0]<<" (add "<<w[1]-weight<<" pounds)"<<endl;
				}else if(min_bound == bound[1])
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[1]<<" (add "<<w[2]-weight<<" pounds)"<<endl;
				}else
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[2]<<" (add "<<w[3]-weight<<" pounds)"<<endl;
				}
			}
			else if(weight < w[2])
			{
				int min_bound = min(bound[1],bound[2]);
				if(weight*r[2] <= min_bound)
				{
					cout<<"Weight ("<<weight<<") has best price $"<<weight*r[2]<<" (add 0 pounds)"<<endl;
				} else if(min_bound == bound[1])
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[1]<<" (add "<<w[2]-weight<<" pounds)"<<endl;
				}else if(min_bound ==bound[2])
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[2]<<" (add "<<w[3]-weight<<" pounds)"<<endl;
				}
			}
			else if(weight < w[3])
			{
				if(weight*r[3] < bound[2])
				{
					cout<<"Weight ("<<weight<<") has best price $"<<weight*r[3]<<" (add 0 pounds)"<<endl;
				}else
				{
					cout<<"Weight ("<<weight<<") has best price $"<<bound[2]<<" (add "<<w[3]-weight<<" pounds)"<<endl;
				}
			}
			else
			{
				cout<<"Weight ("<<weight<<") has best price $"<<weight*r[4]<<" (add 0 pounds)"<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}