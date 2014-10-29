#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct print{
    int p;
    int key;
};
bool cmp(print a,print b)
{
    return a.key > b.key;
}
int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--) {
        int n,mid;
        cin>>n>>mid;
        print a[n];
        queue<print> myq;
        for (int i = 0; i < n; ++i){
            cin>>a[i].key;
            a[i].p = i;
            myq.push(a[i]);
        }
        sort(a,a+n,cmp);
        queue<print> prique;
        for (int i = 0; i < n; ++i){
            prique.push(a[i]);
        }
        int cnt = 0;  
        while(!myq.empty()){
            if((myq.front()).key == (prique.front()).key){
                cnt++;
                if((myq.front()).p == mid) break;
                myq.pop();
                prique.pop();
            }
            if((myq.front()).key < (prique.front()).key){
                myq.push(myq.front());
                myq.pop();
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}                                 