#include <cstdio>
#include <string>
#include<iostream>>
using namespace std;

string ADD_INT(string str1, string str2) 
{ 
string str; 
string::size_type l1, l2; 
int i; 
l1 = str1.size(); l2 = str2.size(); 
if(l1 < l2) { 
for(i = 1; i <= l2 - l1; i++) 
str1 = "0" + str1; 
}else { 
for(i = 1; i <= l1 - l2; i++) 
str2 = "0" + str2; 
} 
int int1 = 0, int2 = 0; 
for(i = str1.size() - 1; i >= 0; i--) { 
int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10; 
int2 = (int(str1[i]) - 48 + int(str2[i]) - 48 +int2) / 10; 
str = char(int1 + 48) + str; 
} 
if(int2 != 0) str = char(int2 + 48) + str; 
return str; 
}

string MULTIPLY_INT(string str1, string str2) 
{ 
string str; 
int i, j; 
string::size_type l1, l2; 
l1 = str1.size(); l2 = str2.size(); 
for(i = l2 - 1; i >= 0; i --) { 
string tempstr; 
int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48; 
if(int3 != 0) { 
for(j = 1; j <= (int)(l2 - 1 - i); j++) 
tempstr = "0" + tempstr; 
for(j = l1 - 1; j >= 0; j--) { 
int1 = (int3 * (int(str1[j]) - 48) + int2) % 10; 
int2 = (int3 * (int(str1[j]) - 48) + int2) / 10; 
tempstr = char(int1 + 48) + tempstr; 
} 
if(int2 != 0) tempstr = char(int2 + 48) + tempstr; 
} 
str = ADD_INT(str, tempstr); 
} 
str.erase(0, str.find_first_not_of('0')); 
if(str.empty()) str = "0"; 
return str; 
} 



int main()
{
int t,i;
int n;
string x,y,d;
string num[55];
scanf("%d",&t);
while(t--)
{
cin >>n>>x;
for(i=0;i<=n;i++)
cin >>num[i];
y="0";
i=0;
while(i<=n)
{
d=MULTIPLY_INT(x,y);
y=ADD_INT(num[i],d);
i++;
}
cout<<y<<endl;
}
return 0;
}
