
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
	struct node*temp=(*head);
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=(*head);
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

void append(struct node**head,int num)
{
	struct node* temp=(*head);
	struct node* newnode = (struct node*) malloc(sizeof(struct node));

	newnode->num=num;
	if(temp==NULL)
	{
		newnode->n=NULL;
		*head=newnode;
		return;
	}
	while(temp->n!=NULL)
	{
		temp=temp->n;
	}

	if(temp!=NULL)
		temp->n=newnode;

	newnode->n=NULL;
}

void MergeSortedlinklist(struct node**h1,struct node**h2,struct node**h)
{
	struct node*head1=(*h1);
	struct node*head2=(*h2);
	struct node*head=(*h);

	if(head1==NULL)
	{
		(*h)=head2;
		return;
	}

	if(head2==NULL)
	{
		(*h)=head1;
		return;
	}

	if(head1==NULL && head2==NULL)
	{
		(*h)=NULL;
		return;
	}

	while(head1!=NULL && head2!=NULL)
	{
		if(head1->num <= head2->num)
		{
			append((h),head1->num);
			head1=head1->n;
		}
		if(head2->num <= head1->num)
		{
			append((h),head2->num);
			head2=head2->n;
		}
	}

	if(head1==NULL)
	{
		while(head2!=NULL)
		{
			append((h),head2->num);
			head2=head2->n;
		}
	}

	if(head2==NULL)
	{
		while(head1!=NULL)
		{
			append((h),head1->num);
			head1=head1->n;
		}
	}
}

int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head=NULL;


	insert(&head1,100);
	insert(&head1,90);
	insert(&head1,80);
	insert(&head1,70);
	insert(&head1,60);
	insert(&head1,50);
	insert(&head1,40);
	insert(&head1,30);
	insert(&head1,20);
	insert(&head1,10);
	printf("\n\nFirst link list is:\n");
	print(head1);

	insert(&head2,49);
	insert(&head2,39);
	insert(&head2,29);
	insert(&head2,19);
	insert(&head2,9);
	printf("\n\nSecond linklist is:\n");
	print(head2);

	MergeSortedlinklist(&head1,&head2,&head);
	printf("\n\nMERGED LINKLIST IS:\n\n");
	print(head);

	getch();
	return(0);
}


