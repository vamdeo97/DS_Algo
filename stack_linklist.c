#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*n;
};

void insert(struct node**head,int num)
{
	struct node*temp=(*head);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nPUSH:%d\n",num);
	newnode->num=num;
	newnode->n=temp;
	(*head)=newnode;
}

void delete(struct node**head)
{
	struct node*temp=(*head);
	struct node*del=temp;
	
	if(temp==NULL)
	{
		printf("Empty linklist");
		return;
	}
	
	(*head)=temp->n;
	printf("\n\n deleted:%d\n",del->num);
	free(del);
}

void print(struct node*head)
{
	struct node*temp=head;
	printf("\nlinklist:\n");
	while(temp!=NULL)
	{
		printf("->%d",temp->num);
		temp=temp->n;
	}
}

int main(void)
{
	struct node*head=NULL;
	
	insert(&head,11);
	insert(&head,20);
	insert(&head,10);
	insert(&head,13);
	insert(&head,14);
	insert(&head,15);
	print(head);
	
	delete(&head);
	delete(&head);
	delete(&head);
	print(head);
	
	return(0);
}
	
	
	
	