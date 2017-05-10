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
	struct node*Newnode= (struct node*)malloc(sizeof(struct node));
	Newnode->num=num;
	Newnode->left=Newnode->right=NULL;
	return(Newnode);
}

// Print the nodes within a range:
void Range(struct node*root,int n1,int n2)
{
	if(root==NULL)
		return;

	if(root->num > n1)
		Range(root->left,n1,n2);

	if(root->num >= n1 && root->num <= n2)
		printf("%d ",root->num);

	if(root->num < n2)
		Range(root->right,n1,n2);
}



struct node* Insert(struct node*root,int num)
{
	if(root==NULL)
	{
		root=newnode(num);
	}
	if(num < root->num)
	{
		root->left=Insert(root->left,num);
	}
	else if(num > root->num)
	{
		root->right=Insert(root->right,num);
	}
	return(root);
}

void Inorder(struct node*root)
{
	if(root==NULL)
		return;

	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d ",root->num);
		Inorder(root->right);
	}
}

int main(void)
{
	struct node*root=NULL;

	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,60);
	root=Insert(root,50);
	root=Insert(root,65);
	root=Insert(root,55);
	root=Insert(root,30);
	root=Insert(root,45);
	root=Insert(root,20);
	root=Insert(root,35);
	root=Insert(root,10);
	Inorder(root);
	printf("\nRange\n");
	Range(root,20,55);

	return(0);
}

