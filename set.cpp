#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s; //声明

	s.insert(1);//插入元素
	s.insert(3);
	s.insert(5);

	set<int>::iterator ite; //查找元素

	ite = s.find(1);
	if(ite == s.end()) puts("not found");
	else puts("found");

	ite = s.find(2);
	if(ite == s.end()) puts("not found");
	else puts("found");

	s.erase(3);//删除元素
	
	if(s.count(3) != 0)	puts("found");//其他查找元素的方法
	else puts("not found");

	for (ite = s.begin();ite != s.end();ite++){    //便利所有元素
		printf("%d\n",*ite);
	}

	return 0;
}