// Circular array Implementation

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 105

int arr[size];

int front=-1;
int rear=-1;

void insert(int num)
{

	if(rear==(size-1) && front==0 || rear+1==front)
	{
		printf("\nOverflow\n");
	}
	else if(front==-1)
	{
		rear=front=0;
	}
	else if(rear==size-1)
	{
		rear=0;
	}
	else
		rear++;

	arr[rear]=num;
}

int delte_data(void)
{
	int x=0;

	if(front==-1)
		printf("Underflow");
	else
	{
		x=arr[front];

		if(front==rear)
		{
			front=rear=-1;
		}
		else if(front==size-1)
		{
			front=0;
		}
		else
			front++;
	}
	return(x);
}

void print(void)
{
	int i= front;
	for(i;i<rear;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}

int main(void)
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);
	insert(21);
	insert(11);
	insert(13);
	insert(24);
	insert(26);
	insert(27);
	print();

	delte_data();
	delte_data();
	print();

	insert(17);
	insert(22);
	print();

	getch();
	return(0);
}











