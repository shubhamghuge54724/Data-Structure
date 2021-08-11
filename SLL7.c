

/*
Title- 7. Write a C program to create linked list with multiple strings.

*/

#include<stdio.h>
#include<stdlib.h>

char* AcceptString();
struct node* CreateNode();
void CreateLinkedList(struct node**);
void DisplayLinkedList(struct node*);

struct node
{
    char* str;
    struct node* next;
};



void main()
{
    struct node* first = NULL;
    int choice;
    do
    {
        printf("--------------------------------********************************-------------------------------------------\n");
        printf("\n1) Create Linked List\n2) Display Linked List\n3) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
        }
    }while(choice!=3);
    
}

// ------------------------ FUNCTION TO ACCEPT STRING -------------------

char* AcceptString()
{
    int len = 1;
    char ch;
    char* str = NULL;
    str = (char*)malloc(sizeof(char));
    (*str) = '\0';
    scanf(" ");
    do
    {
        scanf("%c",&ch);
        len++;
        str = (char*)realloc(str, sizeof(char)+len);
        *(str+(len-2)) = ch;
        *(str+(len-1)) = '\0';
    }while(ch != '\n');
    return str;
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
        printf("Enter the string for newnode: ");
        newnode->str = AcceptString();
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


// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* tempnode)
{
    printf("Your Linked List is: \n");
    while(tempnode != NULL)
    {
        printf("%s",tempnode->str);
        tempnode = tempnode->next;
    }
}
