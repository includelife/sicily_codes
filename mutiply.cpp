#include <iostream>
#include <cstring>
using namespace tsd;  
//高精度乘法  
string MULTIPLY_INT(string str1, string str2)  
{  
     int sign = 1; //sign 为符号位  
     string str;  
     if(str1[0] == '-') {  
           sign *= -1;  
           str1 = str1.erase(0, 1);  
     }  
     if(str2[0] == '-') {  
           sign *= -1;  
           str2 = str2.erase(0, 1);  
     }  
     int i, j;  
     string::size_type l1, l2;  
     l1 = str1.size(); l2 = str2.size();  
     for(i = l2 - 1; i >= 0; i --) {  //实现手工乘法  
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
     if((sign == -1) && (str[0] != '0'))  
           str = "-" + str;  
     return str;  
}  
  
int main()  
{  
      char ch;  
      string s1, s2, res;  
      while(cin >> s1 >> s2)
      {  
          res = MULTIPLY_INT(s1, s2); //高精度乘法  
          cout << res << endl;    
      }    
      return(0);  
}