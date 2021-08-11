/*
Title-Write a program in C to find the maximum and minimum element in an array.

*/
 




#include<stdio.h>
#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,max,min;
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
        min=array[0];
        for(i=0;i<no_of_elements;i++)
        {
            if(array[i]<min)
            {
                min=array[i];
            }
        }
        printf("maximum element is: %d\n",max);
        printf("minimum element is: %d\n",min);
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
