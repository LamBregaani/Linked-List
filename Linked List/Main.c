//Program that allows integers to be added or removed from a singly linked
//list

#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

//The total number of options for the user
#define OPTIONS 6

//Display the different options
void PrintMenu()
{
   printf("You have the following options:\n"
          "\t1. Insert item to beginning of list\n"
          "\t2. Insert item to end of list\n"
          "\t3. Insert item into list\n"
          "\t4. Remove item from list\n"
          "\t5. Print list\n"
          "\t6. Quit\n"
   );
}

int main(void)
{
   int option = 0;

   MyLinkedList *list = CreateList();

   //Loop until the given exit input entered
   while (option != OPTIONS)
   {
      PrintMenu();

      int numRecieved = scanf("%d", &option);

      int data, position = 0;

      //Run the function based on the input given
      if (numRecieved == 1 && option > 0 && option <= OPTIONS)
      {
         switch (option)
         {
         case 1:
            //Add
            printf("Input data ");
            scanf("%d", &data);
            InsertFirst(list, data);
            break;

         case 2:
            //Add to end
            printf("Input data ");
            scanf("%d", &data);
            InsertLast(list, data);
            break;

         case 3:
            //Insert
            printf("Insert data ");
            scanf("%d", &data);
            printf("Insert position ");
            scanf("%d", &position);
            int inserted = Insert(list, data, position);
            if (inserted == NULL)
            {
               printf("Failed to insert into list\n");
            }
            break;

         case 4:
            //Remove
            printf("Remove data ");
            scanf("%d", &data);
            int success = RemoveItem(list, data);
            if (!success)
            {
               printf("Data not found\n");
            }
            else
            {
               printf("Data found\n");
            }
            break;

         case 5:
            //Print
            PrintList(list);
            break;

         case 6:
               break;
         }
      }
   }

   return 0;
}
