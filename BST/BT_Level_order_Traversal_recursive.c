#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*left;
	struct node*right;
};

struct node* newnode(int num)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->num=num;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return(Newnode);
}

struct node* Insert(struct node*root,int num)
{
	if(root==NULL)
	root=newnode(num);
	
	else if(root->num < num)
	{
		root->right=Insert(root->right,num);
	}
	else
	{
		root->left=Insert(root->left,num);
	}
	return(root);
}

int MAX(int a,int b)
{
	if(a>b)
	return(a);
	
	else
	return(b);
}

int height(struct node*root) // compute height as number of nodes
{
	if(root==NULL)
	return(0);
	
	return( MAX(height(root->left),height(root->right))+1);
}


void printgivenlevel(struct node*root,int level)
{
	if(root==NULL)
	return;
	
	if(level==1)
	printf("%d ",root->num);
	
	else if(level > 1)
	{
		printgivenlevel(root->left,level-1);
		printgivenlevel(root->right,level-1);
	}
}

void Printlevelorder(struct node*root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
	printgivenlevel(root,i);
}

int main(void)
{
	struct node* root=NULL;
	int num;
	
	root=newnode(10);
	
	root->left=newnode(100);
	root->right=newnode(110);
	
	root->left->left=newnode(101);
	root->right->right=newnode(102);
	
	root->left->left->left=newnode(105);
	root->right->right->right=newnode(106);
	
	root->left->left->left=newnode(1005);
	root->right->right->right=newnode(1006);
	
	num=height(root);
	printf("Height of Tree is  %d ",num);
	
	printf("\nLEVEL ORDER TRAVERSAL RECURSIVE:\n");
	Printlevelorder(root);
	return(0);
}
		
	
	