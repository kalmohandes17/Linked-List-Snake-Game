#include "Snake.h"
#include "Candy.h"

static const int kInitialHeadRow = 5;
static const int kInitialHeadCol = 5;
static const int kInitialLength = 3;

// The default constructor creates a head at a hard-coded initial position.
// It creates kInitialLength-1 more segments to the left of the head.
Snake::Snake() {
  for (int i = 0; i < kInitialLength; i++) {
    pushBack(kInitialHeadRow, kInitialHeadCol - i);
  }
}

// Return true if a snake will intersect with the edge of the board or with
// itself.
bool Snake::willCrash(const GameBoard *board, int nextRow, int nextCol) const {
  if (nextRow == board->rowCount() || nextRow < 0 ||
      nextCol == board->colCount() || nextCol < 0) {
    return true;
  }
  return intersects(nextRow, nextCol);
  // ====> DJH: -1% Great traversal code, but you have the intersects() method about 12 lines of code after this
}

// Return true if any segment of the snake intersects the given row and col.
bool Snake::intersects(int row, int col) const {
  SnakeListNode *curNode = head();

  while (curNode != nullptr) {
    if (curNode->row() == row && curNode->col() == col) {
      return true;
    }
    curNode = curNode->nextNode();
  }
  return false;
}

// Use the GameBoard's setTiles method to place glyphs for every snake segment.
void Snake::setTiles(GameBoard *board) const {
  board->setTileAt(head()->row(), head()->col(), _headGlyph, _color);
  
  SnakeListNode *curNode = head()->nextNode();
  while (curNode != nullptr) {
    board->setTileAt(curNode->row(), curNode->col(), _bodyGlyph, _color);
    curNode = curNode->nextNode();
  }
}

// A snake takes a step by adding a head segment and sometimes removing a tail
// segment. Adding a head and not removing the tail will cause it to grow in
// length.
void Snake::step(GameBoard *board, int nextRow, int nextCol) {
  if (_calories == 0) {
    board->clearTileAt(tail()->row(), tail()->col());
    popBack();
  }
  else {
    --_calories;
  }
  
  pushFront(nextRow, nextCol);
  setTiles(board);
  // ====> DJH: -1% we only need to draw the new head. Just one line here.
  // And if we did want to redraw the whole snake, same point as before: you have setTiles()
  // already written and tested.
}

bool Snake::headIntersects(int row, int col) {
  if (head()->row() == row && head()->col() == col) {
    return true;
  }
  return false;
}

void Snake::eat(int calories, Color color) { 
  _calories += calories; 
  _color = color;
}

