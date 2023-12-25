#include<stdio.h>

void swap(int *a, int *b)
{
 	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int arr[],int N,int i)
{
	int lno=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<N && arr[left]>arr[lno])
	{
		lno=left;
	}
	if(right<N && arr[right]>arr[lno])
	{
		lno=right;
	} 
	
	if(lno!=i)
	{
		swap(&arr[i],&arr[lno]);
		heapify(arr,N,lno);
	}  	
}

void heapsort(int arr[],int N)
{
	for(int i=N/2-1;i>=0;i--)
	{
		heapify(arr,N,i);		
	}
	for(int i=N-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);		
	}

}

void display(int arr[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={12,3,9,14,10,18,8,23};
	int N = sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,N);
	printf("Sorted Array:");
	display(arr,N);
}
