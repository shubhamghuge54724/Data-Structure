

/*
Title- 4. Find maximum  element from the array

*/



#include<stdio.h>

void main()
{
    int array[20],no_of_elements,i,max;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        max=array[0];
        for(i=0;i<no_of_elements;i++)
        {
            if(array[i]>max)
            {
                max=array[i];
            }
        }
        printf("maximum element is: %d\n",max);
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
