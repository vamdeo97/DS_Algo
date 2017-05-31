#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*left;
	struct node*right;
};

struct queue
{
	struct node*data;
	struct queue*next;
};


void enqueue(struct queue**front,struct queue**rear,struct node*root)
{
	struct queue*temp=(*front);
	
	struct queue*newnode=(struct queue*)malloc(sizeof(struct queue));
	
	newnode->data=root;
	newnode->next=NULL;
	
	if(temp==NULL)
	{
		*front=newnode;
		*rear=newnode;
		return;
	}
	else
	{
		(*rear)->next=newnode;
		(*rear)=newnode;
	}
}

void dequeue(struct node**front)
{
	struct queue*temp=(*front);
	
	if(temp==NULL)
	return;
	
	(*front)=temp->next;
	free(temp);
}

int levelorder(struct node*root)
{
	int count=0;
	struct queue*front,*rear;
	front=rear=NULL;
	
	if(root==NULL)
	return(0);
	
	enqueue(&front,&rear,root);
	
	while(front!=NULL)
	{
		printf("%d ",front->data->num);
		
		if(front->data->left!=NULL)
		enqueue(&front,&rear,front->data->left);
		
		if(front->data->right!=NULL)
		enqueue(&front,&rear,front->data->right);
		
		if(front->data->left==NULL && front->data->right==NULL)
		 count=count+1;
		
		dequeue(&front);
	}
	return(count);
}

struct node* newnode(int num)
{
	struct node*Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->num=num;
	Newnode->left=Newnode->right=NULL;
	return(Newnode);
}

struct node*insert(struct node*root,int num)
{
	if(root==NULL)
	{
		root=newnode(num);
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

int main(void)
{
	struct node*root=NULL;
	int size=0;
	
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,15);
	root=insert(root,30);
	root=insert(root,25);
	root=insert(root,40);
	root=insert(root,35);
	root=insert(root,50);
	root=insert(root,45);
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,3);	
	root=insert(root,2);
	
	size=levelorder(root);
	printf("  no of leaf nodes %d",size);
	
	return(0);
}
	
	

	
		
	