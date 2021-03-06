#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef struct moban{
    string status;
    string s;
};

bool comp(string A,string B)
{
    if(A!=B) return false;
    else return true;
}

string ope(string ps,int n){
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

void bfs(moban stdmoban,int max){
    moban initial;
    initial.status="12348765";
    initial.s="";
    queue<moban> qm;

    qm.push(initial);
    set<string> myset;
    myset.insert(initial.status);

    if(comp(initial.status,stdmoban.status)) {  cout<<"0 "<<endl;return;}
    while(!qm.empty()){
        for (int j = 1; j <= 3; ++j){
            moban temp=qm.front();
           // cout<<myset.size()<<" ";
            temp.status = ope(temp.status,j);

            if(j==1) temp.s += "A";
            else if(j==2) temp.s += "B";
            else if(j==3) temp.s += "C";

            if(comp(temp.status,stdmoban.status)){
                cout<<temp.s.length()<<"  "<<temp.s<<endl;
                return;
            }
            if(temp.s.length() > max)   cout<<"-1"<<endl;
            if(myset.count(temp.status)==0){
                qm.push(temp);
                myset.insert(temp.status);
            }
        }
        qm.pop();
    }
}

int main()
{   
    freopen("1150input.txt","r",stdin);
    int n;
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
        bfs(stdmoban,n);
    }
    return 0;
}