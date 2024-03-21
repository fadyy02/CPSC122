#include <iostream>
using namespace std;

#include "main.h"

//Constructor
List::List() 
{       
 length = 0;
 head = NULL;
}

//No need to write this function
//List::~List() //this function is written as DeleteItemH()

void List::PutItemH(itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = head;
 head = tmp;
 length++;
}

void List::Print() const
{
 node* cur = head;
 while(cur != NULL)
  {
   cout << cur->item << endl;
   cur = cur->next;
  }
}

 /*
 pre: an instance of List exists and is not empty
 post: returns the number of nodes in the list that stores target 
 */
int List::Find(const itemType target) const
 {
   int count = 0; 
   node* cur = head;
   while (cur!=NULL)
     {
       if(cur->item == target)
         count++;
       cur=cur->next;
     }
   return count;
 }

 /*
 pre:  an instance of List exists and is not empty 
 post: deletes all nodes that store target.  Returns
       the number of nodes deleted 
 */
 int List::DeleteItem(const itemType target)
 {
   int count = 0;
   node* cur = head;
   node* prev = NULL;
   
   while(cur != NULL)
     {
       if(cur->item == target)
       {
         if(prev == NULL)
         {
           head = head->next;
           delete cur;
           cur = head;
         }
         else
         {
           prev->next = cur->next;
           delete cur;
           cur = prev->next;
         }
         count++;
         length--;
       }
       else
       {
         prev = cur;
         cur = cur->next;
       }
     }
   return count;
 }


 /*
 pre: an instance of List exists and is not empty
 post: Returns the contents pointed to by the head of the list 
 */
 itemType List::GetItemH() const
 {
  if (head != NULL)
   return head -> item; 
else
    return itemType();
 }

 /*
 pre: an instance of list exists and is not empty
 post: Node pointed to by head is deleted 
 */
 void List::DeleteItemH()
 {
   if (head != NULL)
   {
     node* tmp = head;
     head = head->next;
     delete tmp; 
     length--;
   }
   else
     cout << "List is empty" << endl;
 }

 //General operations on List,  starting with the easiest  
 /*
 pre: an instance of List exists
 post: returns true if list is empty, false otherwise
 */ 
 bool List::IsEmpty() const
 {
   return (head == NULL);
 }

 /*
 pre: an instance of List exists
 post: returns length of the list 
 */
int List::GetLength() const
 {
   return length;
 }

//g++ main.cpp tstFile.cpp -o myList
// ./myList