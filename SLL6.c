

/*
Title-  6. Write a C program to print singly linked list in reverse order.

*/

#include<stdio.h>
#include<stdlib.h>

struct node* CreateNode();
void CreateLinkedList(struct node**);
void ReversedLinkedList(struct node*);

struct node
{
    int data;
    struct node* next;
};



void main()
{
    struct node* first = NULL;
    int choice;
    do
    {
        printf("\n1) Create Linked List\n2) Reverse Linked List\n3) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: ReversedLinkedList(first);
                    break;
        }
    }while(choice!=3);
    
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
        printf("Enter the data for newnode: ");
        scanf("%d",&(newnode -> data));
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

//  ------------------ FUNCTION TO REVERSE LINKED LIST ---------------------
void ReversedLinkedList(struct node* tempnode)
{
   if(tempnode != NULL)
    {
        ReversedLinkedList(tempnode->next);
        printf(" -> %d",tempnode->data);
    }
}
