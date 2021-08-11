
/*
Title- Stack Implimentation using array(statically)

*/

#include<stdio.h>
#define MAX 10

struct STACK
{
    int arr[MAX];
    int top;
};

void init_stack(struct STACK* stack)
{
    stack->top = -1;
}


int overflow(struct STACK* stack)
{
    if(stack->top == (MAX-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int underflow(struct STACK* stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct STACK* stack)
{
    (stack->top)++;
    printf("Enter Data for stack: ");
    scanf("%d",&(stack->arr[stack->top]));
}

void pop(struct STACK* stack)
{
    printf("Popped Element is: %d\n",stack->arr[stack->top]);
    (stack->top)--;
}

void display(struct STACK* stack)
{
    int i;
    for(i=stack->top;i>=0;i--)
    {
        printf("| %d |\n",stack->arr[i]);
    }
}
void main()
{
    int choice,data;
    struct STACK stack;
    init_stack(&stack);
    do
    {
        printf("***************************************************\n");
        printf("1. PUSH\n2. POP\n3. IS UNDERFLOW\n4. IS OVERFLOW\n5. DISPLAY\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(overflow(&stack))
                    {
                        printf("Stack Fulled......!\n");
                    }
                    else
                    {
                        push(&stack);
                    }
                    break;
            case 2: if(underflow(&stack))
                    {
                        printf("Stack is Empty....\n");
                    }
                    else
                    {
                        pop(&stack);
                    }
                    break;
            case 3: if(underflow(&stack))
                    {
                        printf("Stack is Empty....\n");
                    }
                    else
                    {
                        printf("%d positions filled.....\n",stack.top+1);
                    }
                    break;
            case 4: if(overflow(&stack))
                    {
                        printf("Stack is Fulled....\n");
                    }
                    else
                    {
                        printf("%d positions empty.....\n",MAX-(stack.top)-1);
                    }
                    break;
            case 5: if(underflow(&stack))
                    {
                        printf("Stack is empty......\n");
                    }
                    else
                    {
                        display(&stack);
                    }
                    break;
            case 6: printf("Exiting............\n");
                    break;
            default: printf("Wrong choice ... Please enter correct choice...\n");
        }
    }while(choice != 6);
}
