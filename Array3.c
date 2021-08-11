
/*
Title- 3. Search the given element in the array.

*/


#include<stdio.h>

void main()
{
    int array[17]={1,2,3,4,5,6,7,45,12,23,42,123,345,675,0,9,8},element,i,flag=1;
    printf("enter the element to search the element in array: ");
    scanf("%d",&element);
    for(i=0;i<17;i++)
    {
        if(array[i]==element)
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        printf("element found in array \n");
    }
    else
    {
        printf("element not found in array \n");
    }
}
 
 
