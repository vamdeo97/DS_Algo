#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node*n;
};
// Insert a node
void insert(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=head_node;
	(*head)=newnode;
}

// Append a node:
void Append(struct node**head,int num)
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
	printf("->NULL\n\n");
}

// Reversal of link list:
struct node* Rev(struct node*head)
{
	struct node*curr=head,*prev=NULL,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	return(prev);
}


// Length of link list:
int len(struct node*head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->n;
	}
	return(count);
}

// Chunk reversal:
struct node* rev_chunk(struct node*head,int k)
{
	struct node*prev,*curr,*next;
	prev=curr=next=NULL;
	int count=k;
	curr=head;
	
	while(curr!=NULL && count>0)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
		count--;
	}
	
	if(next!=NULL)
	{
		head->n=rev_chunk(next,k);
	}
	return(prev);
}

// head Deletion in linklist"
void DeleteHead(struct node*head)
{
	struct node*temp=NULL;
	temp=head->n;
	head->num=temp->num;
	head->n=temp->n;
	free(temp);
}

// Deletion of a particular element:
void Delete_element(struct node**head,int num)
{
	struct node*next=NULL,*curr=(*head),*prev=NULL,*del=NULL;
	
	if(curr->num==num)
	{
		(*head)=curr->n;
		free(curr);
		return;
	}
		
	
	while(curr->n!=NULL)
	{
		next=curr->n;
		if(curr->num == num)
		{
			prev->n=next;
			free(curr);
			return;
		}
		prev=curr;
		curr=curr->n;
	}
}
			
struct node* search(struct node*head,int num)
{
	while(head->n!=NULL)
	{
		if(head->num==num)
		{
			printf("\nFound Element in linklist\n\n");
			return(head);
		}
		head=head->n;
	}
	printf("\nNOT FOUND\n");
	return(NULL);
}

struct node* findprev(struct node*head,int num)
{
	struct node*prev=NULL;
	
	while(head!=NULL)
	{
		if(head->num=num)
			return(prev);
		prev=head;
		head=head->n;
	}
	return(NULL);
}

struct node* findnext(struct node*head,int num)
{
	struct node*next=NULL;
	
	while(head->n!=NULL)
	{
		next=head->n;
		if(head->num==num) return(next);
		head=head->n;
	}
	return(NULL);
}

void SwapNodes(struct node**head,int X, int Y)
{
	struct node*prevX,*currX=(*head),*prevY,*currY=(*head);
	
	if(X==Y)			// When x and y both are same
	return;
	
	while(currX && currX->num!=X)		// Find curr and prev for X
	{
		prevX=currX;
		currX=currX->n;
	}
	
	while(currY && currY->num!=Y)		// Finf curr and prev for Y
	{
		prevY=currY;
		currY=currY->n;
	}
	
	if(currX==NULL || currY==NULL)		// If any of them dont exist
	return;
	
	if(prevX!=NULL)			// When X is not head;
		prevX->n=currY;
	else
		(*head)=currY;  	// if X is head Make Y as head:
	
	if(prevY!=NULL)			// when y is not head
		prevY->n=currX;
	else
		(*head)=currX;		// If Y is head make X as head
	
	// Swap the other links for the x and y:
	struct node*temp=currY->n;
	currY->n=currX->n;
	currX->n=temp;
}

int main(void)
{
	struct node*head=NULL;
	struct node*temp=NULL;
	struct node*prev=NULL,*next=NULL;
	int count=0;
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	insert(&head,70);
	Append(&head,80);
	Append(&head,90);
	print(head);
	SwapNodes(&head,30,80);
	print(head);
	

	return(0);
}

	