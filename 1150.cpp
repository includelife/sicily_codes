#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef struct moban{
	int x[4];
	int y[4];
	string s;
	moban(){}
	moban(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
		x[0] = x1;	x[1] = x2;	x[2] = x3;	x[3] = x4;
		y[0] = y1;	y[1] = y2;  y[2] = y3;	y[3] = y4;
	}
};

bool comp(moban A,moban B){
	for (int i = 0; i < 4; ++i)
	{
		if(A.x[i] != B.x[i] || A.y[i] != B.y[i]) return false;
	}
	return true;
}

void ope(moban &pmoban,int n){
	if(n == 1){
		int temp[4];
		for (int i = 0; i < 4; ++i)
		{
			temp[i] = pmoban.x[i];	pmoban.x[i] = pmoban.y[i];	pmoban.y[i] = temp[i];
		}
	}else if(n == 2){
		int tx = pmoban.x[3];
		int ty = pmoban.y[3];
		for (int i = 3; i >= 1; i--)
		{
			pmoban.x[i] = pmoban.x[i-1];
			pmoban.y[i] = pmoban.y[i-1];
		}
		pmoban.x[0] = tx;
		pmoban.y[0] = ty;
	}else if(n == 3){
		int temp3;
		temp3 = pmoban.x[1];
		pmoban.x[1] = pmoban.y[1];
		pmoban.y[1] = pmoban.y[2];
		pmoban.y[2] = pmoban.x[2];
		pmoban.x[2] = temp3;
	}
}
void printmoban(moban temp){
	for (int k = 0; k < 4; ++k)
	{
		cout<<temp.x[k];
	}
	cout<<endl;
	for (int k = 0; k < 4; ++k)
	{
		cout<<temp.y[k];
	}
	cout<<endl;
	cout<<temp.s<<endl;
}
int main()
{
	freopen("1150input.txt","r",stdin);
	int n;
	while(cin>>n && n!=-1){
		moban stdmoban;
		for (int i = 0; i < 4; ++i){
			cin>>stdmoban.x[i];
		}
		for (int i = 0; i < 4; ++i){
			cin>>stdmoban.y[i];
		}

		moban initial(1,2,3,4,8,7,6,5);
		queue<moban> qm[n+1],qm_all;
		qm[0].push(initial);
		qm_all.push(initial);

		bool success = false;
		int num = 0;

		for (int i = 0; i < n; ++i)
		{	
			while(!qm[i].empty())
			{
				//cout<<qm[i].size()<<" "<<i<<" ";
				for (int j = 1; j <= 3; ++j)
				{	
					//cout<<num++<<" ";
					moban temp = qm[i].front();
					cout<<temp.s<<endl;
					if(comp(temp,stdmoban)) {
					cout<<i<<" ";
					cout<<endl;
					success = true;
					break;
					}

					ope(temp,j);

					if(j == 1) temp.s+="A";
					else if(j == 2) temp.s+="B";
					else if(j == 3) temp.s+="C";
					if(comp(temp,stdmoban)) {
						cout<<i+1<<" "<<temp.s;
						cout<<endl;
						success = true;
						break;
					}
					//printmoban(temp);
					qm[i+1].push(temp);

					if(j == 3) qm[i].pop();
				}
				//cout<<endl;
				if(success) break;
			}
			if(success) break;
		}
		if(!success) cout<<"-1"<<endl;
	}
	return 0;
}