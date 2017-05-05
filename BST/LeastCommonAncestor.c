#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int num;
	struct node*left;
	struct node*right;
};
struct node* Newnode(int num)
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
	{
		root=Newnode(num);
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
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d ",root->num);
		Inorder(root->right);
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

struct node* MinElement(struct node*root)
{
	if(root==NULL)
	{
		return(root);
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	printf("%d ",root->num);
	return(root);
}
int max(int a,int b)
{
	if(a>=b)
	return(a);
	
	else
	return(b);
}


struct node* MaxElement(struct node*root)
{
	if(root==NULL)
	{
		return(root);
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	printf("%d ",root->num);
	return(root);
}
 
int Height(struct node*root)
{
	int max_val=0;
	
	if(root==NULL)
	return(-1);
	
	max_val=max( Height(root->left), Height(root->right));
	return(max_val+1);
}

// Delete an Element of Tree:
struct node* Delete(struct node*root,int num)
{
	if(root==NULL)
	return(root);
	
	if(num < root->num)
	root->left=Delete(root->left,num);
	
	else if(num > root->num)
	root->right=Delete(root->right,num);
	
	else
	{
		if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return(temp);
		}
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return(temp);
		}
		
		struct node*temp=MinElement(root->right);
		root->num=temp->num;
		root->right=Delete(root->right,temp->num);
	}
	return(root);
}

void Print_outer_edges_left(struct node*root)
{
	if(root==NULL)
	return;
	
	printf("%d ",root->num);
	Preorder(root->left);
	Postorder(root->right);
}

//check for BST
int isBSTutil(struct node*root,int min,int max)
{
	if(root==NULL)
	return(1);										// Empty tree is a BST
	
	if(root->num < min || root->num > max)			// Root data should be greater than Min and less than Max: if it is not then its not a BST
		return(0);
	
	return(isBSTutil(root->left, min, (root->num)-1) && 								// left subtree should not have data greater than max 
	isBSTutil(root->right, (root->num)+1, max));   										// Right subtree should not have data greater than min
}

 int isBST(struct node*root)
{
	return (isBSTutil(root,INT_MIN,INT_MAX));
}


// Find Lowest Common Ancestor
struct node* LCA(struct node*root,int n1,int n2)
{
	if(root==NULL)							// If tree empty return NULL
	return(root);
	
	if(root->num > n1 && root->num >n2)		// If root is having greater value than both num Recur Left
	return(LCA(root->left,n1,n2));
	
	if(root->num < n1 && root->num <n2)
	return(LCA(root->right,n1,n2));
	
	return(root);
}

int main(void)
{
	struct node*root=NULL;
	int val=0;
	
	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,30);
	root=Insert(root,20);
	root=Insert(root,10);
	root=Insert(root,5);
	root=Insert(root,55);
	root=Insert(root,57);
	root=Insert(root,58);
	root=Insert(root,59);
	root=Insert(root,60);
	root=Insert(root,61);
	root=Insert(root,45);
	
	printf("\nInorder:\n");
	Inorder(root);
	printf("\nPreorder:\n");
	Preorder(root);
	printf("\nPostorder:\n");
	Postorder(root);
	
	// Testing Inorder Successor
	printf("\nInorder Successor of root is:");
	MinElement(root->right);
	
	// Testing Inorder Predecessor
	printf("\nInorder Predecessor of root is:");
	MaxElement(root->left);
	
	// Testing Print_outer_edges function
	printf("\nPrint_outer_edges:\n");
	Print_outer_edges_left(root);

	if(isBST(root))
	printf("\nBST\n");
	
	else
	printf("\nNOT_BST\n");
	
	root=LCA(root,40,60);
	printf("LCA is %d",root->num);
	
	
	
	
	
	// Testing height of tree
	//val=Height(root);
	//printf("\n\nheight is = %d \n\n",val);
	
	// Testing Deletion function:
	//root=Delete(root,45);
	//printf("\nInorder after deletion 45:\n");
	//Inorder(root);
	
	//root=Delete(root,60);
	//printf("\nInorder after deletion 60:\n");
	//Inorder(root);
	
	//root=Delete(root,50);
	//printf("\nInorder after deletion 50:\n");
//	Inorder(root);

	
	
	
	
	return(0);
	
}

	



