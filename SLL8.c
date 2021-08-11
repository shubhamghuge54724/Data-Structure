

/*
Title- 8. Write a C program to create two linked lists (B and C) from one linked
list(A) one of two(B) contains only even data from (A) and another contains
only odd data from (A).

*/


#include<stdio.h>
#include<stdlib.h>

struct node* CreateNode();
void CreateLinkedList(struct node**);
void EvenOddSeperator(struct node*, struct node**, struct node**);
void DisplayLinkedList(struct node*);

struct node
{
    int data;
    struct node* next;
};



void main()
{
    struct node *first = NULL, *even = NULL, *odd = NULL;
    int choice;
    do
    {
        printf("\n1) Create Linked List\n2) Display Original Linked List\n3) Seperate Even Odd\n4) Display Even Linked List\n5) Display Odd Linked List\n6) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: EvenOddSeperator(first, &even, &odd);
                    break;
            case 4: DisplayLinkedList(even);
                    break;
            case 5: DisplayLinkedList(odd);
                    break;
        }
    }while(choice!=6);
    
}


// ----------------------------------- FUNCTION TO CREATE NODE ------------------------------

struct node* CreateNode()
{
    struct node* newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Sorry,Memory not allocated... Please close the other applications or restart your computer and try again...\n");
    }
    else
    {
        newnode -> next = NULL;
    }
    return newnode;
}

// ------------------- FUNCTION TO JOIN NODES (LINK LIST CREATION) -------------------

void CreateLinkedList(struct node** head)
{
    struct node* newnode = NULL;
    struct node* tempnode = *head;
    newnode = CreateNode();
    if(newnode != NULL)
    {
        printf("Enter the value for newnode: ");
        scanf("%d",&(newnode->data));
    }
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

// ---------------------- FUNCTION TO SEPERATE EVEN ODD ELEMENTS -----------------------------

void EvenOddSeperator(struct node* head, struct node** even, struct node** odd)
{
    struct node* tempnode = NULL;
    while(*even != NULL)
    {
        tempnode = (*even)->next;
        free(*even);
        *even = tempnode;
    }
    while(*odd != NULL)
    {
        tempnode = (*odd)->next;
        free(*odd);
        *odd = tempnode;
    }
    
    if(head == NULL)
    {
        printf("List List not available....\n");
    }
    else
    {
        while(head != NULL)
        {
            
            if((head->data)%2 == 0)
            {
                if(*even == NULL)
                {
                    *even = CreateNode();
                    (*even)->data = head->data;
                    (*even)->next = NULL;
                }
                else
                {
                    tempnode = *even;
// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

                    while(tempnode->next != NULL)
                    {
                        tempnode = tempnode->next;
                    }
                    tempnode->next = CreateNode();
                    tempnode->next->data = head->data;
                    tempnode->next->next = NULL;
                }
            }
            else
            {
                if(*odd == NULL)
                {
                    *odd = CreateNode();
                    (*odd)->data = head->data;
                    (*odd)->next = NULL;
                }
                else
                {
                    tempnode = *odd;
                    while(tempnode->next != NULL)
                    {
                        tempnode = tempnode->next;
                    }
                    tempnode->next = CreateNode();
                    tempnode->next->data = head->data;
                    tempnode->next->next = NULL;
                }
            }
            head = head->next;
        }
    }
    
    
}

// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
}























