#include<stdio.h>
#include<stdlib.h>

// Creation of a Binary Search Tree
struct node
{
	int num;
	struct node*left;
	struct node*right;
};

// Creation of NewNode
struct node* Newnode(int data)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

// Insert an element in a Tree
struct node* insert(struct node*root,int num)
{
	struct node*root_node=root;
	
	if(root_node==NULL)
	{
		root_node=Newnode(num);
	}
	else if(root_node->num > num)
	{
		root_node->left = insert((root_node->left),num);
	}
	else if(root_node->num < num)
	{
		root_node->right = insert((root_node->right),num);
	}
	return(root_node);
}

// Searching an Element in a Tree
int search(struct node*root,int num)
{
	if(root==NULL)
		return(false);

	if(root->num==num)
		return(true);

	else if(num < root->num)
		return(search(root->left,num));

	else
		return(search(root->right,num));
}

// Find Min Element in a BST
int FindMin(struct node*root)
{
	if(root==NULL)
	{
		printf("\nTree Empty\n");
		return(-99);
	}
	while(root->left!=NULL){
		root=root->left;
	}
	return(root->num);
}

int FindMin_recursive(struct node*root)
{
	if(root==NULL)
	{
		printf("\nTree Empty\n");
		return(-99);
	}
	if(root->left==NULL)
		return(root->num);

	FindMin_recursive(root->left);
}

int FindMax_recursive(struct node*root)
{
	if(root==NULL)
	{
		printf("\nTree empty\n");
		return(-1);
	}
	if(root->right==NULL)
		return(root->num);

	FindMax_recursive(root->right);
}

// Find Max Element in a BST

int FindMax(struct node*root)
{
	if(root==NULL)
	{
		printf("\nTree Empty\n");
		return(-1);
	}
	while(root->right!=NULL){
		root=root->right;
	}
	return(root->num);
}
// Find the max num
int max(int a,int b)
{
	if(a>=b)
		return(a);
	else
		return(b);
}

// Find The Height of the Tree
int FindHeight(struct node*root)
{
	if(root==NULL)
		return(-1);
	return(max(FindHeight(root->left),FindHeight(root->right))+1);
}

// LEVEL Order traversal DFS:
// Inorder
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

int main(void)
{
	int search_var,data,height;
	struct node*root=NULL;
	root= insert(root,55);
	root= insert(root,10);
	root= insert(root,15);
	root= insert(root,5);
	root= insert(root,4);
	root= insert(root,3);
	root= insert(root,2);
	root= insert(root,1);
	root= insert(root,25);
	root= insert(root,35);
	root= insert(root,45);
	root= insert(root,65);
	root= insert(root,75);
	root= insert(root,85);

	search_var=search(root,2);
	if(search_var)
		printf("\nNUMBER FOUND\n\n");
	else
		printf("\nNUMBER NOT FOUND\n\n");

	data=FindMin_recursive(root);
	printf("\n%d\n",data);

	data=FindMax_recursive(root);
	printf("\n%d\n",data);

	height= FindHeight(root);
	printf("\nHeight of the tree is %d\n",height);

	printf("\nInorder traversal is as:\n");
	Inorder(root);

	printf("\nPre-Order traversal is as:\n");
	preorder(root);

	printf("\nPost-Order traversal is as:\n");
	Postorder(root);

	return(0);
}