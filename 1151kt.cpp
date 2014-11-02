//BFS深度优先搜索+全排列编码(康托展开)
#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int fact[9] = {0,1,2,6,24,120,720,5040,40320};//阶乘表
string str;//空字符串
struct move
{
	int num;//状态
	string di;//操作记录
	bool vis;//记录是否被访问过
}step[40321];//1到8的全排列数
int A(int source)//操作A
{
	return source%10000*10000+source/10000;
}
int B(int source)//操作B
{
	int temp = 0;
	temp += source%1000/10;
	temp += source%10000/1000*100;
	temp += source%10*1000;
	temp += source%1000000/100000*10000;
	temp += source/1000000*100000;
	temp += source%100000/10000*10000000;
	return temp;
}
int C(int source)//操作C
{
	int temp = 0;
	temp += source%10;
	temp += source%1000000/100000*10;
	temp += source%100/10*100;
	temp += source%100000/1000*1000;
	temp += source%10000000/1000000*100000;
	temp += source%1000/100*1000000;
	temp += source/10000000*10000000;
	return temp;
}
int encode(int n)//全排列编码方法
{
	int temp[9],code = 0;
	for(int i = 8;i >= 1;--i)
	{
		temp[i] = n % 10;
		n /= 10;
	}
	for(int i = 1;i <= 8;++i)//*****康托展开公式：当前位数的逆序数*该位数的阶乘****(本题重点)
	{
		int cnt = 0;
		for(int j = i + 1;j <= 8;j++)
			if(temp[i] > temp[j])	++cnt;
		code += fact[8-i] * cnt;
	}
	return code;
}
void clear(move step[])
{
	for(int i = 1;i <= 40320;++i)
	{
		step[i].num = 0;
		step[i].vis = 0;
		step[i].di = str;
	}
}
int main()
{
	freopen("1151input.txt","r",stdin);
	int source = 12348765;
	int min_step;
	int goal;
	
	int ok;
	int a,aa,b,bb,c,cc,ss,g;
	while(cin >> min_step)
	{
		if(min_step == -1)	break;
		int target[9];
		ok = 1;
		queue<int> q;
		clear(step);
		for(int i = 0;i < 8;++i)
			cin >> target[i];
		goal = target[7] + target[6]*10 + target[5]*100 + target[4]*1000 + target[3]*10000 + target[2]*100000 + target[1]*1000000 + target[0]*10000000;
		g = encode(goal);
		q.push(source);
		while(q.front() != goal)
		{
            if(step[encode(q.front())].num > min_step)//超过最大步数则跳出
            {
                 cout << -1 << endl;
                 ok = 0;
                 break;
            }
			a = A(q.front());aa = encode(a);//a为A操作后所得的状态，aa为编码后的状态
			b = B(q.front());bb = encode(b);//b为B操作后所得的状态，bb为编码后的状态
			c = C(q.front());cc = encode(c);//c为C操作后所得的状态，cc为编码后的状态
			ss = encode(q.front());//对应
			
			if(!step[aa].vis)
			{
				q.push(a);//将状态插入队列
				step[aa].num = step[ss].num + 1;//步数+1
				step[aa].di = step[ss].di + "A";//插入操作数
				step[aa].vis = 1;//标记已访问
			}
			if(!step[bb].vis)
			{
				q.push(b);
				step[bb].num = step[ss].num + 1;
				step[bb].di = step[ss].di + "B";
				step[bb].vis = 1;
			}
			if(!step[cc].vis)
			{
				q.push(c);
				step[cc].num = step[ss].num + 1;
				step[cc].di = step[ss].di + "C";
				step[cc].vis = 1;
			}
			q.pop();
		}
		if(ok)
			cout << step[g].num <<" " <<step[g].di << endl;
	}
	return 0;
}