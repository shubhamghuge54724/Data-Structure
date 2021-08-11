

/*
Title- 6. Find the position of given element in the array

*/



#include<stdio.h>

void main()
{
    int array[20],no_of_elements,i,element,pos=0,flag=0;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        printf("enter the element find it's position in array: ");
        scanf("%d",&element);
        for(i=0;i<no_of_elements;i++)
        {
            if(array[i]==element)
            {
                pos++;
                flag=1;
                break;
            }
            pos++;
           
        }
        if(flag==1)
        {
            printf("position of element is: %d\n",pos);
        }
        else
        {
            printf("element not found..\n");
        }
            
        
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}
 
