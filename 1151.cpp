#include<iostream>
#include<queue>
using namespace std;
typedef struct moban{
	int x[4];
	int y[4];
	std::string s;
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
		for (int i = 0; i < 4; ++i){
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

int main()
{

	freopen("1150input.txt","r",stdin);
	int n;
	while(std::cin>>n && n!=-1){
		moban stdmoban;
		for (int i = 0; i < 4; ++i){
			std::cin>>stdmoban.x[i];
		}
		for (int i = 0; i < 4; ++i){
			std::cin>>stdmoban.y[i];
		}
		moban initial(1,2,3,4,8,7,6,5);

		std::queue<moban> qm[n+1];
		qm[0].push(initial);
		bool success = false;
		for (int i = 0; i < n; ++i)
		{	
			while(!qm[i].empty())
			{
				for (int j = 1; j <= 3; ++j)
				{	
					moban temp = qm[i].front();

					ope(temp,j);

					if(j == 1) temp.s+="A";
					else if(j == 2) temp.s+="B";
					else if(j == 3) temp.s+="C";
					if(comp(temp,stdmoban)) {
						std::cout<<i+1<<" "<<temp.s;
						std::cout<<std::endl;
						success = true;
						break;
					}
					qm[i+1].push(temp);
					if(j == 3) qm[i].pop();
				}
				if(success) break;
			}
			if(success) break;
		}
		if(!success) std::cout<<"-1"<<std::endl;
	}
	return 0;
}