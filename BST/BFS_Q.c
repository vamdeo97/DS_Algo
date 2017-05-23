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

struct node* newnode(int num)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=num;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return(Newnode);
}

 void enqueue(struct queue**front,struct queue**rear,struct node*data)
{
	struct queue*temp=(*front);
	
	struct queue*newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=data;
	newnode->next=NULL;
	
	if(temp==NULL){
		(*front)=newnode;
		(*rear)=newnode;
		return;
	}
	else{
		(*rear)->next=newnode;
		(*rear)=newnode;
	}
}

void dequeue(struct queue**front)
{
	struct node*temp=(*front);
	
	if(temp==NULL)
		return;
	
	(*front)=(*front)->next;
	free(temp);
}

void levelorder(struct node*root)
{
	struct queue*front=NULL,*rear=NULL;
	
	if(root==NULL) return;
	
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

struct node* Insert(struct node*root,int num)
{
	if(root==NULL)
	{
		root=newnode(num);
	}
	else if(num<root->data)
	{
		root->left=Insert(root->left,num);
	}
	else
	{
		root->right=Insert(root->right,num);
	}
	return(root);
}

int main(void)
{
	struct node*root=NULL;
	
	root=Insert(root,50);
	root=Insert(root,60);
	root=Insert(root,30);
	
	root=Insert(root,55);
	root=Insert(root,65);
	root=Insert(root,35);
	
	root=Insert(root,15);
	root=Insert(root,16);
	root=Insert(root,13);
	
	root=Insert(root,51);
	root=Insert(root,61);
	root=Insert(root,31);
	
	levelorder(root);
	
	return(0);
}

	



	
	
	
