
/*
Title- Stack Implimentation using DMA

*/


#include<stdio.h>
#include<stdlib.h>

struct STACK
{
    int data;
    struct STACK *next;
};

// ------------ FUNCTION TO CREATE NEWNODE -----------------------

struct STACK* CreateNode()
{
    struct STACK* newnode = NULL;
    newnode = (struct STACK*)malloc(sizeof(struct STACK));
    if(newnode ==  NULL)
    {
        printf("STACK OVERFLOW.....\n");
    }
    else
    {
        printf("Please enter DATA in stack: ");
        scanf("%d",&(newnode->data));
        newnode->next = NULL;
    }
    return newnode;
}

//  --------------------------- FUNCTION TO PUSH ELEMENT --------------------

void push(struct STACK** top)
{
    struct STACK* newnode = NULL;
    newnode = CreateNode();
    if(*top == NULL)
    {
        *top = newnode;
    }
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
}

// --------------------------- FUNCTION TO CHECK EMPTY STACK -------------------------

void underflow(struct STACK* top)
{
    if(top == NULL)
    {
        printf("Stack is Empty.....\n");
    }
    else
    {
        printf("Stack is not Empty....\n");
    }
}

//  ------------------------- FUNCTION TO POP STACK EMEMENTS ------------------------

void pop(struct STACK** top)
{
    struct STACK* temp = *top;
    if(*top == NULL)
    {
        underflow(*top);
    }
    else
    {
        *top = (*top)->next;
        printf("Popped Element is: %d\n",temp->data);
        free(temp);
        temp = NULL;
    }
}

// --------------------------------- FUNCTION TO DISPLAY STACK REVERSELY ----------------------------

// void display(struct STACK* top)
// {
//     if(top != NULL)
//     {
//         display(top->next);
//         printf("| %d |\n",top->data);
//     }
// }

// --------------------------------- FUNCTION TO DISPLAY STACK ----------------------------

void display(struct STACK* top)
{
    while(top != NULL)
    {
        printf("| %d |\n",top->data);
        top = top->next;
    }
}

// ------------------------ ENTRY POINT FUNCTION -------------------------

void main()
{
    struct STACK* top = NULL;
    int choice;
    do
    {
        printf("\n*********************************\n");
        printf("1. PUSH\n2. POP\n3. UNDERFLOW\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(&top);
                    break;
                
            case 2: pop(&top);
                    break;
                    
            case 3: underflow(top);
                    break;
                    
            case 4: display(top);
                    break;
                    
            case 5: printf("Exiting......\n");
                    break;
                    
            default: printf("Please Enter Proper choice...\n");
            
        }
    }while(choice != 5);
}



