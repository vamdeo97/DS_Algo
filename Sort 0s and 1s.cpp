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
	int flag=1,count;
	int even=1;

	// When linklist is empty:
	if(curr==NULL)
		return;


	// Loop through the linklist:
	while(curr!=NULL)
	{
		if(even)
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
		even=0;
		}
		else
		{
			prev_tail->n=curr;
			count=1;
			while(count<k)
			{
				count++;
				curr=curr->n;
			}

			even=1;

		}
	}
}


void SortZeroesOnes(struct node**head,struct node**head1,struct node**head2,struct node**head3)
{
	struct node*head_node=(*head);
	while(head_node!=NULL)
	{
		if(head_node->num==0)
		{
			insert(head1,0);
			head_node=head_node->n;
		}
		else if(head_node->num==1)
		{
			insert(head2,1);
			head_node=head_node->n;
		}
		else if(head_node->num==2)
		{
			insert(head3,2);
			head_node=head_node->n;
		}
		else
		{
			head_node=head_node->n;
		}
	}
}


int main(void)
{
	struct node*head=NULL;
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;
	struct node*head4=NULL;

	struct node*tail1=NULL;
	struct node*tail2=NULL;
	struct node*tail3=NULL;
	
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,0);
	insert(&head,2);
	insert(&head,2);
	insert(&head,0);
	insert(&head,1);
	insert(&head,0);
	insert(&head,1);
	insert(&head,1);
	insert(&head,0);
	insert(&head,2);
	insert(&head,2);
	insert(&head,0);
	insert(&head,1);
	print(head);

	SortZeroesOnes(&head,&head1,&head2,&head3);
	printf("\n\nSORTED 0's\n\n");
	print(head1);
	printf("\n\nSorted 1's\n\n");
	print(head2);
	printf("\n\nSorted 2's\n\n");
	print(head3);

	head4=head1;

	while(head1->n!=NULL)
	{
		head1=head1->n;
	}
	tail1=head1;

	tail1->n=head2;

	while(head2->n!=NULL)
	{
		head2=head2->n;
	}
	tail2=head2;

	tail2->n=head3;

	while(head3->n!=NULL)
	{
		head3=head3->n;
	}
	tail3=head3;

	tail3->n=NULL;

	printf("\n\n FINAL SORTED LINKLIST\n\n");
	print(head4);

	getch();
	return(0);
}

