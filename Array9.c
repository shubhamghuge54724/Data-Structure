

/*
Title- Write a C program to find the sum of all the elements of an array.

*/
 
#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,sum=0;
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
            sum=sum+array[i];
        }
        printf("sum of all elements of array is : %d\n",sum);
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
