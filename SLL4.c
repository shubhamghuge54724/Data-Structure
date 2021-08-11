



#include<stdio.h>
#include<stdlib.h>

struct node* CreateNode();
void CreateLinkedList(struct node**);
void DisplayLinkedList(struct node*);
void ReplaceElement(struct node*);

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
        printf("\n--------------------------******************************----------------------------\n");
        printf("1) Create Linked List\n2) Display Linked List\n3) Replace Element\n4) Exit\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: ReplaceElement(first);
                    break;
        }
    }while(choice != 4);
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


// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* tempnode)
{
    printf("Your Linked List is: ");
    while(tempnode != NULL)
    {
        printf(" -> %d",tempnode->data);
        tempnode = tempnode->next;
    }
}

// -------------------- FUNCTION TO REPLACE ELEMENT IN LINKED LIST -----------------------
void ReplaceElement(struct node* head)
{
    int x,flag = 0;
    printf("Enter which element you want to replace: ");
    scanf("%d",&x);
    if(head == NULL)
    {
        printf("Linked List not Created... Please create Linked List..\n");
    }
    else
    {
        while( head != NULL )
        {
            if(x == head->data)
            {
                printf("Please enter new element: ");
                scanf("%d",&x);
                head->data = x;
                flag =1;
                break;
            }
            head = head -> next;
        }
        if(flag ==1)
        {
            printf("Element Replaced Successfully.....\n");
        }
        else
        {
            printf("Element Not found to replace...\n");
        }
    }
}
