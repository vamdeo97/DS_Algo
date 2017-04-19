// Reversal of String using Stack

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10

int top=-1;
char arr[size];

void PUSH(char ch)
{
	if(top==(size-1))
		printf("\n OVERFLOW \n");

	//printf("\nPUSH\n");
	arr[top++]=ch;
}

char POP(void)
{
	if(top==-1)
	{
		printf("\nUNDERFLOW\n");
		return(NULL);
	}
	//printf("\nPOP\n");
	return(arr[--top]);
}

void print(void)
{
	int i;
	for(i=-1;i<top;i++)
		printf("%c\n",arr[i]);
}

int main(void)
{
	int i=0;
	char cha[7];
	PUSH('M');
	PUSH('A');
	PUSH('R');
	PUSH('I');
	PUSH('R');
	PUSH('H');
	PUSH('S');

	for(i=0;i<7;i++)
	{
		cha[i]=POP();
		printf("%c ",cha[i]);
	}

	


	getch();
	return(0);
}