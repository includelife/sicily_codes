#include<iostream>
using namespace std;
int id[10002],lcid[10002],rcid[10002];
char data[10002];
int t;

typedef struct binary_tree
{
	int id;
	char data;
	struct binary_tree *lchild;
	struct binary_tree *rchild;
};

void print_tree(binary_tree *root)
{
	if(root == NULL) return;
	if(root != NULL)
	{
		cout<<root->data;
		print_tree(root->lchild);
	 	print_tree(root->rchild);
	}
}

binary_tree *create_tree(binary_tree *root,int pid)
{
		root = new binary_tree;
		root->lchild = NULL;
		root->rchild = NULL;
		int k = 0;
		for (int i = 0; i < t; ++i)
		{
			if(pid == id[i]) { k=i; break;}
		}

		root->id = id[k];
		if(data[k] >= 'A' && data[k] <='Z'){
			root->data = data[k];
		}

		if(lcid[k] != 0)
		{
			root->lchild = create_tree(root->lchild,lcid[k]);
		}
		if(rcid[k] != 0)
		{
			root->rchild = create_tree(root->rchild,rcid[k]);
		}
		return root;
}

int main()
{
	freopen("input.txt","r",stdin);
	while(cin>>t)
	{
		int r = 0;
		for (int i = 0; i < t; ++i)
		{
			cin>>id[i]>>data[i]>>lcid[i]>>rcid[i];
			r ^= id[i]^lcid[i]^rcid[i];  //找出根节点
		}
		//cout<<r<<endl;
		binary_tree *root;
 		binary_tree *tree = create_tree(root,r);

 		print_tree(tree);
 		cout<<endl;
	}
	return 0;
}