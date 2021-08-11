

/*
Title- 10. Write a C program to sort student information in ascending order according to marks of student using singly linked list.

*/


#include<stdio.h>
#include<stdlib.h>

char* AcceptString();
struct node* CreateNode();
void CreateLinkedList(struct node**);
void DisplayLinkedList(struct node*);
void SortLinkedList(struct node**);

struct node
{
    int roll_no;
    char* name;
    char* address;
    float marks;
    struct node* next;
};



void main()
{
    struct node* first = NULL;
    int choice;
    do
    {
        printf("\n1) Create Linked List\n2) Display Linked List\n3) Sort Linked List\n4) Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: CreateLinkedList(&first);
                    break;
            case 2: DisplayLinkedList(first);
                    break;
            case 3: SortLinkedList(&first);
                    break;
        }
    }while(choice!=4);
    
}

// -------------------- FUNCTION TO ACCEPT STRING ---------------------------

char* AcceptString()
{
    int len = 1;
    char ch;
    char* str = NULL;
    str = (char*)malloc(sizeof(char));
    (*str) = '\0';
    scanf(" ");
    scanf("%c",&ch);
    while(ch != '\n')
    {
        len++;
        str = (char*)realloc(str, sizeof(char)+len);
        *(str+(len-2)) = ch;
        *(str+(len-1)) = '\0';
        scanf("%c",&ch);
    }
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
        printf("Enter the Roll No. for student: ");
        scanf("%d",&(newnode -> roll_no));
        printf("Enter the Name for student: ");
        newnode->name = AcceptString();
        printf("Enter the Address for student: ");
        newnode->address = AcceptString();
        printf("Enter the marks for student: ");
        scanf("%f",&(newnode -> marks));
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

void DisplayLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf("\t|\t%d  \t|\t%s\t|\t%s\t|\t%f\t|\n",head->roll_no,head->name,head->address,head->marks);
        head = head -> next;
    }
    
}


// ------------------------ FUNCTION TO SORT LINKED LIST ----------------------------

void SortLinkedList(struct node** head)
{
    struct node *temp1= NULL, *temp2=NULL, *temp=NULL;
    temp1 = *head;
    if(*head == NULL)
    {
        printf("Linked List not Available\n");
    }
    else
    {
        while(temp1->next != NULL)
        {
            temp2 = temp1->next;
            while(temp2->next!=NULL)
            {
                if(temp1->next->marks > temp2->next->marks)
                {
                    temp = temp2->next->next;
                    temp2->next->next = temp1->next->next;
                    temp1->next->next = temp;
                    temp = temp2->next;
                    temp2->next = temp1->next;
                    temp1->next = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        if((*head)->marks > (*head)->next->marks)
        {
            temp, temp1 = *head;
            *head = (*head)->next;
            while(temp1->next != NULL)
            {
                if(temp1->marks < temp->marks && temp1->next->marks >= temp->marks)
                {
                    temp->next = temp1->next;
                    temp1->next = temp;
                }
                temp1 = temp1->next;
            }
            if(temp1->marks < temp->marks)
            {
                temp1->next = temp;
                temp->next = NULL;
            }
        }
        
    }
    
}

