#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*n;
};

// Enqueue operation through Link list
void insert(struct node**head,int num)
{

	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=head_node;
	(*head)=newnode;
}
// Print fhe QUEUE
void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->n;
	}
	printf("->NULL\n\n");
}

// Dequeue operation through Link list
int Delete(struct node*head)
{
	struct node*prev=NULL,*del;
	while(head->n!=NULL)
	{
		prev=head;
		head=head->n;
	}

	prev->n=NULL;
	del=head;
	return(del->num);
	free(del);
}

int main(void)
{
	struct node*head=NULL;

	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	insert(&head,70);
	insert(&head,80);
	insert(&head,90);
	insert(&head,120);
	
	print(head);

	Delete(head);
	Delete(head);
	Delete(head);
	Delete(head);
	Delete(head);

	print(head);

	insert(&head,170);
	insert(&head,180);
	insert(&head,190);
	insert(&head,1120);

	print(head);

	getch();
	return(0);
}




