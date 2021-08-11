

/*
Title- 4. Write a C program to print all armstrong numbers from given singly linked list.

*/ 

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* CreateNode();
void CreateLinkedList(struct node**);
void DisplayLinkedList(struct node*);
void PrintArmstrong(struct node*);

void main()
{
    struct node* first = NULL;
    int choice;
    
    do
    {
        printf("\n----------------************************-------------------------\n");
        printf("\n1) Create Linked List\n2) Display Linked List\n3) Print Armstrong Number\n0) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: PrintArmstrong(first);
                    break;
        }
    }while(choice != 0);
}

// -------------------- FUNCTION TO CREATE NODE ---------------------

struct node* CreateNode()
{
    struct node* newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("memory not allocated ..... \n");
    }
    else
    {
        printf("enter data: ");
        scanf("%d",&(newnode->data));
        newnode->next = NULL;
    }
}
// ------------------- FUNCTION TO JOIN NODES (LINK LIST CREATION) -------------------

void CreateLinkedList(struct node** head)
{
    struct node* newnode = NULL;
    struct node* tempnode = *head;
    newnode = CreateNode();
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        while(tempnode->next != NULL)
        {
            tempnode = tempnode->next;
        }
        tempnode->next = newnode;
    }
}
// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf(" -> %d", head->data);
        head = head->next;
    }
}

// --------------------------- FUNCTION TO PRINT ARMSTRONG NUMBER -------------------------

void PrintArmstrong(struct node* head)
{
    int temp1,value,count,sum,mult,i;
    if(head == NULL)
    {
        printf("Linked List Not Created.....\n");
    }
    else
    {
        while(head != NULL)
        {
            
            
            
            // to find the no. of digits in a number
            count = 0;
            temp1 = head->data;
            while(temp1!=0)
            {
                temp1/=10;
                count++;
            }
        //      to find the armstrong value.
            sum=0;
            temp1 = head->data;
            while(temp1!=0)
            {
                value=temp1%10;
                mult=1;
                for(i=1;i<=count;i++)
                {
                    mult*=value;
                }
                sum+=mult;
                temp1/=10;
            }
            if(head->data == sum)
            {
                printf("%d\t",sum);
            }
            head = head -> next;
            }
            printf("\n");    
    }
}
