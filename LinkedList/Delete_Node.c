#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*n;
};

void _del_lesser_nodes(struct node*);

void insert(struct node**head , int num)
{
	struct node*temp=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=temp;
	(*head) = newnode;
}

void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->n;
	}
}

void Reverse(struct node**head)
{
	struct node*curr=*head;
	struct node*prev=NULL,*next;
	
	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	(*head)=prev;
}

void del_lesser_nodes(struct node**head)
{
	Reverse(head);
	_del_lesser_nodes(*head);
	Reverse(head);
}

void _del_lesser_nodes(struct node*head)
{
	struct node*curr=head;
	struct node*max=head;
	struct node*temp;
	
	while(curr!=NULL && curr->n!=NULL)
	{
		if(curr->n->num < max->num)
		{
			temp=curr->n;
			curr->n=temp->n;
			free(temp);
		}
		else
		{
			curr=curr->n;
			max=curr;
		}
	}
}
		
int main(void)
{
	struct node*head=NULL;
	
	// Dec Order
	/*insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	insert(&head,70);
	insert(&head,80);
	insert(&head,90);*/
	
	// Random Input:
	/*insert(&head,3);
	insert(&head,2);
	insert(&head,6);
	insert(&head,5);
	insert(&head,11);
	insert(&head,10);
	insert(&head,15);
	insert(&head,12);*/
	
	// Inc Order
	insert(&head,90);
	insert(&head,80);
	insert(&head,70);
	insert(&head,60);
	insert(&head,50);
	insert(&head,40);
	insert(&head,30);
	
	
	printf("\nOriginal Linklist:\n");
	print(head);
	
	//printf("\nREVERSE LINKLIST:\n");
	//Reverse(&head);
	//print(head);
	
	printf("\nDelete_Left_Node_CALL:\n");
	del_lesser_nodes(&head);
	print(head);
	
	
	return(0);
	
}