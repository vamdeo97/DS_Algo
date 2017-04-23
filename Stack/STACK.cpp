// Stack Operation using Link list:

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*n;
};

void PUSH(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=head_node;
	(*head)=newnode;
	printf("\nPUSH->%d\n",num);
}

void print(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->n;
	}
	printf("\n");
}

void POP(struct node**head)
{
	struct node*head_node=(*head);
	struct node*temp,*del;
	if(head_node==NULL)
	{
		printf("\nSTACK UNDERFLOW LINKLIST EMPTY\n");
		return;
	}
	printf("\nPOP ->%d\n",head_node->num);
	del=head_node;
	head_node=head_node->n;
	(*head)=head_node;
	free(del);
}

int main(void)
{
	struct node*head=NULL;

	PUSH(&head,10);print(head);
	PUSH(&head,20);print(head);
	PUSH(&head,30);print(head);
	PUSH(&head,40);print(head);
	PUSH(&head,50);print(head);
	PUSH(&head,60);print(head);
	PUSH(&head,70);print(head);
	POP(&head);print(head);
	POP(&head);print(head);
	POP(&head);print(head);
	POP(&head);print(head);
	POP(&head);print(head);
	POP(&head);print(head);
	
	getch();
	return(0);
}


