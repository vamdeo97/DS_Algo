#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node*right;
	struct node*down;
};

void insert(struct node**head,int num)
{
	struct node*head_node=(*head);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->num=num;
	newnode->down=head_node;
	(*head)=newnode;
}

void print_vertical(struct node*head)
{
	printf("\nVertical linked list:\n");
	while(head!=NULL)
	{
		printf("%d\n",head->num);
		head=head->down;
	}
	printf("NULL\n");
}

void print_Horizontal(struct node*head)
{
	printf("\nHorizontal Linked list:\n");
	while(head!=NULL)
	{
		printf("->%d",head->num);
		head=head->right;
	}
	printf("->NULL\n");
}

void flatten(struct node**head)
{
	struct node*head_node=(*head);
	struct node*horz,*vert;
	struct node*temp_head,*prev,*del;
	temp_head=head_node;

	if(head_node==NULL)
	{
		printf("\nEmpty link list\n");
		return;
	}

	while(temp_head->right!=NULL)
	{
		horz=temp_head->right;
		vert=temp_head->down;
		prev=temp_head;

		while(vert!=NULL)
		{
			if(vert->num > horz->num)
			{
				prev=horz;
				horz=horz->right;
			}
			else if(vert->num < horz->num)
			{
				vert->right=prev->right;
				prev->right=vert;
				del=vert;
				prev=del;
				vert=vert->down;
				temp_head->down=vert;
				del->down=NULL;
				
			}
		}
		while(temp_head->down==NULL)
		{
			temp_head=temp_head->right;
		}
	}
	while(temp_head->down!=NULL)
	{
		temp_head->right=temp_head->down;
		prev=temp_head;
		temp_head=temp_head->down;

	}
	temp_head->right=NULL;

}




int main(void)
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	struct node*head3=NULL;
	struct node*head4=NULL;
	struct node*head5=NULL;

	insert(&head1,15);
	insert(&head1,14);
	insert(&head1,13);
	insert(&head1,12);
	insert(&head1,11);
	insert(&head1,10);
	printf("\n\n");
	print_vertical(head1);

	insert(&head2,21);
	insert(&head2,20);
	insert(&head2,19);
	insert(&head2,18);
	insert(&head2,17);
	insert(&head2,16);
	printf("\n\n");
	print_vertical(head2);

	insert(&head3,27);
	insert(&head3,26);
	insert(&head3,25);
	insert(&head3,24);
	insert(&head3,23);
	insert(&head3,22);
	printf("\n\n");
	print_vertical(head3);

	insert(&head4,33);
	insert(&head4,32);
	insert(&head4,31);
	insert(&head4,30);
	insert(&head4,29);
	insert(&head4,28);
	printf("\n\n");
	print_vertical(head4);

	head1->right=head2;
	head2->right=head3;
	head3->right=head4;
	head4->right=NULL;
	printf("\n\n");
	print_Horizontal(head1);

	flatten(&head1);

	printf("\n\n");
	print_Horizontal(head1);

	getch();
	return(0);
}











