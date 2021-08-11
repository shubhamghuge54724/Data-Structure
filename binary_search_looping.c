
#include<stdio.h>
#include<stdlib.h>

// ------------ FUNCTION TO SORT --------------------
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

// ----------------- FUNCTION TO BINARY SEARCH -------------------------
int BinarySearch(int arr[], int n)
{
    int search,first = 0,last = n-1,mid;
    printf("Enter the element to search: ");
    scanf("%d",&search);
    while(first <= last)
    {
        mid = (first + last) / 2;
        if(search == arr[mid])
        {
            return mid;
        }
        else if(arr[mid] < search)
        {
            first = mid + 1;
        }
        else if(arr[mid] > search)
        {
            last = mid - 1;
        }
    }
    return -1;
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
    
    selection_sort(arr,n);
    
    index = BinarySearch(arr, n);
    
    /*printf("Sorted Array is: [");
    for(i=0;i<n;i++)
    {
        printf("%d , ",*(arr+i));
    }
    printf("]\n");*/
    
    if(index != -1)
    {
        printf("Element found at index = %d\n",index);
    }
    else
    {
        printf("Element not found...\n");
    }
}











