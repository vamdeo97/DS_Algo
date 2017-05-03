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
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

struct node* Insert(struct node*root,int num)
{
	if(root==NULL)
		root=newnode(num);
	else if(num < root->num)
		root->left=Insert(root->left,num);
	else
		root->right=Insert(root->right,num);
	return(root);
}

int Search(struct node*root,int num)
{
	if(root==NULL)
		return(false);

	else if(root->num==num)
		return(true);

	else if(num < root->num)
		return(Search(root->left,num));

	else if(num > root->num)
		return(Search(root->right,num));
}

void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->num);
		inorder(root->right);
	}
}

void Preorder(struct node*root)
{
	if(root==NULL)
		return;

	printf("%d ",root->num);
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(struct node*root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->num);
}

// Min value of that tree:
struct node* Minvalue(struct node*root)
{
	if(root==NULL)
		return(root);

	while(root->left!=NULL)
		root=root->left;
	return(root);
}

// Max value of that subtree
struct node* Maxvalue(struct node*root)
{
	if(root==NULL)
		return(root);

	while(root->right!=NULL)
		root=root->right;
	return(root);
}

// Deletion of KEY Element from a BST
struct node* Delete(struct node*root,int key)
{
	if(root==NULL)
		return(root);
	else if(key < root->num)
		root->left=Delete(root->left,key);
	else if(key > root->num)
		root->right=Delete(root->right,key);
	else
	{
		// If root has single child in Right
		if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return(temp);
		}
		// If root has single child in left
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return(temp);
		}
		// Node with two children
		struct node*temp=Minvalue(root->right);
		root->num=temp->num;
		root->right=Delete(root->right,temp->num);
	}
	return(root);
}

void print_outer_edges(struct node*root)
{
	if(root==NULL)
		return;
		printf("%d ",root->num);
		Preorder(root->left);
		Postorder(root->right);
}
int main(void)
{
	struct node*Min=NULL,*Max=NULL;
	struct node*root=NULL;

	int count=0;
	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,30);
	root=Insert(root,20);
	root=Insert(root,60);
	root=Insert(root,70);
	root=Insert(root,80);
	root=Insert(root,90);
	root=Insert(root,45);
	root=Insert(root,55);
	root=Insert(root,42);
	root=Insert(root,62);

	printf("\nInorder traversal is as:\n");
	inorder(root);
	printf("\nPostorder traversal is as:\n");
	Postorder(root);
	printf("\nPreorder traversal is as:\n");
	Preorder(root);

	count=Search(root,42);
	if(count)
		printf("\n\n Found Element in BST:\n");
	else
		printf("\n\n Not found element in BST:\n");

	Max=Maxvalue(root->left);
	printf("\nInorder->Predecessor of root: %d is %d\n",root->num,Max->num);

	Min=Minvalue(root->right);
	printf("\nInorder->Sucessor of root: %d is %d\n",root->num,Min->num);

	//root=Delete(root,50);

	printf("\nInorder traversal after deletion is as:\n");
	inorder(root);
	
	printf("\nprint_outer_edges\n");
	print_outer_edges(root);



	
	return(0);
}






