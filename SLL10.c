

/*
Title- 10. Write a C program to sort student information in ascending order according to marks of student using singly linked list.

*/


#include<stdio.h>
#include<stdlib.h>

char* AcceptString();
struct node* CreateNode();
void CreateLinkedList(struct node**);
void DisplayLinkedList(struct node*);
void SortLinkedList(struct node*);
struct student
{
    int roll_no;
    char* name;
    char* address;
    float marks;
};
struct node
{
    struct student s;
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
            case 3: SortLinkedList(first);
                    break;
        }
    }while(choice!=4);
    
}

//  ------------------- FUNCTION TO ACCEPT STRING ---------------------------

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
        scanf("%d",&(newnode -> s.roll_no));
        printf("Enter the Name for student: ");
        newnode->s.name = AcceptString();
        printf("Enter the Address for student: ");
        newnode->s.address = AcceptString();
        printf("Enter the marks for student: ");
        scanf("%f",&(newnode -> s.marks));
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
        printf("\t|\t%d  \t|\t%s\t|\t%s\t|\t%f\t|\n",head->s.roll_no,head->s.name,head->s.address,head->s.marks);
        head = head -> next;
    }
    
}

// ----------------------------- FUNCTION TO SORT LINKED LIST ACCORDING MARKS ----------------------

void SortLinkedList(struct node* head)
{
    struct node* tempnode = NULL;
    struct student temp;
    while(head != NULL)
    {
        tempnode = head->next;
        while(tempnode != NULL)
        {
            if(head->s.marks > tempnode->s.marks)
            {
                temp = head->s;
                head->s = tempnode->s;
                tempnode->s = temp;
            }
            tempnode = tempnode->next;
        }
        head = head->next;
    }
}

 
