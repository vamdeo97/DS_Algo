// Print Next greater element:
#include<stdio.h>
#define size 29

void NextGreaterElement(int*head,int len)
{
	int *curr=head;
	int i=0;
	int j=1;
	int next;

	while(i<len)
	{
		if(j==len)
		{
			printf("\nNGE of %d is -1\n",curr[i]);
			i++;
		}
		else
		{
			next=curr[j];
			if(curr[i] < next)
			{
				printf("\nNGE OF %d is %d\n",curr[i],next);
				i++;
				j=i+1;
			}
			else if(curr[i] > next)
				j++;
		}
	}
}

int main(void)
{
	int str[10]= {2,5,7,9,12,1,2,24,43,95};
	int len=sizeof(str)/sizeof(str[0]);
	NextGreaterElement(str,len);
	return(0);
}






















