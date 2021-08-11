

#include<stdio.h>
#include<stdlib.h>

// ------------ function to display list -----------------
void display_list(int* arr , int n)
{
    int i;
    printf("[");
    for(i=0;i<n;i++)
    {
        printf("%d , ",*(arr+i));
    }
    printf("]\n");
}

// ------------ FUNCTION TO SELECTION SORT --------------------
void selection_sort(int arr[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// ------------------ MAIN FUNCTION -----------------------
void main()
{
    int n, *arr, i,index;
    printf("Enter how many elements do you want to enter in array: ");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Unsorted array is: ");
    display_list(arr, n);
    selection_sort(arr,n);
    printf("Sorted array is: ");
    display_list(arr, n);
    
}











