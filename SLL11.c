

/*
Title- 1.Write a C program to print all Strong number from the given linked list.

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
void DisplayStrong(struct node*);

void main()
{
    struct node* first = NULL;
    int choice;
    
    do
    {
        printf("\n----------------************************-------------------------\n");
        printf("\n1) Create Linked List\n2) Display Linked List\n3) Print Strong Number\n0) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: DisplayStrong(first);
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

// ------------- FUNCTION TO DISPLAY STRONG NUMBERS --------------------

void DisplayStrong(struct node* head)
{
    int element,value,sum,fact;
    if(head == NULL)
    {
        printf("Linked List not Created....\n");
    }
    else
    {
        while(head != NULL)
        {
            element = head->data;
            sum=0;
            while(element!=0)
            {
                value=element%10;
                fact=1;
                while(value>=1)
                {
                    fact*=value;
                    value--;
                }
                sum+=fact;
                element/=10;
            }
            if(sum==head->data)
            {
                printf("%d\t",head->data);
            }
            head = head -> next;
        }
        printf("\n");
    }

}
