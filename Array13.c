/*
Title- Write a C program to copy the elements of one array into another array.
than , greater than and equal to zero.
)
*/ 

#include<stdio.h>
void main()
{
    int array1[20],array2[20],no_of_elements,i,sum=0;
    printf("enter how many elements do you want to enter into the array1(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array1 elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array1[i]);
        }
        for(i=0;i<no_of_elements;i++)
        {
            array2[i]=array1[i];
        }
        printf("array2 elements are: [");
        for(i=0;i<no_of_elements;i++)
        {
            printf("%d, ",array2[i]);
        }
        printf("]\n");
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
