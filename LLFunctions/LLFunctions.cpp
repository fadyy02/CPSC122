/*
Team Members: Fady Youssef
Course: CPSC122
Date Submitted: 3/26/2024
Assignment Name: Project 8
*/

#include "main.h"
#include <iostream>

using namespace std;

ListT::ListT() {
  head = NULL;
  tail = NULL;
  length = 0;
}

ListT::~ListT() {
  node *current = head;
  while (current != NULL) 
  {
    node *temp = current;
    current = current->next;
    delete temp;
  }

  head = NULL; // Set head to NULL
  tail = NULL; // Set tail to NULL
  length = 0;

}

void ListT::PutItemH(itemType item) { //
  length = 0;
  node *tmp = new node;
  tmp->item = item;
  tmp->next = head;

  head = tmp;
  if (length == 0)
    tail = tmp;
  length++;
}

void ListT::PutItemT(const itemType itemIn) { //create new node
  node *tmp = new node;
  // Assign the item to the new node
  tmp->item = itemIn;
  //Set the next pointer of the new node to NULL since it is the new tail.
  tmp->next = NULL;
  //If the list is empty, set the head and tail pointers to the new node.
  if (length == 0)
    tail = tmp;
  //If the list is not empty, set the next pointer of the current tail to the new node.
  else
    tail->next = tmp;
  //Set the tail pointer to the new node.
  tail = tmp;
  //Increment the length of the list.
  length++;
}

itemType ListT::GetItemH() const {
  node *currHead = head;
  if (head != NULL) {
    return head->item;
  } else
    return itemType();
}

itemType ListT::GetItemT() const {
  node *currTail = tail;
  if (tail != NULL) {
    return tail->item;
  } else
    return itemType();
}

void ListT::DeleteItemT() {
  if (tail != NULL) // If the list is not empty
  {
    node *tmp = tail; // Remember the first item
    if (head == tail) {
      head = NULL;
      tail = NULL;
    } else if (head != NULL) { // Condition for the first else if
      node *current = head;
      while (current->next != tail) {
        current = current->next;
      }
      tail = current;
      tail->next = NULL;                 // Update the tail to the second item
      delete tmp;                        // Delete the first item
      length--;                          // Decrease the length of the list
    } else {                             // If the list is empty
      cout << "tail is deleted" << endl; // Print a message
    }
  }
}

void ListT::DeleteItemH() {
  if (head != NULL) // If the list is not empty
  {
    node *tmp = head;  // Remember the first item
    head = head->next; // Update the head to the second item

    if (head == NULL) {
      tail = NULL; // Update tail when list becomes empty
    }

    delete tmp;                        // Delete the first item
    length--;                          // Decrease the length of the list
  } else {                             // If the list is empty
    cout << "Head is deleted" << endl; // Print a message
  }
}

/*
pre:  an instance of List exists and is not empty
post: deletes all nodes that store target.  Returns
      the number of nodes deleted
*/
int ListT::DeleteItem(const itemType target) {
  int dCount = 0;
  node *curr = head;
  node *prev = NULL;

  while (curr != NULL) {
    if (curr->item == target) { //if curr mathes target
      if (curr == head) { // move to head
        head = curr->next;
      } else {
        prev->next = curr->next; //else if at end of list 
      }

      if (curr == tail) {
        tail = prev;
      }
      node *tmp = curr;

      curr = curr->next;
      delete tmp; // get rid of given position
      dCount++; // Increment count of deleted item 
    } else { //If the target is after the beginning 
      prev = curr; //Move to the next item
      curr = curr->next;
    }
  }

  return dCount;
}

 // prev->next = curr->next; // Update the link to skip the current item

int ListT::FindItem(const itemType target) const {
  node *head = new node;
  int count = 0;      // Start counting from zero
  node *cur = head;   // Start at the beginning of the list
  while (cur != NULL) // Keep going until the end of the list
  {
    if (cur->item == target) // If the current item matches the target
      count++;               // Increase the count
    cur = cur->next;         // Move to the next item
  }
  return count; // Return the total count
}

bool ListT::IsEmpty() const {
  if (head == NULL)
    return true;
  else
    return false; // Return true if the list is empty, false otherwise
}

int ListT::GetLength() const { return length; }

void ListT::Print() const { //
  node *cur = head;
  while (cur != NULL) {
    cout << cur->item << endl;
    cur = cur->next;
  }
}

// still need to get through the delete items (3 functions)
// write tests for remaining functions
// setup github student and repos for class
// make sure to include comments each step
// git push -u origin main
// git add .
// git commit -m "message"
// git push (on wsl terminal)
//
