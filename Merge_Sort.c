




#include<stdio.h>
#include<stdlib.h>

// ---------------------- FUNCTION TO DISPLAY LIST ----------------------
void display_list(int* arr, int n)
{
    int i;
    printf("[");
    for(i=0;i<n;i++)
    {
        printf("%d , ",*(arr+i));
    }
    printf("]\n");
}

// ---------------------- FUNCTION TO MERGE ARRAY (CONQUER ARRAY)-----------------------
void merge(int* arr, int low, int mid, int high)
{
    int i,j,k = 0, *arr2 = NULL;
    i = low;
    j = mid+1;
    arr2 = (int*)malloc(((high-low)+1)*sizeof(int));
    while(i <= mid && j <= high )
    {
        if(*(arr+i) < *(arr+j))
        {
            *(arr2+k) = *(arr+i);
            i++;
            k++;
        }
        else
        {
            *(arr2+k) = *(arr+j);
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        *(arr2+k) = *(arr+i);
        i++;
        k++;
    }
    while(j <= high)
    {
        *(arr2+k) = *(arr+j);
        j++;
        k++;
    }
    k=0;
    for(i=low;i<=high;i++,k++)
    {
        *(arr+i) = *(arr2+k);
    }
    
}

// ------------------- FUNCTION TO MERGE SORT (DIVIDE ARRAY) ------------------------

void merge_sort(int* arr, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

// --------------------- MAIN FUNCTION -------------------------
void main()
{
    int n, i, *arr = NULL;
    printf("Enter How many elements do you want to enter in Array: ");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
    printf("Unsorted array is: ");
    display_list(arr, n);
    merge_sort(arr,0,n-1);
    printf("Sorted array is: ");
    display_list(arr, n);
    
    
}
