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
struct node* Tail(struct node*head,int k)
{
	int count=0;
	while(head!=NULL && count<k)
	{
		count++;
		head=head->n;
	}
	//printf("\n\n\ %dth element is %d",k,head->num);
	return(head);
}

struct node* Reverse(struct node*head,struct node*tail)
{
	struct node*curr=head,*prev=NULL,*next;

	while(curr!=tail)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	return(prev);
}

// Reversal of link list in given chunk size(k)
void Reverse_chunk(struct node**head, int k)
{
	struct node*curr=(*head);
	struct node*rev_head,*tail,*prev_tail,*temp_head;
	int flag=1;

	// When linklist is empty:
	if(curr==NULL)
		return;


	// Loop through the linklist:
	while(curr!=NULL)
	{
		tail=Tail(curr,k);// Tail Function to Find the node after Kth position

		if(tail==NULL)break; // if the link list avlbl is not of chunksize then no reversal

		rev_head=Reverse(curr,tail); // Reversal of the chunk with return of chunk head node
		temp_head=tail;    // head of the next chunk assigned:
		curr->n=temp_head;    // tail of the reversed node linked to the head of the next chunk

		if(flag==1)    // For First chunk make head as head of linklist
		{
			(*head)=rev_head;
			flag=0;
		}

		else   // for next chunk onwards link tail of prev chunk with reversed head of new chunk
		{
			prev_tail->n=rev_head;
		}
		// make the the current node as prev tail and move to other chunk of linklist for reversal
		prev_tail=curr;
		curr=curr->n;
	}
}


















int main(void)
{
	struct node*head=NULL;
	struct node*tail=NULL;
	struct node*rev=NULL;
	
	insert(&head,9);
	insert(&head,8);
	insert(&head,10);
	insert(&head,20);
	insert(&head,30);
	insert(&head,40);
	insert(&head,50);
	insert(&head,60);
	insert(&head,70);
	insert(&head,80);
	insert(&head,90);
	insert(&head,200);
	insert(&head,300);
	insert(&head,400);
	insert(&head,500);
	insert(&head,600);
	insert(&head,700);
	insert(&head,800);
	insert(&head,900);
	print(head);
	printf("\n\nREVERSAL IN CHUNK Iterative:\n\n");
	Reverse_chunk(&head,3);
	print(head);
	
	getch();
	return(0);
}

