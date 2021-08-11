/*
Title-Write a program in C to find the second largest element in an array..

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
        for(j=0;j<no_of_elements;j++)
        {
            for(i=j+1;i<no_of_elements;i++)
            {
                if(array[j]<array[i])
                {
                    temp=array[j];
                    array[j]=array[i];
                    array[i]=temp;
                }
            }
        }
        printf("second largest element in array is: %d\n",array[1]);
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
 
 
