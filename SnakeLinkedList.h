#ifndef __SNAKE_LINKED_LIST_H__
#define __SNAKE_LINKED_LIST_H__

#include <string>

using namespace std;

/* The declarations of SnakeLinkedList & SnakeListNode below are the same as those
provided in the Lab 8.5 Linked Lists Part 3. You should _not_ need to modify this file.

Put the method definitions for this lab in SnakeListNode.cpp.
*/

class SnakeListNode {
public:
  SnakeListNode(int row, int col, SnakeListNode *nextNode)
      : _row(row), _col(col), _nextNode(nextNode) {}

  int row() const { return _row; };
  int col() const { return _col; };

  SnakeListNode *nextNode() const { return _nextNode; };
  void setNextNode(SnakeListNode *nextNode) { _nextNode = nextNode; };

  string toString() const;

private:
  int _row;
  int _col;
  SnakeListNode *_nextNode;
};


class SnakeLinkedList {
public:
  ~SnakeLinkedList();

  // Create a node with the given row and col attributes and make it the first node in the list.
  void pushFront(int row, int col);

  // Remove the first node in the list, if there is one.
  void popFront();

 // Create a node with the given row and col attributes and make it the last node in the list.
  void pushBack(int row, int col);

  // Remove the last node in the list, if there is one.
  void popBack();

  // Return the number of nodes in the list.
  int length() const;

  // Return a pointer to the first node in the list, nullptr if the list is empty.
  SnakeListNode* head() const { return _head; };

  // Return a pointer to the last node in the list, nullptr if the list is empty.
  SnakeListNode* tail() const;

  // Print the length, the head and tail of the snake on one line/
  // On each subsequent line, print each node
  // Print nodes using the toString method on SnakeListNode
  void printSnake() const;

private:
  SnakeListNode *_head = nullptr;
};


#endif