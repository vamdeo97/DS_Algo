#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*n;
};

void removeloop(struct node*,struct node*);

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

struct node* Reverse_new(struct node*head)
{
	struct node*temp=head;
	struct node*prev=NULL,*next;
	
	while(temp!=NULL)
	{
		next=temp->n;
		temp->n=prev;
		prev=temp;
		temp=next;
	}
	return(prev);
}

void Detectloop(struct node*head)
{
	struct node*temp=head;
	struct node*slow,*fast;
	int count=0;
	slow=fast=temp;
	
	while(slow && fast && fast->n)
	{
		slow=slow->n;
		fast=fast->n->n;
		if(slow==fast)
		{
			printf("\nLoop detected loop node is %d:",slow->data);
			removeloop(head,slow);
			count++;
			return;
		}
	}
	printf("\nNO LOOP DETECTED \n");
}

void removeloop(struct node*head, struct node*loopnode)
{
	struct node*temp=head;
	struct node*loop=loopnode;
	struct node*ptr1,*ptr2;
	
	ptr1=temp;
	while(1)
	{
		ptr2=loop;
		while(ptr2->n!=ptr1 && ptr2->n!=ptr2)
		{
			ptr2=ptr2->n;
		}
		
		if(ptr2->n==ptr1)
		{
			break;
		}
		ptr1=ptr1->n;
	}
	ptr2->n=NULL;
}
		

		

int main(void)
{
	struct node* head=NULL;
	struct node*temp;
	insert(&head,50);
	insert(&head,55);
	insert(&head,1);
	insert(&head,65);
	insert(&head,60);
	insert(&head,70);
	insert(&head,1);
	insert(&head,75);
	insert(&head,80);
	insert(&head,85);
	
	//Append Function
	append(&head,200);
	append(&head,300);
	append(&head,400);
	append(&head,500);
	append(&head,100);
	
	
	// Loop Creation in a linklist:
	temp=head;
	while(temp->n!=0)
	{
		temp=temp->n;
	}
	temp->n=head;
	
	/*printf("\nLinklist is:\n");
	print(head);
	
	printf("\nREVERSE Linklist is:\n");
	Reverse(&head);
	print(head);
	
	printf("\nChunk_Reversal\n");
	head = Reverse_chunk(head,2);
	print(head);*/
	
	printf("\nLoop_Detection_FUNCTION\n");
	Detectloop(head);
	printf("\n\n");
	print(head);
	
	
	return(0);
}



