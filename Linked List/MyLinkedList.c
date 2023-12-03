//Contains structs for a singly linked list and functions to create a lisy, 
//insert items, remove items, and print the contents

#include "MyLinkedList.h"

//Creates a new list object
MyLinkedList *CreateList()
{
   MyLinkedList *list = NULL;

   list = malloc(sizeof(MyLinkedList));

   if (list == NULL)
   {
      return NULL;
   }

   //Initialize default values
   list->head = NULL;
   list->tail = NULL;
   list->count = 0;

   return list;
}

//Inserts an item at the beginning of the list
Node *InsertFirst(MyLinkedList *list, int data)
{
   return Insert(list, data, 0);
}

//Inserts an item at the end of the list
Node *InsertLast(MyLinkedList *list, int data)
{
   printf("Position %d", list->count);
   return Insert(list, data, list->count);
}

//Insert item into the given positon
Node *Insert(MyLinkedList *list, int data, int position)
{
   Node *current = list->head;

   //Check that the position is valid
   if (position < 0 || position > list->count)
   {
      printf("Position does not exist in list\n");
      return NULL;
   }

   //Alocate new node
   Node *node = malloc(sizeof(Node));

   if (node == NULL)
   {
      printf("Failed to allocate memeory for node");
      return NULL;
   }

   //If list is empty
   if (list->head == NULL)
   {
      node->data = data;
      list->head = node;
      node->next = NULL;
   }
   //Special case where the position is the first and the lists's head
   //variable needs to be modified
   else if (position == 0)
   {
      node->data = data;
      node->next = list->head;
      list->head = node;
   }
   else
   {
      for (int i = 0; i < position - 1 && current != NULL; i++)
      {
         current = current->next;
      }

      node->data = data;

      node->next = current->next;

      current->next = node;
   }

   list->count++;

   return node;
}

//Remove item from the list
int RemoveItem(MyLinkedList *list, int position)
{
   Node *current = list->head, *prev = list->head;

   //Check that the position is valid
   if (position < 0 || position > list->count)
   {
      printf("Position does not exist in list\n");
      return NULL;
   }

   //Special case where the position is the first and the lists's head
   //variable needs to be modified
   if (position == 0)
   {
      list->head = current->next;
      free(current);
      current = NULL;
   }
   else
   {
      for (int i = 0; i < position; i++)
      {
         prev = current;
         current = current->next;

      }

      prev->next = current->next;

      free(current);
      current = NULL;
   }

   list->count--;

   return 0;
}

//Print the items in the list
void PrintList(MyLinkedList *list)
{
   Node *current = list->head;
   printf("Total Items: %d\n", list->count);

   while (current != NULL)
   {
      printf("%d->", current->data);
      current = current->next;
   }

   printf("\n");
   return;
}