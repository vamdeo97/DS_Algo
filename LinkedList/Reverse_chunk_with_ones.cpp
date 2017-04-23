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
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=(temp);
	(*head)=newnode;
}

void print(struct node*head)
{
	struct node*temp=head;
	printf("\nLINKLIST IS:");
	while(temp!=NULL)
	{
		printf("->%d",temp->num);
		temp=temp->n;
	}
	if(temp==NULL)
	{
		printf("->NULL");
	}
}

struct node* Reverse(struct node*head,struct node*end)
{
	struct node*temp=head;
	struct node*prev=NULL,*next,*end_node=end;
	
	while(temp!=end_node)
	{
		next=temp->n;
		temp->n=prev;
		prev=temp;
		temp=next;
	}
	return(prev);
}

void Reverse_Chunks_WithOne(struct node**head)
{
	struct node*head_node=(*head);
	struct node*temp_head,*node_one,*prev_node,*rev_head;
	int flag=1;
	
	// When Link list is Empty
	if(head_node==NULL)
	{
		printf("\n Empty linklist \n");
		return;
	}
	// When Head node starts with one
	if(head_node->num==1)
	{
		(*head)=head_node;
		prev_node=head_node;
		head_node=head_node->n;
		flag=0;
	}
	// Traversing the linklist to find one's
	temp_head=head_node;
	while(head_node!=NULL)
	{
		if(head_node->num==1)
		{
			node_one=head_node;
			rev_head=Reverse(temp_head,node_one);
			temp_head->n=node_one;
			temp_head=node_one->n;
			
			if(flag)
			{
				(*head)=rev_head;
				 flag=0;
			}
			else
			{
				prev_node->n=rev_head;
			}
			prev_node=node_one;
		}
		head_node=head_node->n;
	}		
}
	
int main(void)
{
	struct node*head=NULL;
	insert(&head,1);
	insert(&head,102);
	insert(&head,103);
	insert(&head,104);
	insert(&head,1);
	insert(&head,105);
	insert(&head,106);
	insert(&head,107);
	insert(&head,1);
	insert(&head,108);
	insert(&head,109);
	insert(&head,110);
	insert(&head,1);
	insert(&head,111);
	insert(&head,112);
	insert(&head,113);
	insert(&head,1);
	print(head);
	
	printf("\n\nREV_CHUNKS_with_ones\n");
	Reverse_Chunks_WithOne(&head);
	print(head);
	
	
	getch();
	return(0);
}