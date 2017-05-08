#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define size 10
int arr[size];

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
int SizeofBST(struct node* root)
{
	if(root==NULL)
		return(0);
	else
		return( SizeofBST(root->left) + 1 + SizeofBST(root->right) );
}

int Kthlowestelement(struct node*root,int k)
{
	int count=0;
	int ksmall=INT_MIN;
	struct node*curr=root;
	
	if(k>SizeofBST(root))
	return(-99);
	
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			count++;
			if(count==k)
			ksmall=curr->num;
			curr=curr->right;
		}
		else
		{
			struct node*pre=curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre=pre->right;
			}
			if(pre->right==NULL)
			{
				pre->right=curr;
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				count++;
				if(count==k)
				{
					ksmall=curr->num;
				}
				curr=curr->right;
			}
		}
	}
	return(ksmall);
}

int main(void)
{
	struct node* root=NULL;
	int num;
	root=Insert(root,10);
	root=Insert(root,5);
	root=Insert(root,8);
	root=Insert(root,4);
	root=Insert(root,3);
	num=Kthlowestelement(root,6);
	printf("kth_element:%d",num);
	return(0);
}
		
	
	