

/*
Title- 1.Accept the array from user and print it

*/



#include<stdio.h>

void main()
{
    int array[20],no_of_elements,i;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
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
