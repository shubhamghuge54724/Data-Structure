
/*
Title- 7. Merge two arrays in a single array.

*/


#include<stdio.h>

void main()
{
    int array1[20],array2[20],array3[40],no_of_elements1,no_of_elements2,i,j=0;
    
    
    printf("enter how many elements do you want to enter into the array1(must be < 20): ");
    scanf("%d",&no_of_elements1);
    
    
    printf("enter how many elements do you want to enter into the array2(must be < 20): ");
    scanf("%d",&no_of_elements2);
    
    
    if((no_of_elements1>0 && no_of_elements1<=20) && (no_of_elements2>0 && no_of_elements2<=20))
    {
        
        printf("Enter array1 elements:\n");
        for(i=0;i<no_of_elements1;i++)
        {
            scanf("%d",&array1[i]);
        }
        
        
        printf("Enter array2 elements:\n");
        for(i=0;i<no_of_elements2;i++)
        {
            scanf("%d",&array2[i]);
        }
        
        
        for(i=0;i<no_of_elements1;i++)
        {
            array3[j++]=array1[i];
        }
        
        
        for(i=0;i<no_of_elements2;i++)
        {
            array3[j++]=array2[i];
        }
        
        
        printf("merged elements are: [");
        for(i=0;i<j;i++)
        {
            printf("%d, ",array3[i]);
        }
        printf("]\n");
     
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
    
}
