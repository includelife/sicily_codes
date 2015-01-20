#include <cstdio>
#include <stack>
//using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n%2!=0) { printf("NO %d\n",n); continue;}
		char ch[101];
		std::stack<char> st;
		scanf("%s",ch);
		int i = 0;
		while(i<n)
		{
			if(st.empty()) st.push(ch[i]);
			else if(st.top()=='(' && ch[i]==')') st.pop();
			else if(st.top()=='[' && ch[i]==']') st.pop();
			else if(st.top()=='{' && ch[i]=='}') st.pop();
			else {
				st.push(ch[i]);
			}
			i++;
		}
		if(st.empty()) printf("YES\n");
		else if(!st.empty()) printf("NO\n");
	}
	return 0;
}
