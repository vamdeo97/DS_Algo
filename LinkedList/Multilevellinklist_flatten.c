#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*right;
	struct node*down;
};

void insert_right(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->right=head_node;
	newnode->down=NULL;
	(*head)=newnode;
}

void insert_down(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->down=head_node;
	(*head)=newnode;
}

void append_right(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->right=NULL;
	newnode->down=NULL;
	
	if(head_node==NULL)
	{
		(*head)=newnode;
		return;
	}
	while(head_node->right!=NULL)
		head_node=head_node->right;
	head_node->right=newnode;
}	


void append_down(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->down=NULL;
	newnode->right=NULL;
	
	if(head_node==NULL)
	{
		(*head)=newnode;
		return;
	}
	while(head_node->down!=NULL)
		head_node=head_node->down;
	head_node->down=newnode;
}

void display_right(struct node*head)
{
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->right;
	}
	printf("->NULL\n\n");
}

void display_down(struct node*head)
{
	printf("\nVERTICAL LINK LIST\n");
	while(head!=NULL)
	{
		printf("->%d\n",head->num);
		head=head->down;
	}
	printf("\n\n");
}
struct node* FindTail(struct node*head)			// Find tail of linklist
{
	while(head->right!=NULL)
	{
		head=head->right;
	}
	return(head);
}

// Flatten a Multilevel linklist	
void MultilevelFlatten(struct node**head)
{
	struct node*head_node=(*head);
	struct node*tail=NULL,*vert=NULL;
	int count=0;
	
	tail=FindTail(head_node);			// Find tail of linklist
	
	while(head_node!=NULL)
	{
		if(head_node->down!=NULL)		// If Vertical linklist exist
		{
			vert=head_node->down;		
			head_node->down=NULL;		// break the vertical link 
			tail->right=vert;			// Insert vertical linklist at the end
			tail=FindTail(vert);		// Find tail after insertion of vertical linklist
		}
		head_node=head_node->right;		// shift the head node
	}
}

int main(void)
{
	struct node*head=NULL;
	
	insert_right(&head,30);
	insert_right(&head,29);
	insert_right(&head,28);
	insert_right(&head,27);
	insert_right(&head,26);	
	insert_right(&head,25);
	
	append_down(&head,31);
	append_down(&head,32);
	append_down(&head,33);
	append_down(&head,40);
	append_down(&head,41);
	append_down(&head,42);
	
	append_right(&head->down,34);
	append_right(&head->down,35);
	append_right(&head->down,36);
	append_right(&head->down,37);
	append_right(&head->down,38);
	append_right(&head->down,39);
	
	MultilevelFlatten(&head);
	display_right(head);
	
	return(0);
}

