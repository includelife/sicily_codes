#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef struct moban
{
	string status;
	string s;
};

string ope(string ps,int n)
{
	if(n==1){
		string x1 = ps.substr(2,2)+ps.substr(0,2);
		string y1 = ps.substr(6,2)+ps.substr(4,2);
		return x1+y1;
	}else if(n==2){
		string x2 = ps.substr(1,3)+ps.substr(0,1);
		string y2 = ps.substr(5,3)+ps.substr(4,1);
		return x2+y2;
	}else if(n==3){
		string x3 = ps.substr(0,1)+ps.substr(2,1)+ps.substr(6,1)+ps.substr(3,1);
		string y3 = ps.substr(4,1)+ps.substr(1,1)+ps.substr(5,1)+ps.substr(7,1);
		return x3+y3;
	}
}

moban initial;
queue<moban> qm;
map<string,string> mymap;
map<string,string>::iterator ite;

void bfs(moban pmoban,int max)
{
	//if(pmoban.status == initial.status) {cout<<"0"<<endl;return;}

	if(mymap.count(pmoban.status) != 0){
		ite = mymap.find(pmoban.status);
		if(ite->second.length() <= max){
			cout<<ite->second.length()<<" "<<ite->second<<endl;
			return;
		}
	}

	while(!qm.empty()){
		for (int i = 1; i <= 3; ++i)
		{
			moban temp = qm.front();
			temp.status = ope(temp.status,i);	
			//cout<<temp.status<<" ";
			if(i==1) temp.s += "A";
			else if(i==2) temp.s += "B";
			else if(i==3) temp.s += "C";

			if(temp.s.length() > max)   {cout<<"-1"<<endl;return;}
			if(temp.status == pmoban.status){
				cout<<temp.s.length()<<" "<<temp.s<<endl;
				return;
			}

			if(mymap.count(temp.status) == 0)
			{
				qm.push(temp);
				mymap.insert(make_pair(temp.status,temp.s));
			}
		}
		//cout<<endl;
		qm.pop();
	}
}

int main()
{
	freopen("1515input.txt","r",stdin);
	initial.status = "12345678";
	initial.s="";
	qm.push(initial);
	mymap.insert(make_pair(initial.status,initial.s));
	int n;
	while(cin>>n && n!= -1)
	{
		moban stdmoban;
		string x;
		for (int i = 0; i < 4; ++i)
		{
			cin>>x;
			stdmoban.status += x;
		}
		for (int i = 0; i < 4; ++i)
		{
			cin>>x;
			stdmoban.status += x;
		}
		stdmoban.s = "";
		bfs(stdmoban,n);
	}
	return 0;
}