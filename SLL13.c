

/*
Title- 3. Write a C program to find second highest element in singly linked list.

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
void SecondHeighest(struct node*);

void main()
{
    struct node* first = NULL;
    int choice;
    
    do
    {
        printf("\n----------------************************-------------------------\n");
        printf("\n1) Create Linked List\n2) Display Linked List\n3) Second Heighest Element\n0) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: SecondHeighest(first);
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

// ------------------- FUNCTION TO JOIN NODES (LINK LIST CREATION) -------------------

void CreateLinkedList(struct node** head)
{
    struct node* newnode = NULL;
    struct node* tempnode = *head;
    newnode = CreateNode();
    if(newnode != NULL)
    {
        printf("enter data: ");
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

// ----------------------- FUNCTION TO DISPLAY LINKED LIST -------------------------

void DisplayLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf(" -> %d", head->data);
        head = head->next;
    }
}

// ------------- FUNCTION TO FIND OUT SECOND LAST HEIGHEST NUMBER ------------------------

void SecondHeighest(struct node* head)
{
    struct node *tempnode1=NULL, *tempnode2 = NULL, *tempnode = NULL;
    int temp;
    if(head == NULL)
    {
        printf("Linked List not Created.....\n");
    }
    else if(head->next == NULL)
    {
        printf("Only one element in linked list...\n");
    }
    else
    {
        while(head != NULL)
        {
            tempnode1 = CreateNode();
            if(tempnode1!= NULL)
            {
                tempnode1 -> data = head -> data;
            }
            if(tempnode2 == NULL)
            {
                tempnode2 = tempnode1;
            }
            else
            {
                tempnode = tempnode2;
                while(tempnode -> next != NULL)
                {
                    tempnode = tempnode->next;
                }
                tempnode->next = tempnode1;
            }
            head = head->next;
        }
        head = tempnode2;
        while(head != NULL)
        {
            tempnode = head->next;
            while(tempnode != NULL)
            {
                if(tempnode->data > head->data)
                {
                    temp =tempnode->data;
                    tempnode->data = head -> data;
                    head->data = temp;
                }
                tempnode = tempnode->next;
            }
            head = head->next;
        }
        head = tempnode2;
        for(temp = 1;temp<2;temp++)
        {
            head = head->next;
        }
        printf("Second Heighest element in Linked List is: %d\n", head->data);
    }
    while(tempnode2 != NULL)
    {
        tempnode1 = tempnode2;
        tempnode2 = tempnode2->next;
        free(tempnode1);
        tempnode1 = NULL;
    }
    tempnode2 = head = tempnode = NULL;
}




