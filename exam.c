#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100

// global variable 
struct Globe
{
    char name[MAX];
    int age;
    int mark;
    int grade;
    int count;
};

//Node
struct Node{
    char Name[MAX];
    int age;
    int mark;
    int Grade;
    int index;
    struct Node* next; 
};


//insert in front 
void push(struct Node** head , char name[MAX] , int age , int mark , int Grade , int idx)
{
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   if (newNode != NULL)
   {
    for (int y = 0;newNode->Name[y] == '\0';y++)
    {
        newNode->Name[y] = name[y];
    }
    newNode->age = age;
    newNode->Grade = Grade;
    newNode->index = idx;
    newNode->next = *head;
    *head = newNode;
   }
   

}

// void reverse(struct Node** head)
// {
//     struct Node* prev = NULL;
//     struct Node* curr_Node = *head;

//     while(curr_Node != NULL)
//     {
//         struct Node* cache_Node = curr_Node->next;
//         curr_Node->next = prev;
//         prev = curr_Node;
//         curr_Node = cache_Node;
//     }
//     *head = prev;
// }

//deleting a stduent record
void Delsturec(struct Node** head, int idx)
{
    struct Node *temp = *head, *prev;
 
    if (temp != NULL && temp->index == idx) {
        *head = temp->next;
        free(temp);
        return;
    }
 
    while (temp != NULL && temp->index != idx) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    free(temp);
}
 
void printList(struct Node* head)
{
    int count = 1;
    struct Node* curr = head;
    printf("\n");
    while(curr->next != NULL)
    {
        printf("__________Student number %d __________\n\n", count);
        printf("\tName: %s\n", curr->Name);
        printf("\tName: %d\n", curr->age);
        printf("\tMark: %d\n", curr->mark);
        printf("\tGrade: %d\n", curr->Grade);
        printf("\tStudent Code: %d\n", curr->index);
        curr = curr->next;
        count++;
    }
    printf("\n");
}

//main_func
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof (struct Node));
    int index = 0;

    struct Globe glovari;
    printf("\n\n__________ Welcome to Student Database Program __________\n\n");
    int choice;
    Main:
    printf("1 = input student data , 2 = view student data , 3 = delete student data , 4 = exit\n");
    printf("Your choice: ");
    scanf("%d" , &choice);

    if (choice == 1)
    {
        printf("Enter student numbers you want to add: ");
        scanf("%d", &glovari.count);
        for (int x;x < glovari.count;x++)
        {
            printf("Enter name: ");
            scanf("%s", glovari.name);
            printf("Enter age: ");
            scanf("%d", &glovari.age);
            printf("Enter Mark: ");
            scanf("%d", &glovari.mark);
            printf("Enter Grade: ");
            scanf("%d", &glovari.grade);
            printf("\n");
            index++;
            push(&head , glovari.name , glovari.age , glovari.mark , glovari.grade , index);
            // reverse(&head);
        }
        printList(head);
        goto Main;
    }else if (choice == 2)
    {
        printList(head);
        goto Main;
    }else if (choice == 3)
    {
        printf("enter student code you want to delete: ");
        scanf("%d" , &index);
        Delsturec(&head , index);
        printList(head);
        goto Main;
    }else if (choice == 4)
    {
        return 0;
    }
    
    

}