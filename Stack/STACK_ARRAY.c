#include<stdio.h>
#include<stdlib.h>
#define size 10

int arr[size];
int top=-1;

void push(int num)
{
	if(top==size-1)
	{
		printf("\nSTACK OVERFLOW\n");
		return;
	}
	arr[++top]=num;
}

int pop(void)
{
	int num;
	if(top==-1)
	{
		printf("\nUNDERFLOW\n");
		return(0);
	}
	num=arr[top--];
	printf("POP:%d",num);
	return(num);
}

void print(void)
{
	int i;
	printf("\n");
	for(i=top;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
}

int main(void)
{
	push(10);print();
	push(23);print();
	push(45);print();
	push(46);print();
	push(47);print();
	push(48);print();
	push(49);print();
	push(50);print();
	print();
	printf("\n\n");
	pop();print();
	pop();print();
	pop();print();
	pop();print();
	pop();print();
	print();
	
	
	
	return(0);
}
		