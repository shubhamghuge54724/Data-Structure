

/*
Title- 5. Write a C program to sort only even data using singly linked list.
*/


#include<stdio.h>
#include<stdlib.h>

struct node* CreateNode();
void CreateLinkedList(struct node**);
void EvenSeperator(struct node*, struct node**);
void DisplayLinkedList(struct node*);

struct node
{
    int data;
    struct node* next;
};



void main()
{
    struct node *first = NULL, *even = NULL;
    int choice;
    do
    {
        printf("\n1) Create Linked List\n2) Display Original Linked List\n3) Seperate Even\n4) Display Even Linked List\n5) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: EvenSeperator(first, &even);
                    break;
            case 4: DisplayLinkedList(even);
                    break;
        }
    }while(choice!=5);
    
}

// -------------------- FUNCTION TO CREATE NODE ---------------------


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
// ---------------------- FUNCTION TO SEPERATE EVEN NUMBERS ---------------------
void EvenSeperator(struct node* head, struct node** even)
{
    struct node* tempnode = NULL;
    while(*even != NULL)
    {
        tempnode = (*even)->next;
        free(*even);
        *even = tempnode;
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























