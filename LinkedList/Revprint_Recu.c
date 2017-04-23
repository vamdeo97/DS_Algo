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
	printf("->NULL");
}

void printreverse(struct node*head)
{
	if(head==NULL)
	return;

	else{
		printreverse(head->n);
		printf("%d ",head->num);
	}
}

int main(void)
{
	struct node*head=NULL;
	insert(&head,19);
	insert(&head,20);
	insert(&head,21);
	insert(&head,22);
	insert(&head,23);
	print(head);
	printf("\nPrint in Reverse Order Recursive way:\n");
	printreverse(head);
	
	return(0);
}
	
	
