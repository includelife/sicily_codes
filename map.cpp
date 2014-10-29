#include<iostream>
#include<map>

using namespace std;
int main()
{
	map<int,const char*> m; //声明（int为键，const char*为值）

	m.insert(make_pair(1,"one")); //插入值
	m.insert(make_pair(2,"two"));
	m[100] = "hundred";    //其他写法

	map<int,const char*>::iterator ite; //查找元素
	ite = m.find(1);
	puts(ite->second);

	ite = m.find(2);
	if(ite == m.end()) puts("not found");
	else puts(ite->second);

	puts(m[10]); //其他写法

	m.erase(10); //删除元素

	for(ite == m.begin();ite != m.end();ite++)  //遍历所有元素
	{
		printf("%d:%s\n",ite->first,ite->second);
	}
	return 0;
}