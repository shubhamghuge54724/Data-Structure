

/*
Title- 7. Write a C program to check whether strings are Anagram strings or not in given

*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
};
struct node* CreateNode();
void AcceptString(struct node**);
void DisplayLinkedList(struct node*);
void AnagramCheck(struct node*, struct node*);

void main()
{
    struct node *first = NULL, *second = NULL;
    int choice;
    
    do
    {
        printf("\n----------------************************-------------------------\n");
        printf("\n1) Accept String\n2) Display Linked List\n3) Anagram Check\n0) Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter First String: \n");
                    AcceptString(&first);
                    printf("Enter Second String: \n");
                    AcceptString(&second);
                    break;
            case 2: 
                    printf("First String: ");
                    DisplayLinkedList(first);
                    printf("Second String: ");
                    DisplayLinkedList(second);
                    break;
            case 3: AnagramCheck(first, second);
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
    printf("\n");
}

// -------------------- function to accept strings ------------------

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

// --------------------- FUNCTION TO ANAGRAM CHECK -----------------------
void AnagramCheck(struct node* first, struct node* second)
{
    int i = 1,j;
    char temp, *str1 = NULL, *str2 = NULL;
    str1 = (char*)malloc(sizeof(char));
    *str1 = '\0';
    str2 = (char*)malloc(sizeof(char));
    *str2 = '\0';
    while(first != NULL)
    {
        i++;
        str1 = (char*)realloc(str1,sizeof(char)*i);
        *(str1+(i-2)) = first->data;
        *(str1+(i-1)) = '\0';
        first = first->next;
    }
    i=1;
    while(second != NULL)
    {
        i++;
        str2 = (char*)realloc(str2,sizeof(char)*i);
        *(str2+(i-2)) = second->data;
        *(str2+(i-1)) = '\0';
        second = second->next;
    }
    i=0;
    if(strlen(str1) == strlen(str2))
    {
        while(*(str1+i) != '\0')
        {
            j = i+1; 
            while(*(str1+j) != '\0')
            {
                if(*(str1+i) > *(str1+j))
                {
                    temp =*(str1+i);
                    *(str1+i)= *(str1+j);
                    *(str1+j) = temp;
                }
                j++;
            }
            i++;
        }
        i=0;
        while(*(str2+i) != '\0')
        {
            j = i+1; 
            while(*(str2+j) != '\0')
            {
                if(*(str2+i) > *(str2+j))
                {
                    temp =*(str2+i);
                    *(str2+i)= *(str2+j);
                    *(str2+j) = temp;
                }
                j++;
            }
            i++;
        }
        i = strcmp(str1,str2);
    }
    else
    {
        i=1;
    }
    if(i==0)
    {
        printf("Strings are Anagram Strings...\n");
    }
    else
    {
        printf("Strings are not Anagram Strings...\n");
    }
}
