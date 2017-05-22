#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*left;
	struct node*right;
};

struct queue
{
	struct node*data;
	struct queue*next;
};

struct node* newnode(int data)
{
	struct node*Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=data;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return(Newnode);
}

struct node* Insert(struct node*root,int data)
{
	if(root==NULL)
		root=newnode(data);
		
	else if(data < root->data)
		root->left = Insert(root->left,data);
	
	else
		root->right = Insert(root->right,data);
	
	return(root);
}

void enqueue(struct queue**front,struct queue**rear,struct node*data)
{
	struct queue*temp=*front;
	struct queue*newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=data;
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

void dequeue(struct queue**front)
{
	struct queue*temp=*front;
	
	if(temp==NULL)
		return;
	
	(*front)=(*front)->next;
	free(temp);
}

void Levelorder(struct node*root)
{
	// Queue Declaration
	struct queue*front=NULL,*rear=NULL;
	
	if(root==NULL) 
		return;
	
	enqueue(&front,&rear,root);
	
	while(front!=NULL)
	{
		printf("%d ",front->data->data);
		
		if(front->data->left!=NULL) 
			enqueue(&front,&rear,front->data->left);
		
		if(front->data->right!=NULL) 
			enqueue(&front,&rear,front->data->right);
		
		dequeue(&front);
	}
}

int main(void)
{
	struct node*root=NULL;
	
	root=Insert(root,50);
	root->left=newnode(200); // Making it BT
	root=Insert(root,40);
	root=Insert(root,45);
	root=Insert(root,30);
	root=Insert(root,35);
	root=Insert(root,20);
	root=Insert(root,25);
	root=Insert(root,60);
	root=Insert(root,70);
	root=Insert(root,80);
	root=Insert(root,90);
	root=Insert(root,55);
	root=Insert(root,65);
	root=Insert(root,75);
	root=Insert(root,85);
	
	Levelorder(root);
	
	//Delete_Tree(root);
	


	return(0);
}

	
	
	