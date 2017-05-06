#include<stdio.h>

// Sorted order printing of a given array that represents a BST:
void print_sorted(int arr[],int start,int end)
{
	if(start>end)
	return;
	
	// Recur left nodes:
	print_sorted(arr,start*2+1,end);
	
	printf("->%d",arr[start]);
	
	// Recur Right nodes:
	print_sorted(arr,start*2+2,end);
}

int main(void)
{	
	int arr[]={50,40,60,30,45,55,65,25,35};			// array that represents a BST
	int arr_size=sizeof(arr)/sizeof(arr[0]);		// Size of array
	print_sorted(arr,0,arr_size-1);					
	return(0);
}
