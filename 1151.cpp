#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
int fact[]={1,1,2,6,24,120,720,5040};
string visited[50000];
typedef struct moban
{
	string status; //魔板状态
	string s;     //魔板到代该状态的操作
};

moban initial; //初始状态的魔板
queue<moban> qm; //记录还需要进行操作的状态

bool comp(string A,string B)  //对两个状态进行比较
{
    if(A!=B) return false;
    else return true;
}
string ope(string ps,int n){   //对状态进行操作
    if(n==1){
        string x1=ps.substr(4,4)+ps.substr(0,4);
        return x1;
    }else if(n==2){
        string x21=ps.substr(3,1)+ps.substr(0,3);
        string y21=ps.substr(7,1)+ps.substr(4,3);
        return x21+y21;
    }else if(n==3){
        string x31=ps.substr(0,1)+ps.substr(5,1)+ps.substr(1,1)+ps.substr(3,1);
        string y31=ps.substr(4,1)+ps.substr(6,1)+ps.substr(2,1)+ps.substr(7,1);
        return x31+y31;
    }
}

int encode(string s)    //康托展开，将一个特定的码与一个状态对应起来
{
	int n1,n2;
	int temp[8];
	int cnt;
	string s1 = s.substr(0,4);
	string s2 = s.substr(7,1)+s.substr(6,1)+s.substr(5,1)+s.substr(4,1);
	n1 = atoi(s1.c_str());   //string转int
	n2 = atoi(s2.c_str());
	n1 = n1*10000+n2;
	int code = 0;
	for (int i = 7; i >= 0; i--)
	{
		temp[i] = n1 % 10;
		n1 /= 10;
	}
	for (int i = 0; i < 7; ++i)
	{
		cnt = 0;
		for (int j = i+1; j < 8; ++j)
		{
			if(temp[j] < temp[i]) cnt++;
		}
		n1 += fact[8-i-1] * cnt; 
	}
	return n1;
}

void bfs(moban stdmoban,int max)  //广度优先搜索
{
	qm.push(initial);        //初始状态入队
	if(comp(initial.status,stdmoban.status)) {	cout<<"0  "<<endl;return;}   //如果初始状态即为目标状态,输出0
	if(visited[encode(stdmoban.status)]!="") {	cout<<visited[encode(stdmoban.status)].length()<<" "<<visited[encode(stdmoban.status)]<<endl;return;} 
	// 如果目标状态已经被搜索过,直接输出其操作
	while(!qm.empty())
	{
        for (int j = 1; j <= 3; ++j)  //对魔板进行A，B，C操作
        {
		    moban temp=qm.front();
		    temp.status = ope(temp.status,j);
		    int code = encode(temp.status); //得到康拓展开的特征码
		    if(j==1) temp.s += "A";
		    else if(j==2) temp.s += "B";
		    else if(j==3) temp.s += "C";

		    if(comp(temp.status,stdmoban.status)){   //判断是否为目标状态
		        cout<<temp.s.length()<<" "<<temp.s<<endl; 
		        return;
		    }
		    if(temp.s.length() > max)   {cout<<"-1"<<endl;return;}  //超过最大次数,输出-1

		    if(visited[code]==""){  //如果没有被搜索过，则进队，同时vistited记录操作
		     	visited[code] = temp.s;
		        qm.push(temp);
		    }
        }
        qm.pop();  //出队
	}
}

int main()
{
	freopen("1151input.txt","r",stdin);
	initial.status="12348765";
	initial.s="";
	int n;
	//得到输入
    while(cin>>n && n!=-1){
        moban stdmoban;

        for (int i = 0; i < 4; ++i)
        {
            string x;
            cin>>x;
            stdmoban.status += x;
        }
        for (int i = 0; i < 4; ++i)
        {
            string y;
            cin>>y;
            stdmoban.status += y;
        }
 	    //广度优先搜索
        bfs(stdmoban,n);
    }
    return 0;
}
