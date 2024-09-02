/*
Team Members: Fady Youssef
Course: CPSC122
Date Submitted: 05/01/2024
Assignment Name: Project 12
*/
#include "queueP.h"
#include <iostream>

PQueue::PQueue() : QueueI() {}

PQueue::PQueue(PQueue *q) : QueueI(q) {}

void PQueue::Enqueue(itemType newItem) {
  // If the queue is empty or newItem is smaller than the head item, insert at
  // head
  if (head == nullptr || newItem < head->item) {
    PutItemH(newItem);
  } else {
    // Find the position to insert newItem
    node *prev = PtrTo(newItem);
    if (prev != nullptr) {
      PutItemT(newItem);
    }
  }
}

node *PQueue::PtrTo(itemType newItem) {
  node *prev = head;
  // Traverse the list to find the insertion point for newItem
  while (prev != nullptr && prev->next != nullptr &&
         prev->next->item < newItem) {
    prev = prev->next;
  }
  return prev;
}
