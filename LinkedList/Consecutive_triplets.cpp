#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int num;
	struct node*n;
};

void insert(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));

	newnode->num=num;
	newnode->n=head_node;
	(*head)=newnode;
}

void append(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=NULL;
	if(head_node==NULL)
	{
		(*head)=newnode;
		return;
	}
	while(head_node->n!=NULL)
	{
		head_node=head_node->n;
	}
	head_node->n=newnode;
}

void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->n;
	}
	printf("->NULL\n\n");
}

void Reverse(struct node**head)
{
	struct node*head_node=(*head);
	struct node*curr=head_node,*prev=NULL,*next;

	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	(*head)=prev;
}

struct node* tail(struct node*head,int n)
{
	int count=1;
	while(head->n!=NULL && count<n)
	{
		head=head->n;
		count++;
	}
	return(head);
}

int length_of_linklist(struct node*head)
{
	int len=0;
	while(head!=NULL)
	{
		len++;
		head=head->n;
	}
	return(len);
}
// Find Three consecutive triplets
void triplet(struct node*head,int sum)
{
	struct node*curr=head,*next=head->n,*next1=head->n->n;

	while(next1!=NULL)
	{
		if((curr->num + next->num + next1->num) == sum)
		{
			printf("Found triplets %d %d %d",curr->num , next->num , next1->num);
			return;
		}
		curr=next;
		next=next1;
		next1=next1->n;
	}
}

// Find Three consecutive triplets
int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;

	insert(&head1,1);
	insert(&head1,2);
	insert(&head1,3);
	insert(&head1,4);
	insert(&head1,5);
	insert(&head1,6);
	insert(&head1,16);
	insert(&head1,7);
	insert(&head1,8);
	insert(&head1,9);
	insert(&head1,11);
	print(head1);
	triplet(head1,28);
	getch();
	return(0);
}


