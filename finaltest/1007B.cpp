#include<cstdio>
using namespace std;
int n,count;
int id[1000],lid[1000],rid[1000];
struct Node{
	int data;
	Node *lchild,*rchild;
};
Node *create_tree(int pid)
{
	if(pid==0) return NULL;
	Node *root=NULL;
	root = new Node();
	root->lchild=NULL;
	root->rchild=NULL;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(id[i]==pid) {k=i;break;}
	}
	root->data=pid;
	root->lchild=create_tree(lid[k]);
	root->rchild=create_tree(rid[k]);
	return root;
}
void post(Node *root)
{
	if(root==NULL) return;
	post(root->lchild);
	post(root->rchild);
	printf("%d",root->data);
	count++;
	if(count<n) printf(" ");
}
int main()
{
	freopen("1.txt","r",stdin);
	while(scanf("%d",&n) && n)
	{
		count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&id[i],&lid[i],&rid[i]);
		}
		int r=0;
		for(int i=0;i<n;i++)
		{
			r ^=id[i]^lid[i]^rid[i];
		}
		//printf("%d",r);
		Node *root=NULL;
		root=create_tree(r);
		post(root);
		printf("\n");		
	}
	return 0;
}
