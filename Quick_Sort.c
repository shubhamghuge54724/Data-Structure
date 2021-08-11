



#include<stdio.h>
#include<stdlib.h>


// ------------------- FUNCTION TO DISPLAY LIST ----------------------
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

// ---------------------- FUNCTION TO QUICK SORT --------------------------
void Quick_Sort(int* arr, int L, int H)
{
    
    int low,high,pivot,temp;
    pivot = *(arr+L);
    low = L+1;
    high = H;
    while(low <= high)
    {
        while((low <= high) && (*(arr+low) < pivot))
        {
            low++;
        }
        if(low > high)
        {
        	low--;
        	break;
        }
        while(*(arr+high) > pivot)
        {
            high--;
        }
        
        if(low <= high)
        {
            temp = *(arr+low);
            *(arr+low) = *(arr+high);
            *(arr+high) = temp;
            low++;
            high--;
        }
    }
    temp = *(arr+L);
    *(arr+L) = *(arr+high);
    *(arr+high) = temp;
    if(L < high)
    {
        Quick_Sort(arr, L, high-1);
    }
    if(H > low)
    {
        Quick_Sort(arr,high+1,H);
    }
}

// -------------- MAIN FUNCTION ----------------------------
void main()
{
    int* arr , i, n;
    printf("Enter how many elements do you want to enter: ");
    scanf("%d",&n);
    arr =(int*)malloc(sizeof(int)*n);
    printf("Enter array Elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Unsorted List is: ");
    display_list(arr,n);
    Quick_Sort(arr,0,n-1);
    printf("Sorted List is: ");
    display_list(arr,n);
}
