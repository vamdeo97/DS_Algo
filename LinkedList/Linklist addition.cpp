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
	printf("->NULL");
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

void Addition_Linklist(struct node**head1,struct node**head2,struct node**head3)
{
	struct node*head_node1=(*head1);
	struct node*head_node2=(*head2);
	int num,carry=0,sum,prev_carry;

	Reverse(&head_node1);
	Reverse(&head_node2);

	while(head_node1!=NULL && head_node2!=NULL)
	{
		prev_carry=carry;
		num = head_node1->num + head_node2->num + prev_carry;
		if(num>10)
		{
			sum=num%10;
			carry=1;
		}
		else if(num<10)
		{
			sum = num;
			carry=0;
		}
		insert(head3,sum);
		head_node1=head_node1->n;
		head_node2=head_node2->n;
	}

	if(head_node1==NULL && head_node2==NULL)
		return;

	if(head_node1==NULL)
	{
		while(head_node2!=NULL)
		{
			num = head_node2->num;
			num=num+carry;
			insert(head3,num);
			head_node2=head_node2->n;
		}
	}

	else if(head_node2==NULL)
	{
		while(head_node1!=NULL)
		{
			num = head_node1->num;
			num=num+carry;
			insert(head3,num);
			head_node1=head_node1->n;
		}
	}
}

// Addition of linklist
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

	insert(&head2,6);
	insert(&head2,7);
	insert(&head2,8);
	insert(&head2,9);
	insert(&head2,1);

	printf("\n\n");
	print(head1);

	printf("\n\n");
	print(head2);

	/*Reverse(&head1);
	Reverse(&head2);

	printf("\n\n");
	print(head1);

	printf("\n\n");
	print(head2);*/

	Addition_Linklist(&head1,&head2,&head3);

	//Reverse(&head3);
	printf("\n\nSUM of linklist:\n\n");
	print(head3);

	getch();
	return(0);
}


