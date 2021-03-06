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
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->num=num;
	newnode->n=(*head);
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



struct node* reverse(struct node*head)
{
	struct node*prev=NULL,*next,*curr=head;

	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	return(prev);
}
int lengthoflinklist(struct node*head)
{
	int count=0;

	while(head!=NULL)
	{
		count++;
		head=head->n;
	}
	return(count);
}



int checkPallindrome(struct node*head)
{
	struct node*temp=head,*prev,*mid,*last;
	struct node*slow,*fast;
	struct node*head1,*head2;
	int len;

	slow=fast=temp;

	while(fast && fast->n)
	{
		last=slow;
		slow=slow->n;
		fast=fast->n->n;
	}

	printf("\n\n\n Mid element is %d %d\n\n",last->num,slow->num);
	// Middle element is:
	mid=slow;
	last->n=NULL;
	head1= temp;
	head2 = reverse(mid);

    printf("\n\nThe first half of list is: \n");
	print(head1);
	printf("\n\n");
	printf("\n\n\The second half in reverse is: \n\n\n");
	print(head2);

	len=lengthoflinklist(temp);
	printf("\n length is %d\n",len);

	while(head1!=NULL && head2!=NULL)
	{
		if(head1->num!=head2->num)
		{
			printf("NON PLLINDROME");
			return(0);
		}
		head1=head1->n;
		head2=head2->n;
	}
	printf("\nPALLINDROME\n");
	return(1);
}




int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head=NULL;


	insert(&head1,100);
	insert(&head1,90);
	insert(&head1,80);
	insert(&head1,70);
	insert(&head1,60);
	insert(&head1,50);
	insert(&head1,40);
	insert(&head1,30);
	insert(&head1,20);
	insert(&head1,10);
	printf("\n\nFirst link list is:\n");
	print(head1);

	insert(&head2,1);
	insert(&head2,2);
	insert(&head2,3);
	insert(&head2,4);
	insert(&head2,4);
	insert(&head2,5);
	insert(&head2,6);
	insert(&head2,7);
	insert(&head2,3);
	insert(&head2,2);
	insert(&head2,1);
	printf("\n\nSecond linklist is:\n");
	print(head2);

	checkPallindrome(head2);


	getch();
	return(0);
}


