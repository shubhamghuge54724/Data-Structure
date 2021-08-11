/*
Title- Write a program in C to count the frequency of each element of an array.

*/
 
 




#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,j,flag=0,count,x;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        printf("frequency of elements is: [");
        for(i=0;i<no_of_elements;i++)
        {
            flag=0;
            count=1;
            x=i-1;
            while(x>=0)
            {
                if(array[i]==array[x])
                {
                    flag=1;
                    break;
                }
                x--;
            }
            if(flag==0)
            {
                for(j=i+1;j<no_of_elements;j++)
                {
                    if(array[i]==array[j])
                    {
                        count++;
                    }
                }
                printf("%d= %d, ",array[i],count);
            }
        }
        printf("]\n");
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
