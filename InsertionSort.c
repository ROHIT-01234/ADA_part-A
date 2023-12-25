#include<stdio.h>

void insertionsort(int arr[],int n)
{
	int temp;
	for (int i=0; i<n; i++)
	{
		temp=arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>=temp)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
				
	}
}

void display(int arr[],int n)
{
	printf("Sorted Array : ");
	for (int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[]={5,6,10,1,4,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted Array: ");
	for(int i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
	insertionsort(arr,n);
	display(arr,n);
	
}
