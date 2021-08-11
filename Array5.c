/*
Title- 5. Sort the array in ascending or descending order

*/


#include<stdio.h>
void main()
{
    int array[]={1,3,2,4,6,5,7,7,56,45,78},i,j,k=-1,pos,x,temp,min;
    for(j=0;j<11;j++)
    {
        i=k+1;
        pos=-1;
        k=i;
        min=array[i];
        for(i;i<11;i++)
        {
            if(array[i]<min)
            {
                min=array[i];
            }
        }
        for(x=0;x<11;x++)
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
    for(i=0;i<11;i++)
    {
        printf("%d, ",array[i]);
    }
    printf("]\n");
        
}
