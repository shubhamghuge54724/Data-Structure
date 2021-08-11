


#include<stdio.h>
#include<stdlib.h>

struct node* CreateNode();
void CreateLinkedList(struct node**);
void SortLinkedList(struct node**);
void DisplayLinkedList(struct node*);

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
        printf("\n1) Create Linked List\n2) Sort In Assending Order\n3) Display Linked List\n4) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: SortLinkedList(&first);
                    break;
            case 3: DisplayLinkedList(first);
                    break;
        }
    }while(choice!=4);
    
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

// ------------------------ FUNCTION TO SORT LINKED LIST -------------------------------

void SortLinkedList(struct node** head)
{
    struct node *tempnode1=NULL,*tempnode2=NULL;
    if(*head == NULL)
    {
        printf("Linked List not Created.....\n");
    }
    else
    {
        tempnode1 = *head;
        int temp;
        while(tempnode1 != NULL)
        {
            tempnode2 = tempnode1 -> next;
            while(tempnode2 != NULL)
            {
                if((tempnode1->data) > (tempnode2->data))
                {
                    temp = tempnode1->data;
                    tempnode1->data = tempnode2->data;
                    tempnode2->data = temp;
                }
                tempnode2 = tempnode2->next;
            }
            tempnode1 = tempnode1->next;
        }
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
