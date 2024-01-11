#ifndef __SNAKE__
#define __SNAKE__

#include "SnakeLinkedList.h"
#include "GameBoard.h"

class Snake : public SnakeLinkedList {
public:
  Snake();

  int calories() const { return _calories; }
  // Returns whether or not the snake will "crash" if it moves to nextRow,nextCol.
  bool willCrash(const GameBoard *board, int nextRow, int nextCol) const;

  // Returns whether row,col matches the coordinates of one of the snake's nodes.
  bool intersects(int row, int col) const;

  // Sets the tiles on the gameboard corresponding to each of the snake's nodes.
  void setTiles(GameBoard *board) const;

  // Moves the head to nextRow,nextCol and adjusts the tail as needed.
  void step(GameBoard *board, int nextRow, int nextCol);

  bool headIntersects(int row, int col);

  void eat(int calories, Color color);

  

  /*
    It is possible that the Candy discussion will result in a need for one more more candy-related methods
  */

private:
  int _calories = 0;
  Color _color = defaultColor;
  char _headGlyph = '@';
  char _bodyGlyph = 'o';
};

#endif