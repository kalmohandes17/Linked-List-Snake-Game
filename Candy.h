#ifndef __CANDY_H__
#define __CANDY_H__

#include "GameBoard.h"

class Candy {
public:

  void draw(GameBoard *board) {
    board->setTileAt(_row, _col, _glyph, _color);
  }

  int row() const { return _row; }
  int col() const { return _col; }
  int calories() const { return _calories; }
  char glyph() const { return _glyph; }
  Color color() const { return _color; }

  void setRow(int value) { _row = value; }
  void setCol(int value) { _col = value; }
  void setCalories(int value) { _calories = value; }
  void setGlyph(char value) { _glyph = value; }
  void setColor(const Color& value) { _color = value; }

private:
  int _row = -1;
  int _col = -1;
  int _calories = 0;
  char _glyph = ' ';
  Color _color = defaultColor;
};

#endif