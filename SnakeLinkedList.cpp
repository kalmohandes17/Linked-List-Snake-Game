#include "SnakeLinkedList.h"
#include <iostream>
#include <sstream>

/* Put the method definitions from Lab 8.5 "Linked Lists Part 3" here.
*/

string SnakeListNode::toString() const {
  ostringstream oss;
  oss << "(row = " << _row << ", col = " << _col << ')';

  return oss.str();
}

SnakeLinkedList::~SnakeLinkedList() {
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
    SnakeListNode* nextNode = curNode->nextNode();
    delete curNode;
    curNode = nextNode;
  }
}

int SnakeLinkedList::length() const {
  int result = 0;
  SnakeListNode *curNode = _head;
  while (curNode != nullptr) {
    ++result;
    curNode = curNode->nextNode();
  }

  return result;
}

SnakeListNode* SnakeLinkedList::tail() const {
  SnakeListNode* prevNode = nullptr;
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
     prevNode = curNode;
     curNode = curNode->nextNode();
  }

  return prevNode;
}

void SnakeLinkedList::pushFront(int row, int col) {
  _head = new SnakeListNode(row, col, _head);
}

void SnakeLinkedList::popFront() {
  if (SnakeListNode* oldHead = _head) {
    _head = _head->nextNode();
    delete oldHead;
  }
}

void SnakeLinkedList::pushBack(int row, int col) {
   SnakeListNode* newTail = new SnakeListNode(row, col, nullptr);
   if (tail() == nullptr) {
      _head = newTail;
   }
   else {
      tail()->setNextNode(newTail);
   }
}

void SnakeLinkedList::popBack() {
   SnakeListNode* newTail = _head;
   SnakeListNode* oldTail = tail();

    // ====> DJH: Very well done!
   if (newTail == nullptr) {}
   else if (newTail->nextNode() == nullptr) {
      delete newTail;
      _head = nullptr;
   }
   else {
      while (newTail->nextNode() != oldTail) {
         newTail = newTail->nextNode();
      }
      delete newTail->nextNode();
      newTail->setNextNode(nullptr);
   }
}

void SnakeLinkedList::printSnake() const {
  SnakeListNode* curNode = _head;
  int len = length();
  cout << "length = " << len;
  if (len > 1) {
    cout << ", head = " << head()->toString();
    cout << ", tail = " << tail()->toString();
  } if (len == 1) {
    cout << ", head = tail = " << head()->toString();
  }
 cout << endl;

  while (curNode != nullptr) {
    cout << " " << curNode->toString() << endl;
    curNode = curNode->nextNode();
  }

  cout << endl;
}
