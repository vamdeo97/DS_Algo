#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*n;
};

void insert(struct node**head,int num)
{
	struct node*temp=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->n=(*head);
	(*head)=newnode;
}

void append(struct node**head,int num)
{
	struct node*temp=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	
	if(temp==NULL)
	{
		newnode->n=NULL;
		(*head)=newnode;
		return;
	}
	while(temp->n!=NULL)
	temp=temp->n;
	temp->n=newnode;
	newnode->n=NULL;
}

void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->data);
		head=head->n;
	}
}

void Reverse(struct node**head)
{
	struct node*temp=(*head);
	struct node*prev=NULL,*next;
	
	while(temp!=NULL)
	{
		next=temp->n;
		temp->n=prev;
		prev=temp;
		temp=next;
	}
	(*head)=prev;
}
struct node* Reverse_chunk(struct node*head, int chunk)
{
	struct node*temp=(head);
	struct node*prev=NULL,*next;
	int count=0;
	
	while(temp!=NULL && count<chunk)
	{
		next=temp->n;
		temp->n=prev;
		prev=temp;
		temp=next;
		count++;
	}
	if(next!=NULL)
	{
		head->n=Reverse_chunk(next,chunk);
	}
	return(prev);
}

int main(void)
{
	struct node* head=NULL;
	
	insert(&head,10);
	insert(&head,20);
	insert(&head,40);
	append(&head,100);
	append(&head,200);
	append(&head,300);
	append(&head,400);
	append(&head,500);
	printf("\nLinklist is:\n");
	print(head);
	printf("\nREVERSE Linklist is:\n");
	Reverse(&head);
	print(head);
	
	printf("\nChunk_Reversal\n");
	head = Reverse_chunk(head,2);
	print(head);
	
	
	return(0);
}



