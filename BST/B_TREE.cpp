#include<stdio.h>
#include<stdlib.h>

// Creation of Binary Search Tree
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

// Insert element in a tree
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

// Searching an Element in a tree
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

// Find Minimum Element in a BST
int FindMin(struct node*root)
{
	if(root==NULL)
	{
		printf("\nTree Empty\n");
		return(-1);
	}
	while(root->left!=NULL){
		root=root->left;
	}
	return(root->num);
}

// Find MAX Element in a BST
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

int main(void)
{
	int search_var,data;
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

	data=FindMin(root);
	printf("\n%d\n",data);

	data=FindMax(root);
	printf("\n%d\n",data);

	return(0);
}