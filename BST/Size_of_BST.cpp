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
struct node* LCA(struct node* root,int n1,int n2)
{
	if(root==NULL)
		return(root);

	if(root->num > n1 && root->num > n2)
		return(LCA(root->left,n1,n2));

	if(root->num < n1 && root->num <n2)
		return(LCA(root->right,n1,n2));

	return(root);
}

int SizeofBST(struct node* root)
{
	if(root==NULL)
		return(0);
	else
		return( SizeofBST(root->left) + 1 + SizeofBST(root->right) );
}

int size(struct node*root)
{
	static int count =0;
	if(root==NULL)
		return(0);
	else if(root!=NULL)
	{
		size(root->left);
		count++;
		size(root->right);
	}
	return(count);
}

int main(void)
{
	struct node*root=NULL;
	struct node* lca=NULL;
	int count=0;

	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,60);
	root=Insert(root,30);
	root=Insert(root,70);
	root=Insert(root,55);
	root=Insert(root,45);
	root=Insert(root,145);

	root=Insert(root,500);
	root=Insert(root,400);
	root=Insert(root,600);
	root=Insert(root,300);
	root=Insert(root,700);
	root=Insert(root,550);
	root=Insert(root,450);
	root=Insert(root,1450);

	root=Insert(root,5000);
	root=Insert(root,4000);
	root=Insert(root,6000);
	root=Insert(root,3000);
	root=Insert(root,7000);
	root=Insert(root,5500);
	root=Insert(root,4500);
	root=Insert(root,14500);

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

	lca=LCA(root,30,45);
	printf("\n\n\n LCA is ->%d ",lca->num);

	count = SizeofBST(root);
	printf("\n\nsize of the BST is %d \n",count);

	count = size(root);
	printf("\n\nsize of the BST*** is %d \n",count);

	return(0);
}






