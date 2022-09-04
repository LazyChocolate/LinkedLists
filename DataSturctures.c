#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node *head);
void insertAfter(struct Node* prev_node , int newData);
void insertFront(struct Node** first_note , int newData);
void insertLast(struct Node* head, int newData);
void reverse(struct Node** head);

int main()
{
    struct Node* first = (struct Node*)malloc(sizeof (struct Node));
    struct Node* second = (struct Node*)malloc(sizeof (struct Node));
    struct Node* third = (struct Node*)malloc(sizeof (struct Node));

    first->data = 10;
    first->next = second;
    
    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;


    insertAfter(first , 15);
    insertFront(&first , 5);
    insertLast(third , 40);

    printList(first);

    reverse(&first);
    printList(first);

}

void printList(struct Node* head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
         printf("%d -> ", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

void insertAfter(struct Node* prev_node , int newData)
{
    if (prev_node == NULL)
    {
       printf("Error 64");
        exit(0);
    }
    struct Node* newNode = (struct Node*)malloc(sizeof (struct Node));
    newNode->data = newData;
    newNode->next = prev_node->next;
    prev_node->next = newNode;

}

void insertFront(struct Node** head_ref, int newData)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error 80");
        exit(0);
    }else{
        newNode->data = newData;
        newNode->next = (*head_ref);
        (*head_ref) = newNode;
    }
    
}

void insertLast(struct Node* head , int newData)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    if (newNode == NULL)
    {
        printf("Error 97");
        exit(0);
    }else{
        newNode->data = newData;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;  
        newNode->next = NULL;  
        
    }
}

void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* curr_Node = *head;

    while(curr_Node != NULL)
    {
        struct Node* cache_Node = curr_Node->next;
        curr_Node->next = prev;
        prev = curr_Node;
        curr_Node = cache_Node;
    }
    *head = prev;
}
