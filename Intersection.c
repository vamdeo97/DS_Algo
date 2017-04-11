#include<stdio.h>
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

void append(struct node**head, int num)
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
	
	

void Intersection(struct node*head1,struct node*head2,struct node**head3)
{
	struct node*head_node3=(*head3);
	struct node*prev=NULL;
	int flag=1;
	
	if(head1==NULL && head2==NULL)
	{
		printf("\nEMPTY LINKLIST\n");
		*head3=NULL;
		return;
	}
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->num==head2->num)
		{
			insert(head3,head2->num);
			head1=head1->n;
			head2=head2->n;
			flag=0;
		}
		else if(head1->num < head2->num)
		{
			head1=head1->n;
		}
		else if(head1->num > head2->num)
		{
			head2=head2->n;
		}
	}
	if(flag)
	printf("\nNO INTERSECTION FOUND:\n");
	
}

	

int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;
		
	printf("\n\n");
	insert(&head1,10);
	insert(&head1,20);
	insert(&head1,30);
	insert(&head1,40);
	insert(&head1,50);
	insert(&head1,60);
	insert(&head1,70);
	insert(&head1,80);
	print(head1);

	printf("\n\n");
	insert(&head2,10);
	insert(&head2,20);
	insert(&head2,30);
	insert(&head2,40);
	insert(&head2,50);
	insert(&head2,60);
	insert(&head2,70);
	insert(&head2,80);
	append(&head2,100);
	print(head2);
	

	Intersection(head1,head2,&head3);	
	printf("\nINTERSECTION CALLED\n");
	
	print(head3);

	
	return(0);
}