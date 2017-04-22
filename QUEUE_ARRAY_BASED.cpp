// QUEUE operation through Array:

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 100
int arr[size];

int front=0;
int rear=-1;

void insert(int x)
{
	if(rear==size-1)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		arr[++rear]=x;
	}
}

int delete_data(void)
{
	if(front==rear+1)
	{
		printf("\nUnderflow\n");
		return(0);
	}
	else
		return(arr[front++]);
}

void print(void)
{
	int i=front;
	for(i;i<rear;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}

int main(void)
{
	insert(10);print();
	insert(20);print();
	insert(30);print();
	insert(40);print();
	insert(50);print();
	insert(60);print();
	insert(70);print();
	insert(80);print();
	insert(90);print();
	insert(100);print();
	insert(110);print();
	insert(120);print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	delete_data();print();
	getch();
	return(0);
}










