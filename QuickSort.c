#include<stdio.h>
 int divide(int arr[],int low,int high)
{
	int p=arr[high];
	int i=(low-1);
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=p)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;			
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;

	return (i+1);
		
}

void quicksort(int arr[],int low, int high)
{
	if(low<high)
	{
		int d=divide(arr,low,high);
		quicksort(arr,low,d-1);
		quicksort(arr,d+1,high);
	}	
}


void display(int arr[],int len)
{
	printf("Sorted Array : ");
	for (int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
}

void main()
{
	int arr[]={5,8,2,3,4,6,9,3};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted Array : ");
	for(int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	quicksort(arr,0,len-1);
	display(arr,len);
}
