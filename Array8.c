

/*
Title- 5. Sort the array in ascending or descending order

*/


#include<stdio.h>

void main()
{
    int array[20],no_of_elements,i,j,min,k,x,pos,temp;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        k=-1;
        for(j=0;j<no_of_elements;j++)
        {
            pos=-1;
            i=k+1;
            k=i;
            min=array[i];
            for( ;i<no_of_elements;i++)
            {
                if(array[i]<min)
                {
                    min=array[i];
                }
            }
            for(x=0;x<no_of_elements;x++)
            {
                if(array[x]==min)
                {
                    pos++;
                    break;
                }
                pos++;
           
            }
            temp=array[pos];
            array[pos]=array[k];
            array[k]=temp;
                
        }
        printf("sorted array elements are: [");
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
 
