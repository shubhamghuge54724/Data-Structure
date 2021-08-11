

/*
Title- 6. Write a C program to accept string with multiple spaces and print count of
number character from string in given Singly linked list.

*/ 

#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
};
struct node* CreateNode();
void AcceptString(struct node**);
void DisplayLinkedList(struct node*);
void NumberCount(struct node*);

void main()
{
    struct node* first = NULL;
    int choice;
    
    do
    {
        printf("\n----------------************************-------------------------\n");
        printf("\n1) Accept String\n2) Display Linked List\n3) Count NUmber Characters\n0) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: AcceptString(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: NumberCount(first);
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
        newnode->next = NULL;
    }
}



// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
}

// ----------------- FUNCTION TO ACCEPT STRING -------------------

void AcceptString(struct node** head)
{
    struct node *newnode = NULL, *tempnode = NULL;
    printf("Enter the String: ");
    scanf(" ");
    do
    {
        newnode = CreateNode();
        if( newnode != NULL)
        {
            scanf("%c",&(newnode->data));
        }
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            tempnode = *head;
            while(tempnode->next!= NULL)
            {
                tempnode = tempnode->next;
            }
            tempnode->next = newnode;
        }
    }while((newnode->data) != '\n');
}

// ----------- FUNCTION TO COUNT NUMBERS IN STRING -----------------
void NumberCount(struct node* head)
{
    int count = 0;
    while(head != NULL)
    {
        if(head->data >= 48 && head->data <= 57 )
        {
            count++;
        }
        head = head->next;
    }
    printf(" Total Number Characters In Given String Is: %d\n",count);
}
