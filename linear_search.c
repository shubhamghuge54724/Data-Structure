

#include<stdio.h>
void LinearSearch(int* , int);

// ---------------------- MAIN FUNCTION -------------------
void main()
{
    int arr[10], i, n;
    printf("Enter how many elements Do you want to enter in array: ");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    LinearSearch(arr,n);
}

// -------------------- FUNCTION TO LINEAR SEARCH -----------------------
void LinearSearch(int* arr, int n)
{
    int search,i,flag = 0;
    printf("enter the element to search: ");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(*(arr+i) == search)
        {
            flag = 1;
            printf("Element found at index %d\n",i);
            break;
        }
    }
    if(flag == 0)
    {
        printf("Element not found..\n");
    }
}
