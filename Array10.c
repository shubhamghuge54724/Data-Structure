/*
Title- An array consist of Integers. Write a C program to count the number of elements less
than , greater than and equal to zero.

*/ 

#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,less=0,greater=0,equal=0;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        for(i=0;i<no_of_elements;i++)
        {
            if(array[i]<0)
            {
                less++;
            }
            else 
                if(array[i]>0)
                {
                    greater++;
                }
                else
                {
                    equal++;
                }
        }
        printf("less than zero: %d\ngreater than zero: %d\nequals to zero: %d\n",less,greater,equal);
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
