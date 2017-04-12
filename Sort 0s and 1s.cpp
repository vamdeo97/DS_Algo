#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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


void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->n;
	}
}

void SortZeroesOnes(struct node**head,struct node**head1,struct node**head2,struct node**head3)
{
	struct node*head_node=(*head);
	while(head_node!=NULL)
	{
		if(head_node->num==0)
		{
			insert(head1,0);
			head_node=head_node->n;
		}
		else if(head_node->num==1)
		{
			insert(head2,1);
			head_node=head_node->n;
		}
		else if(head_node->num==2)
		{
			insert(head3,2);
			head_node=head_node->n;
		}
		else
		{
			head_node=head_node->n;
		}
	}
}

int main(void)
{
	struct node*head=NULL;
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;
	struct node*head4=NULL;

	struct node*tail1=NULL;
	struct node*tail2=NULL;
	struct node*tail3=NULL;
	
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,0);
	insert(&head,2);
	insert(&head,2);
	insert(&head,0);
	insert(&head,1);
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,0);
	insert(&head,2);
	insert(&head,2);
	insert(&head,0);
	insert(&head,1);
	print(head);

	SortZeroesOnes(&head,&head1,&head2,&head3);
	printf("\n\nSORTED 0's\n\n");
	print(head1);
	printf("\n\nSorted 1's\n\n");
	print(head2);
	printf("\n\nSorted 2's\n\n");
	print(head3);

	head4=head1;

	while(head1->n!=NULL)
	{
		head1=head1->n;
	}
	tail1=head1;

	tail1->n=head2;

	while(head2->n!=NULL)
	{
		head2=head2->n;
	}
	tail2=head2;

	tail2->n=head3;

	while(head3->n!=NULL)
	{
		head3=head3->n;
	}
	tail3=head3;

	tail3->n=NULL;

	printf("\n\n FINAL SORTED LINKLIST\n\n");
	print(head4);

	getch();
	return(0);
}

