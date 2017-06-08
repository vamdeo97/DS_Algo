#include<stdio.h>
#include<stdlib.h>

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
	newnode->left=newnode->right=NULL;
	return(newnode);
}

struct node* insert(struct node*root,int num)
{
	if(root==NULL)
	{
		root=Newnode(num);
	}
	else if(num < root->num)
	{
		root->left=insert(root->left,num);
	}
	else
	{
		root->right=insert(root->right,num);
	}
	return(root);
}

void inorder(struct node*root)
{
	if(root==NULL)
	return;
	else
	{
		inorder(root->left);
		printf("%d ",root->num);
		inorder(root->right);
	}
}

// Print the array
void printarr(int path[],int pathlen)
{
	int i;
	for(i=0;i<pathlen;i++)
	printf("%d ",path[i]);
	printf("\n");
}

// Print all root to leaf possible path:
void printpathrecur(struct node*root,int path[],int pathlen)
{
	if(root==NULL)
	return;
	
	path[pathlen]=root->num;
	pathlen++;
	
	if(root->left==NULL && root->right==NULL)
	{
		printarr(path,pathlen);
	}
	else
	{
		printpathrecur(root->left,path,pathlen);
		printpathrecur(root->right,path,pathlen);
	}
}

// Print all root to leaf possible path:
void PrinttoPath(struct node*root)
{
	int path[100];
	printpathrecur(root,path,0);
}
int Max(int a,int b)
{
	if(a>b)
	return(a);
	else
	return(b);
}

int Height(struct node*root)
{
	if(root==NULL)
	return(0);
	
	return(1+Max(Height(root->left),Height(root->right)));
}


// Diameter of Tree
int Diameter(struct node*root)
{
	int L_R_Height,Max_Diameter_val;
	int lheight,rheight;
	int Ldia,Rdia;
	
	if(root==NULL)
	return(0);
	
	lheight=Height(root->left);
	rheight=Height(root->right);
	
	L_R_Height = lheight + rheight + 1;
	Max_Diameter_val = 	Max ( Diameter(root->left), Diameter(root->right) );
	
	return(Max(L_R_Height , Max_Diameter_val));
}

// Children Sum property
int isSumProperty(struct node*root)
{
	int ldata,rdata;
	ldata=rdata=0;
	if(root==NULL || root->left==NULL || root->right==NULL)
	return(1);
	
	else
	{
		if(root->left!=NULL)
			ldata=root->left->num;
			
		if(root->right!=NULL)
			rdata=root->right->num;
		
		if(root->num==(ldata+rdata))
			return(1);
		
		else
		return(0);
	}
}

int main(void)
{
	struct node*root=NULL;
	int diameter;
	
	root=insert(root,100);
	root=insert(root,60);
	root=insert(root,40);
	
	root=insert(root,55);
	root=insert(root,45);
	
	root=insert(root,70);
	root=insert(root,30);
	
	root=insert(root,65);
	root=insert(root,35);
	
	PrinttoPath(root);
	
	diameter=Diameter(root);
	printf("\n Diameter of the TREE is: %d \n",diameter);
	
	if(isSumProperty(root)) printf("\nYES Holding Child sum property\n");
	else printf("\nNOT Holding Child sum property\n");
	
	
	return(0);
}

	
	
	
	
	
	
	