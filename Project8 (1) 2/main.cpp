/*
Team Members: Steph and Fady Youssef
Course: CPSC122
Date Submitted: 3/26/2024
Assignment Name: Project 8
*/

#include <iostream>
using namespace std;

#include "main.h"

ListT::ListT() {
  head = NULL;
  tail = NULL;
  length = 0;
}

ListT::~ListT() { 
  node *current = head;
  while (current != NULL) {
    node *temp = current;
    current = current->next;
    delete temp; 
  }
  
  head = NULL;  // Set head to NULL
  tail = NULL;  // Set tail to NULL
  length = 0;

  cout << "I'm the destructor" << endl;
  Print();
}

void ListT::PutItemH(itemType item) {
  length = 0;
  node *tmp = new node;
  tmp->item = item;
  tmp->next = head;

  head = tmp;
  if (length == 0)
    tail = tmp;
  length++;
}

void ListT::PutItemT(const itemType itemIn) {
  length = 0;
  node *tmp = new node;
  tmp->item = itemIn;
  tmp->next = tail;

  tail = tmp;
  if (length == 0)
    tail = tmp;
  length++;
}

itemType GetItemH() {
  node *head = new node;
  if (head != NULL)
    return head->item;
  else
    return itemType();
}

itemType GetItemT() {
  node *tail = new node;
  if (tail != NULL)
    return tail->item;
  else
    return itemType();
}

void ListT::DeleteItemT() {
  if (tail != NULL) // If the list is not empty
  {
    node *tmp = tail;                  // Remember the first item
    tail = tail->next;                 // Update the tail to the second item
    delete tmp;                        // Delete the first item
    length--;                          // Decrease the length of the list
  } else                               // If the list is empty
    cout << "tail is deleted" << endl; // Print a message
}

void ListT::DeleteItemH() {
  if (head != NULL) // If the list is not empty
  {
    node *tmp = head;                  // Remember the first item
    head = head->next;                 // Update the head to the second item
    delete tmp;                        // Delete the first item
    length--;                          // Decrease the length of the list
  } else                               // If the list is empty
    cout << "Head is deleted" << endl; // Print a message
}

/*
pre:  an instance of List exists and is not empty
post: deletes all nodes that store target.  Returns
      the number of nodes deleted
*/
int ListT::DeleteItem(const itemType target) { 
	int dCount =0; 
	node *curr = head;
	node *prev = NULL;
	node *tmp = curr; 

	if (prev == NULL){
		tail = NULL;
	}
	else if (head == NULL) {
		cout << "List is Empty \n";
	}
	return 0; 
}

int FindItem(const itemType target) {
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
    return -1; // Return true if the list is empty, false otherwise
}

int ListT::GetLength() const { return length; }

void ListT::Print() const {
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
