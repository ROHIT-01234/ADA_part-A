# include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int mid, int u)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    
    int size = u - l + 1;
    int b[size];
    
    while (i <= mid && j <= u)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= u)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int z = 0; z < size; z++)
    {
        arr[l + z] = b[z];
    }
}


void mergesort(int arr[], int l, int u)
{
    if(l<u)
    {
        int mid=l+(u-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,u);
        merge(arr,l,mid,u);
    }    
}

void display(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

int main() 
{ 
	int arr[]={5,8,2,3,4,6,9,3}; 
	int arr_size = sizeof(arr) / sizeof(arr[0]); 

	printf("Unsorted Array :\n"); 
	display(arr, arr_size); 

	printf("Sorted Array :\n");
	mergesort(arr, 0, arr_size - 1); 
	display(arr, arr_size); 
}
