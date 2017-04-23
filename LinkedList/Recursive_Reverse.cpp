#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*n;
};

struct node*head=NULL;   // Global declaration of Head

// Insertion in Linklist through Global Head
void insert(int num)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=head;
	head=newnode;
}

// Print through Global Head
void print(struct node*head)
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		printf("->%d",temp->num);
		temp=temp->n;
	}
	printf("->NULL\n\n");
}

// Recursive Reverse Function
void Reverse(struct node*head_node)
{
	// Exit condition:
	if(head_node->n==NULL)
	{
		head=head_node;
		return;
	}
	// Recursive call
	Reverse(head_node->n);

	// Poping out of Recursive function call
	struct node*temp_node=head_node->n;

	temp_node->n=head_node;
	head_node->n=NULL;
}

int main(void)
{
	insert(10);
	insert(30);
	insert(40);
	insert(50);
	print(head);

	Reverse(head);
	print(head);

	getch();
	return(0);
}
