// Check if a Binary tree is BST or not:
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int num;
	struct node*left;
	struct node*right;
};

struct node* newnode(int num)
{
	struct node*Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->num=num;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return(Newnode);
}

struct node* Insert(struct node*root,int num)
{
	if(root==NULL)
	{
		root=newnode(num);
	}
	else if(num < root->num)
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
	if(root==NULL)return;

	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d ",root->num);
		Inorder(root->right);
	}
}

// Pre-order
void preorder(struct node*root)
{
	if(root==NULL)
		return;

		printf("%d ",root->num);
		preorder(root->left);
		preorder(root->right);
}

// Post-order
void Postorder(struct node*root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->num);
}

// Check BST
int isBSTutil(struct node*root,int min,int max)
{
	if(root==NULL)
		return(1);

	if(root->num < min || root->num > max)
		return(0);

	return(isBSTutil(root->left,min,root->num+1) && isBSTutil(root->right,root->num+1,max));
}

int isBST(struct node*root)
{
	return(isBSTutil(root,INT_MIN,INT_MAX));
}

int main(void)
{
	struct node*root=NULL;

	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,60);
	root=Insert(root,30);
	root=Insert(root,70);
	root=Insert(root,55);
	root=Insert(root,45);
	root=Insert(root,145);

	printf("\n\n");
	Postorder(root);

	printf("\n\n");
	Inorder(root);

	printf("\n\n");
	preorder(root);

	if(isBST(root))
		printf("\nBST\n");
	else
		printf("\nNON-BST\n");


	return(0);
}






