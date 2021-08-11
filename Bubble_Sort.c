
/*
Title- Bubble Sort

*/ 


#include<stdio.h>
#include<stdlib.h>

// --------------------- FUNCTION TO DISPLAY LIST ----------------------

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

// ------------------ FUNCTION TO SWAP -------------------

void swap_list(int* a1, int* a2)
{
    int temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}


// --------------- FUNCTION TO BUBBLE SORT -----------------------
void bubble_sort(int* arr , int n)
{
    int i,itr,swapped_check;
    for(itr=n;itr>1;itr--)
    {
        swapped_check = 0;
        for(i=0;i<itr-1;i++)
        {
            printf("Comparing elements [ %d , %d ]\n",*(arr+i),*(arr+i+1));
            if(*(arr+i) > *(arr+i+1))
            {
                swapped_check = 1;
                swap_list(arr+i,arr+i+1);
                printf("Swapped elements [ %d , %d ]\n",*(arr+i),*(arr+i+1));
            }
        }
        printf("Iteration %d :",(n+1)-itr);
        display_list(arr,n);
        if(swapped_check == 0)
        {
            break;
        }
    }
}

// ---------------------- MAIN FUNCTION -------------------------
void main()
{
    int *arr ,n,i;
    printf("How many elments do you want to enter in array: ");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int)*n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
    display_list(arr,n);
    bubble_sort(arr,n);
    display_list(arr,n);
}
