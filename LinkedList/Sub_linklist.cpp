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
struct node* Reverse(struct node*head)
{
	struct node*curr=head;
	struct node*prev=NULL,*next=NULL;

	while(curr!=NULL)
	{
		next=curr->n;
		curr->n=prev;
		prev=curr;
		curr=next;
	}
	return(prev);
}

int length(struct node*head)
{
	int count=0;
	while(head!=NULL)
	{
		head=head->n;
		count++;
	}
	return(count);
}

struct node* subtraction(struct node*head1,struct node*head2)
{
	struct node*head3=NULL;
	struct node*h1=head1,*h2=head2;
	struct node*rev1,*rev2;
	int num1,num2,carry,len1,len2,sub;
	carry=0;

	if(head1==NULL && head2==NULL)
		return;

	len1=length(head1); // length of linklist
	len2=length(head2);

	rev1=Reverse(head1);  // Reverse the link list to get the units and tenth place subtraction
	rev2=Reverse(head2);

	if(len1==len2)			// when both the linklist are of same size
	{
		while(rev1!=NULL && rev2!=NULL)		// perform subtraction untill linklist reaches end
		{
			if(h1->num > h2->num)				// Deciding which number is greater to perform subtraction
			{
				num1=rev1->num;
				num2=rev2->num;
				num1=num1-carry;			// subtracting carry from the number 

				if(num1<num2)
				{
					num1=num1+10;
					carry=1;				// deciding the carry if number is less than the other one
				}
				else
					carry=0;

				sub=(num1-num2);
				insert(&head3,sub);			// Inserting the SUB so that no need of reversal keeping time complexity as well less
				rev1=rev1->n;				// Traversing the linklist further
				rev2=rev2->n;
			}
			if(h2->num > h1->num)			// if the other linklist is greater
			{
				num1 = rev1->num;
				num2 = rev2->num;
				num2 = num2-carry;

				if(num2 < num1)
				{
					num2 = num2+10;
					carry=1;
				}
				else
					carry=0;

				sub=num2-num1;
				insert(&head3,sub);
				rev1=rev1->n;
				rev2=rev2->n;
			}
		}
	}
		if(len1 > len2)							// one linklist is lengthy than the other one
		{
			while(rev1!=NULL && rev2!=NULL)		// traversing till they are of equal length
			{
				num1=rev1->num;
				num2=rev2->num;
				num1=num1-carry;				// perform carry operation on the num

				if(num1 < num2)
				{
					num1 = num1+10;
					carry=1;				// decidig the carry
				}
				else
					carry=0;
				sub=num1-num2;				// sub operation
				insert(&head3,sub);

				rev1=rev1->n;
				rev2=rev2->n;
			}
			while(rev1!=NULL)			// when lengthy linklist only remains 
			{
				num1=rev1->num;
				if(num1==0)
				{
					if(carry==1)		// carry forward of the element
					{
					num1=num1+10;
					num1=num1-carry;
					carry=1;
					}
				}
				else if(num1==1)
				{
					num1=num1-carry;
					carry=1;
				}
				else{
					num1=num1-carry;
					carry=0;
				}
				sub=num1;
				insert(&head3,sub);
				rev1=rev1->n;
			}
		}
		if(len1 < len2)
		{
			while(rev1!=NULL && rev2!=NULL)
			{
				num1=rev1->num;
				num2=rev2->num;
				num2=num2-carry;

				if(num1 > num2)
				{
					num2 = num2+10;
					carry=1;
				}
				else
					carry=0;
				sub=num2-num1;
				insert(&head3,sub);

				rev1=rev1->n;
				rev2=rev2->n;
			}
			while(rev2!=NULL)
			{
				num2=rev2->num;
				if(num2==0)
				{
					if(carry==1)
					{
						num2=num2+10;
						num2=num2-carry;
						carry=1;
					}
				}
				else if(num2==1)
				{
					num2=num2-carry;
					carry=1;
				}
				else{
					num2=num2-carry;
					carry=0;
				}
				sub=num2;
				insert(&head3,sub);
				rev2=rev2->n;
			}
		}
		return(head3);
}

int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;

	insert(&head1,0);
	insert(&head1,0);
	insert(&head1,0);
	insert(&head1,0);
	insert(&head1,9);
	print(head1);

	insert(&head2,1);
	insert(&head2,1);
	insert(&head2,1);
	insert(&head2,1);
	print(head2);

	head3 = subtraction(head1,head2);
	print(head3);

	return(0);
}



