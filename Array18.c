/*
Title-Write a program in C to delete an element at desired position from an array.

*/
 


#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,j,temp,pos;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        printf("enter the position from which you want to delete the element: ");
        scanf("%d",&pos);
        if(pos<=no_of_elements)
        {
            for(pos-=1;pos<no_of_elements;pos++)
            {
                array[pos]=array[pos+1];
            }
            no_of_elements--;
            printf("array elements are: [");
            for(i=0;i<no_of_elements;i++)
            {
                printf("%d, ",array[i]);
            }
            printf("]\n");
        }
        else
        {
            printf("you entered wrong position\n");
        }
        
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
 
