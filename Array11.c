/*
Title- Write a C program that return the positions of the pallindrome element in array.
than , greater than and equal to zero.

*/ 


#include<stdio.h>
void main()
{
    int array[20],no_of_elements,i,a,n;
    printf("enter how many elements do you want to enter into the array(must be < 20): ");
    scanf("%d",&no_of_elements);
    if(no_of_elements>0 && no_of_elements <=20)
    {
        printf("Enter array elements:\n");
        for(i=0;i<no_of_elements;i++)
        {
            scanf("%d",&array[i]);
        }
        printf("position of palindrome elements are: [");
        for(i=0;i<no_of_elements;i++)
        {
            n=array[i];
            a=n%10;
            n=n/10;
            while(n!=0)
            {
                a=a*10+(n%10);
                n=n/10;
            }
            if(array[i]==a)
            {
                printf("%d, ",i+1);
            }
        }
        printf("]\n");
    }
    else
    {
        printf("sorry, you have entered wrong no_of_elements.\n" );
    }
}


// j=no_of_elements-1;
//         
//         for(i=0;i<=j;i++)
//         {
//             printf("%d\n",j);
//             printf("%d\n",array[i]);
//             printf("%d\n",array[j]);
//             if(array[i]!=array[j])
//             {
//                 flag=1;
//                 break;
//             }
//             j--;
//             
//         }
//         if(flag!=1)
//         {
//             printf("palindrome element is: %d\n",array[--i]);
//         }
//         else
//         {
//             printf("array is not palindrome.\n");
//         }
