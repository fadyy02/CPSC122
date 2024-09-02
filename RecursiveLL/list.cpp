/*
Name: Fady Youssef
Class: CPSC 122, Section 1
Date Submitted: May 4, 2024
Description: Project13
  */

#include <iostream>
using namespace std;

#include "list.h"

// Non-recursive functions. I have written them for you.
List::List() { head = NULL; }

// destructor needs to be wriiten
List::~List() { Destructor(head); }

bool List::IsEmpty() {
  if (head == NULL)
    return true;
  return false;
}

void List::PutItemH(itemType item) {
  node *tmp = new node;
  tmp->item = item;
  tmp->next = head;
  head = tmp;
  tmp = NULL;
}

itemType List::GetItemH() {
  if (!IsEmpty())
    return head->item;
  return 0;
}

void List::DeleteItemH() {
  node *cur = head;
  head = head->next;
  delete cur;
  cur = NULL;
}

void List::Print(node *cur) {
  if (cur == NULL)
    return;
  else {
    cout << cur->item << endl;
    Print(cur->next);
  }

} // check

void List::Print() {
  // node *cur = head;

  // while (cur != nullptr) {
  //   cur = cur->next;
  //   cout << cur->item << endl;
  // }

  Print(head);
} // done

void List::PrintRev(node *cur) {
  if (cur == NULL)
    return;
  else {
    PrintRev(cur->next);
    cout << cur->item << endl;
  }

} // check

// reason print and get length works is because when we initialize the list, it
// starts at null then next is the item value then next after is the incoming
// item value

void List::PrintRev() {
  // node *cur = head;

  // while (cur != nullptr) {
  //   cout << cur->item << endl;
  //   cur = cur->next;
  // }
  PrintRev(head);
} // goes to next, then prints
 // null[10]next [9]next [8]next [7]next [6]next [5]next null

int List::GetLength(node *cur) {
  if (cur == NULL)
    return 0;
  return GetLength(cur->next) + 1;
} // done

// null[head]next [item1]next [item2]nextl

int List::GetLength() {

  int length = 0;
  node *cur = head;
  // node *cur = lst->head;

  while (cur != nullptr) {
    length++;
    cur = cur->next;
  }

  return length;
} // null[10]next [9]next [8]next [7]next [6]next [5]next null
  // cur is the list parameter
// everytime we reach the else statment, we go to the next part of the list and
// add 1 to the return type

void List::Destructor(node *cur) {
  // if (cur == NULL)
  //   cout << "Destructor isn't running\n";

  while (cur != NULL) {
    Destructor(cur->next);
  }
  delete cur;
  // cout << "Destructor is running" << endl;
} // test
  // null[10]next [9]next [8]next [7]next [6]next [5]next null
  // goes to next, then deletes, and so on

