//Stack implemented using List and inheritance
#include <iostream>
using namespace std;

#include "stack2.h"

Stack::Stack() : List()
{
}

void Stack::Push(itemType newItem)
{ 
 PutItemH(newItem);
}

itemType Stack::Pop()
{
  itemType poppedItem = GetItemH();
 DeleteItemH();
  return poppedItem;
}

itemType Stack::Peek()
{
 return GetItemH(); 
}


