#include<iostream>
using namespace std;
class Cubic
{
private:
	int length,width,heigth;
public:
	int volume()
	{
		return length*width*heigth;
	}
	cubic(int l,int w,int h)
	{
		length=l;
		width=w;
		heigth=h;
	};
	~cubic();
};

int main()
{	
	for (int i = 0; i < 3; ++i)
	{
		int l,w,h;
		cin>>l>>w>>h;
		Cubic c(l,w,h);
		cout<<c.volume()<<endl;
	}
	return 0;
}