#include<stdio.h>

void selectionsort(int arr[],int n)
{
	for (int i=0; i<n; i++)
	{
		int min=i;
		for (int j=i+1;j<n;j++)
		{
			if (arr[min]>arr[j])
				{
					min=j;	
				}
		}
		if (min!=i)
		{
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;		
		}		
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
	selectionsort(arr,n);
	display(arr,n);
	
}
