//Contains structs for a singly linked list and functions to create a lisy, 
//insert items, remove items, and print the contents


#include <stdlib.h>

//Holds the data and a ptr to the next node in the list
typedef struct
{
   void *next;
   int data;

} Node;

//Holds the first node and the amount of items in the list
typedef struct 
{
   Node *head;

   int count;

} MyLinkedList;

//Creates a new list
MyLinkedList *CreateList();

//Add item to beginning of list
Node *InsertFirst(MyLinkedList *list, int data);

//Add item to end of list
Node *InsertLast(MyLinkedList *list, int data);

//Remove item from list
int RemoveItem(MyLinkedList *list, int position);

//Insert item into list
Node *Insert(MyLinkedList *list, int data, int position);

//Print the list
void PrintList(MyLinkedList *list);
