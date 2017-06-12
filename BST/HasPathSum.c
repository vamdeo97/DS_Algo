#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node*left;
	struct node*right;
};

struct node* newnode(int num)
{
	struct node*Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->num=num;
	Newnode->left=Newnode->right=NULL;
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
	else
	{
		root->right=Insert(root->right,num);
	}
	return(root);
}

void Inorder(struct node*root)
{
	if(root==NULL)
	return;
	
	else{
		Inorder(root->left);
		printf("%d ",root->num);
		Inorder(root->right);
	}
}

// Check for Root to leaf path Sum:
int ispathsum(struct node*root,int num)
{
	if(root==NULL)
	return(num==0);
	
	else{
		int ans=0;
		int subsum=num-root->num;
		
		if(subsum==0 || root->left==NULL || root->right==NULL)
		return(1);
		
		if(root->left)
		ans= ans || ispathsum(root->left,subsum);
		
		if(root->right)
		ans= ans || ispathsum(root->right,subsum);
		
		return(ans);
	}
}

			
		
		
		
	
	

int main(void)
{
	struct node*root=NULL;
	root=Insert(root,50);
	root=Insert(root,40);
	root=Insert(root,60);
	root=Insert(root,70);
	root=Insert(root,30);
	Inorder(root);
	
	int num=ispathsum(root,120);
	if(num==0)
	printf("NO");
	else
	printf("YES");
	
	return(0);
}



	