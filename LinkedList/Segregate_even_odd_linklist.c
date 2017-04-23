#include<stdlib.h>
#include<stdio.h>

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
	printf("->NULL");
}



void Segregate_even_odd(struct node**head)
{
	struct node*head_node=(*head);
	struct node*head1=NULL,*h1;
	struct node*head2=NULL;
	struct node*tail1;
	int num1;
	
	while(head_node!=NULL)
	{
		num1=head_node->num;
		
		if(num1%2==0)
		{
			insert(&head2,num1);
		}
		else
		{
			insert(&head1,num1);
		}
		head_node=head_node->n;
	}
	
	printf("\nSegreagation_odd\n");
	print(head1);
	printf("\nSegreagation_even\n");
	print(head2);
	h1=head1;
	
	while(head1->n!=NULL)
	{
		head1=head1->n;
	}
	
	tail1=head1;
	tail1->n=head2;
	printf("\nSEGRGATED LINKLIST:\n");
	print(h1);
}

int main(void)
{
	struct node*head=NULL;
	
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	insert(&head,6);
	insert(&head,7);
	insert(&head,8);
	insert(&head,9);
	print(head);
	Segregate_even_odd(&head);

	return(0);
	
}
			

	
	
	



