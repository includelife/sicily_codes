#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double sum(double x1,double y1,double x2,double y2,double x3,double y3)
{
   double a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
   double b = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
   double c = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
   return (a+b+c);
}
int main(int argc, char const *argv[])
{
   int t;
   cin>>t;
   for (int i = 0; i < t; ++i)
   {
      double x1, y1, x2, y2, x3, y3;
      cin>>x1>>y1>>x2>>y2>>x3>>y3;
      cout<<fixed<<setprecision(5)<<sum(x1,y1,x2,y2,x3,y3)<<endl;
   }
   return 0;
}