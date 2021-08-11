

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* CreateNode();
void CreateLinkedList(struct node**);
void SearchElement(struct node*);


void main()
{
    struct node* first = NULL;
    int choice;
    do
    {
        printf("------------------------*****************************-----------------------------");
        printf("\n1) Create Linked List\n2) Search Element\n3) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: SearchElement(first);
                    break;
        }
    }while(choice != 3);
}

// ----------------------------------- FUNCTION TO CREATE NODE ------------------------------

struct node* CreateNode()
{
    struct node* newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Sorry, Memory not allocated..., Please close some other application or restart your computer and try again....");
    }
    else
    {
        printf("Enter the value for newnode: ");
        scanf("%d",&(newnode->data));
        newnode->next = NULL;
    }
    return newnode;
}

// ------------------- FUNCTION TO JOIN NODES (LINK LIST CREATION) -------------------

void CreateLinkedList(struct node** head)
{
    struct node *newnode = NULL,*tempnode = *head;
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

// ----------- FUNCTION TO SEARCH ELEMENT IN LINKED LIST ---------------------
void SearchElement(struct node* head)
{
    int x,flag = 0,count = 0;  
    printf("Enter the element to search: ");
    scanf("%d",&x);
    while(head != NULL)
    {
        count++;
      if(x == (head->data))
      {
          flag = 1;
          break;
      }
      head = head->next;
    }
    if(flag == 1)
    {
        printf("element found at %d position.\n",count);
    }
    else
    {
        printf("element not found in linked list...\n");
    }
}
 
