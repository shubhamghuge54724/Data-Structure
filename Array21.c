/*
Title- Write a C program to sort only even numbers in given array.
Eg.
Input: 45 8 75 29 5 49 56 22 14 497 288 18 2
Output: 45 2 75 29 5 49 8 14 18 497 22 56 288.
than , greater than and equal to zero.

*/ 
 

#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,j,temp;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        for(j=0;j<no_of_elements;j++)
        {
            for(i=j+1;i<no_of_elements;i++)
            {
                if(array[j]%2==0 && array[i]%2==0)
                {
                    if(array[j]>array[i])
                    {
                        temp=array[j];
                        array[j]=array[i];
                        array[i]=temp;
                    }
                }
            }
        }
        printf("array elements are: [");
        for(i=0;i<no_of_elements;i++)
        {
            printf("%d, ",array[i]);
        }
        printf("]\n");
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
