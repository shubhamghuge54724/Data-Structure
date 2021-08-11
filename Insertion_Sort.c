


#include<stdio.h>
#include<stdlib.h>

// ------------------ FUNCTION TO DISPLAY LIST ----------------
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

// ------ FUNCTION TO INSERTION SORT ----------------
void Insertion_Sort(int* arr , int n)
{
    int temp, hole, i;
    for(i=1;i<n;i++)
    {
        temp = *(arr+i);
        hole = i;
        printf("***************************************************************************\n");
        printf("Iterration No. %d\n",i);
        printf("Sorting element is %d\n",temp);
        while(hole > 0 && *(arr+(hole-1)) > temp )
        {
            *(arr+hole) = *(arr+(hole-1));
            hole--;
        }
        *(arr+hole) = temp;
        printf("Sorted elemet Changed Position : ");
        display_list(arr , n);
    }
    printf("***************************************************************************\n");
}
//------------ MAIN FUNCTION -------------------------
void main()
{
    int *arr , i , n;
    printf("Enter how many elements do you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Unsorted List is: ");
    display_list(arr, n);
    Insertion_Sort(arr, n);
    printf("Sorted List is: ");
    display_list(arr, n);
}
