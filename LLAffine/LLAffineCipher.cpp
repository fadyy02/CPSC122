/*
Team Members: Fady Youssef
Course: CPSC 122
Date Submitted: 3/20/2024
Assignment Name: Project 6
Description Program implements the Affine Cipher
*/

#include <iostream>
using namespace std;

#include "main.h"

// This is the List constructor
List::List() 
{       
 length = 0; // Start with an empty list
 head = NULL; // No items yet, so the head points to nothing
}

// Function to add an item to the beginning of the list
void List::PutItemH(itemType itemIn)
{
 node* tmp = new node; // Create a new storage for the item
 tmp->item = itemIn; // Store the item
 tmp->next = head; // Link the new item to the previous first item
 head = tmp; // Update the head to point to the new item
 length++; // Increase the length of the list
}

// Function to print all items in the list
void List::Print() const
{
 node* cur = head; // Start at the beginning of the list
 while(cur != NULL) // Keep going until the end of the list
  {
   cout << cur->item << endl; // Print the item
   cur = cur->next; // Move to the next item
  }
}

// Function to count how many times a specific item appears in the list
int List::Find(const itemType target) const
 {
   int count = 0; // Start counting from zero
   node* cur = head; // Start at the beginning of the list
   while (cur!=NULL) // Keep going until the end of the list
     {
       if(cur->item == target) // If the current item matches the target
         count++; // Increase the count
       cur=cur->next; // Move to the next item
     }
   return count; // Return the total count
 }

// Function to delete all occurrences of a specific item from the list
int List::DeleteItem(const itemType target)
 {
   int count = 0; // Start counting deleted items from zero
   node* cur = head; // Start at the beginning of the list
   node* prev = NULL; // Initialize a pointer to the previous item

   while(cur != NULL) // Keep going until the end of the list
     {
       if(cur->item == target) // If the current item matches the target
       {
         if(prev == NULL) // If the target is at the beginning of the list
         {
           head = head->next; // Update the head to skip the current item
           delete cur; // Delete the current item
           cur = head; // Move to the new first item
         }
         else // If the target is after the beginning
         {
           prev->next = cur->next; // Update the link to skip the current item
           delete cur; // Delete the current item
           cur = prev->next; // Move to the next item
         }
         count++; // Increase the count of deleted items
         length--; // Decrease the length of the list
       }
       else // If the current item does not match the target
       {
         prev = cur; // Remember this item as the previous one
         cur = cur->next; // Move to the next item
       }
     }
   return count; // Return the total count of deleted items
 }

// Function to get the first item in the list
itemType List::GetItemH() const
 {
  if (head != NULL) // If the list is not empty
   return head -> item; // Return the item stored in the first item
else
    return itemType(); // If the list is empty, return a default item
 }

// Function to delete the first item in the list
 void List::DeleteItemH()
 {
   if (head != NULL) // If the list is not empty
   {
     node* tmp = head; // Remember the first item
     head = head->next; // Update the head to the second item
     delete tmp; // Delete the first item
     length--; // Decrease the length of the list
   }
   else // If the list is empty
     cout << "List is empty" << endl; // Print a message
 }

// Function to check if the list is empty
 bool List::IsEmpty() const
 {
   return (head == NULL); // Return true if the list is empty, false otherwise
 }

// Function to get the length of the list
int List::GetLength() const
 {
   return length; // Return the length of the list
 }

// g++ main.cpp tstFile.cpp -o myList
// ./myList
