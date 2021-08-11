/*
Title- Write a program in C to print all unique elements in an array.

*/
 



#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,j,flag;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        printf("unique elements are : [");
        for(i=0;i<no_of_elements;i++)
        {
            for(j=0;j<no_of_elements;j++)
            {
               if(array[i]==array[j] && i!=j)
               {
                   flag=1;
                   break;
               }
               else
               {
                   flag=0;
               }
            }
            if(flag==0)
            {
                printf("%d, ",array[i]);
            }
        }
        printf("]\n");
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
