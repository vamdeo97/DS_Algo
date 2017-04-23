// Check for Balanced Parenthesis using Stack:

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

char arr[size];
int top=-1;

void push(char ch)
{
	if(top==size-1)
	{
		printf("Overflow");
		return;
	}
	arr[++top]=ch;  // Push characters in the Stack
}

char pop(void)
{
	if(top==-1)
	{
		printf("Underflow");
		return(NULL);
	}
	return(arr[top--]); // POP the top element
}

int top_element(void)
{
	return(arr[top]);  // Return the top elememt of the stack
}

int IsEmpty(void)
{
	if(top==-1)
	{
		return(1);    // Return TRUE when empty
	}
	else
	{
		return(0);   // Return FALSE when not empty
	}
}

// Display the Stack Elements
void print(void)
{
	int i=0;
	for(i;i<top;i++)
	{
		printf("-%c-",arr[i]);
	}
}

// To check the Pairing:
int IsPair(char openning , char closing)
{
	if(openning=='(' && closing==')')
		return(1);	// if open and close brace matches return 1:

	else if(openning=='{' && closing=='}')
		return(1);							

	else if(openning=='[' && closing==']')
		return(1);

	return(0);
}

// Check Balanced Parenthesis Function:
int AreParenthesisBalanced(char str[])
{
	int len=strlen(str);
	int i=0;

	for(i=0;i<len;i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			push(str[i]);

		else if(str[i]==')' || str[i]=='}' || str[i]==']')
		{
			if(IsEmpty() || !IsPair(top_element(),str[i]))
			{
				return(0);				// False when Parenthesis not Balanced:
			}
			else
				pop();
		}
	}
	return(IsEmpty()?1:0);
}

int main(void)
{
	char str[15]= {'(','{','[',']','}',')'};
	int boolean;

	boolean=AreParenthesisBalanced(str);

	if(boolean)
		printf("\nBALANCED\n\n");
	else
		printf("\nNON BALANCED\n\n");

	getch();
	return(0);
}






















