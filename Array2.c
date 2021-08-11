

/*
Title- 2. Accept the array from user and print it in reverse

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
        no_of_elements--;
        printf("array elements in reverse are: [");
        for(;no_of_elements>=0;no_of_elements--)
        {
            printf("%d, ",array[no_of_elements]);
        }
        printf("]\n");
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
