#include<cstdio>
#define max 1001
int n,id[max],lid[max],rid[max];
char data[max];
struct binary_Node{
	int id;
	char data;	
	binary_Node *lchild,*rchild;
};

void print_tree(binary_Node *root)
{
	if(root==NULL) return;
	if(root!=NULL)
	{
		printf("%c",root->data);
		print_tree(root->lchild);
		print_tree(root->rchild);
	}
}

binary_Node *create_tree(int pid)
{
	binary_Node *root=NULL;
	//���id!=0�Ž����ڵ㣬���򷵻�NULL 
	if(pid!=0){
		root = new binary_Node;
		root->lchild = NULL;
		root->rchild = NULL;
		//�ҵ����ڵ����� 
		int k=0;
		for(int i=0;i<n;i++){
			if(pid==id[i]) {k=i;break;}
		}
		//�������ڵ� 
		root->id=id[k];
		if(data[k]>='A' && data[k]<='Z'){
			root->data=data[k];
		}
		//������������ 
		root->lchild=create_tree(lid[k]);
		root->rchild=create_tree(rid[k]);
	}
	return root;
}

int main()
{
	freopen("1156in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		int r =0;
		for(int i=0;i<n;i++){
			scanf("%d %c %d %d",&id[i],&data[i],&lid[i],&rid[i]);
			//��0������㣬�ҵ�ֻ���ֹ�һ�ε�id�����idΪ���ڵ�id 
			r ^= id[i]^lid[i]^rid[i];
		}		
		binary_Node *root = create_tree(r);
		print_tree(root);
		printf("\n");
	}
	return 0;	
}
