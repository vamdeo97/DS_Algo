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
	printf("->NULL\n\n");
}

int length(struct node*head)
{
	int count=1;
	while(head!=NULL)
	{
		count++;
		head=head->n;
	}
	return(count);
}

struct node* Reverse(struct node*head)
{
	struct node*curr=head;
	struct node*prev=NULL,*next;

	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	return(prev);
}

struct node* Addition(struct node*head1,struct node*head2)
{
	struct node*head3=NULL;
	struct node*h1=head1,*h2=head2;
	struct node*rev1=NULL,*rev2=NULL;
	int sum,num1,num2,carry=0;
	int len1,len2;
	
	if(head1==NULL && head2==NULL)
	return;
	
	len1= length(h1);
	len2= length(h2);
	
	// Reverse to get the addition done from units place:
	rev1=Reverse(head1);
	rev2=Reverse(head2);

	// when both have equal length:
	if(len1==len2)
	{
		while(rev1!=NULL && rev2!=NULL)
		{
			num1=rev1->num;
			num2=rev2->num;
			sum=(num1+num2+carry);
			
			if(sum>9)
			{
				sum=sum%10;
				carry=1;
			}
			else
				carry=0;
			
			insert(&head3,sum);
			rev1=rev1->n;
			rev2=rev2->n;
		}
		if(carry){
			insert(&head3,carry);
		}
	}
	
	// When both the link list are not of equal size:
	if(len1!=len2)
	{
		// Perform addition till both links are non empty:
		while(rev1!=NULL && rev2!=NULL)
		{
			num1=rev1->num;
			num2=rev2->num;
			sum=(num1+num2+carry);
			// calculating the carry part:
			if(sum>9)
			{
				sum=sum%10;
				carry=1;
			}
			else
				carry=0;
			
			insert(&head3,sum);
			
			rev1=rev1->n;
			rev2=rev2->n;
		}
		
		// If first linklist non empty:
		if(rev1!=NULL && rev2==NULL)
		{
			while(rev1!=NULL)
			{
				num1=rev1->num;
				sum=num1+carry;
				if(sum>9){
					sum=sum%10;
					carry=1;
				}
				else{
					carry=0;
				}
				insert(&head3,sum);
				rev1=rev1->n;
			}
			if(carry)// addition of carry at end:
			{
				insert(&head3,carry);
			}
		}
		
		// If second linklist is not empty:
		if(rev2!=NULL && rev1==NULL)
		{
			while(rev2!=NULL)
			{
				num2=rev2->num;
				sum=num2+carry;
				if(sum>9){
					sum=sum%10;
					carry=1;
				}
				else{
					carry=0;
				}
				insert(&head3,sum);
				rev2=rev2->n;
			}
			if(carry)
			{
				insert(&head3,carry);
			}
		}
	}	
	return(head3);
}

int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;
	
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	insert(&head1,9);
	print(head1);

	insert(&head2,5);
	insert(&head2,6);
	insert(&head2,7);
	insert(&head2,8);
	insert(&head2,7);
	insert(&head2,8);
	insert(&head2,7);
	insert(&head2,8);
	print(head2);
	
	printf("\nSUM of the link list is:\n");
	head3=Addition(head1,head2);
	print(head3);
	

	return(0);
}



