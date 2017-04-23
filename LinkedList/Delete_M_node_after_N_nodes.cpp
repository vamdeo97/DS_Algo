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

// Deletion of M nodes after N nodes
void Deletion(struct node**head, int m, int n)
{
	struct node*head_node=(*head);
	struct node*tail_node,*end_node,*del,*temp_node;
	int count=0;
	int len = length_of_linklist(head_node);

	if((m+n) <= len)
	{
		tail_node = tail(head_node,n);
		end_node = tail(tail_node->n,m);
		temp_node=tail_node->n;

		while(temp_node->n!=end_node)
		{
			del=temp_node;
			temp_node=temp_node->n;
			free(del);
		}

		tail_node->n=end_node->n;
	}
	else
	{
		printf("\n deltion not posbl \n");
		return;
	}
}

// Deletion of M nodes after N nodes;
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
	printf("\nDeletion of %d nodes after %d nodes:\n",3,4);
	Deletion(&head1,3,4);
	print(head1);

	getch();
	return(0);
}


