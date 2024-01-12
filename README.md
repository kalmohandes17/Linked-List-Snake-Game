# Linked-List-Snake-Game

Instructions

Snake Game Specification

The Snake Game is nearly as old as computer graphics. In this game, players control a snake, represented as a sequence of glyphs, navigating it around a fixed-size board. It's easy at first, because the board is mostly blank, aside from a short snake and morsels of candy. The challenge is, as the snake eats candy, it grows longer and longer, eventually filling many of the locations on the board. Snakes that bump into themselves or the edges of the board lose, so the game gets tougher as the snake gets longer.



In the image above, the player's snake is shown early in the game. Its head and body segments are depicted as a sequence of @ signs. A piece of candy lies just to the right of the head. The player eats this candy by moving the head right by two columns. The piece of candy is particularly yummy, because it contains 6 calories. When the snake eats it, the snake absorbs those calories. Snakes convert calories to new segments, so for the next 6 turns, the snake grows by one segment per turn.



In the image above, the snake has eaten the candy. As soon as the candy disappears, a new candy appears elsewhere on the board. That new candy has a random position that does not intersect the snake, and it has a random caloric value (7, this time). The player's job now is to steer the ever-lengthening snake to the next piece of candy.



Notice now that the player's snake is 13 segments long, 6 longer than its length when it ate the last candy. The game continues, getting tougher as the snake is left with less room to maneuver.

Candy Specification

The snake game periodically must create a piece of candy on the board for the snake to eat. This candy must meet these requirements:

It needs to represent the candy's location (row, col) selected at random
It needs to represent the candy's calories 1-9 selected at random
It needs to ensure the candy's location is in bounds and not on top of the snake.
Some coordination between the game control code in main(), the Snake class, and the candy must result in the snake gaining the candy's calories.
Steps

0. Participate in the Candy Design Discussion.

I've begun a discussion on Canvas where you may collaborate in the design of the snake's food, which we call "candy" for no particular reason. When that discussion concludes, these instructions will be updated to reflect the design decisions made by the participating students.

1. Complete The Three Linked List Labs (seriously!)

The week 8 labs provide step-by-step support for creating a SnakeLinkedList. This is a large part of the code needed in SnakeLinkedList.cpp. Do these labs first. If done well, the code you create for the labs should just drop in to SnakeLinkedList.cpp.

2. Implement Snake, a Subclass of SnakeLinkedList

The Snake class is a subclass of SnakeLinkedList. It will inherit all of your good work from the labs and add methods specific to the snake game. Declarations and comments describing these methods are provided in Snake.h and Snake.cpp.

Isn't subclassing great? With it, you're able to inherit every line of your (somewhat generic) linked list lab code adding only snake-game specific logic. We could have used templates to make the SnakeLinkedList even more general, creating an Anything LinkedList. Feel free to try this after you get the project working.

3. Get it Working Without Candy

After completing steps 1 & 2 you should be able to run the game and move the snake around the board. Pre-candy, there will be nothing, yet, for the snake to eat, so it will not grow in length. Even before there's food on the board, consider adding a command key to the switch statement that simulates the snake getting a meal, perhaps growing for a few turns afterwards. If you get this far, your project will be in very good shape to complete. The remaining work will be to add the food you designed in the Canvas discussion.

4. Implement the Candy Design

Our Canvas discussion concluded with the idea of two classes, one representing candy, which we'll call Candy, and one that produces Candy, which I suggest we call CandyMaker. Read more about that deliberation on Canvas.

Candy.h

This will declare and define the Candy class. Candy is mostly data, with only a draw method. Most of the interesting logic proposed in our online design discussion suggests code that is better placed in a CandyMaker class.

Ordinarily, we would code a separate cpp for this class, but there's only one non-trivial method. Use this header file as-is.

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

CandyMaker.h

This class is responsible for producing Candy with random values for its position, calories, glyph, and color. The outline of the class provided can be used as-is. Your job for this assignment is to implement the newCandy method().

Ordinarily, we would code a separate cpp for this class, but we're making an exception to the standard to accommodate the student-generated design step.

#ifndef __CANDY_MAKER_H__
#define __CANDY_MAKER_H__
#include "Candy.h"
#include "Snake.h"
#include <random>
static const int kCandyMakerSeed = 3278;
class CandyMaker {
public:
  // This constructor takes board dimensions and an optional random seed.
  // A "seed" is used to initialize a random number generator so that it
  // produces the same random sequence from run to run. Using a constant
  // seed often helps with debugging games, so we can recreate conditions
  // that must be tested. Use it as-is.
  CandyMaker(int rowCount, int colCount, unsigned int seed = random_device{}()) : _rowCount(rowCount), _colCount(colCount), _generator(seed) {}
  // This method returns a random integer uniformly distributed between
  // a min and a max (excluding the max). Uniform distribution means that
  // every number in the given range is equally likely. Use it as is:
  int random(int min, int max) {
    uniform_int_distribution<int> uniform(min, max-1);
    return uniform(_generator);
  }
  /*
  Provide an implementation of newCandy. Return a Candy instance meeting
  the following requirements:
  1) The row and col must be in bounds on the board.
  2) The row and col must not intersect with any part of the snake. The
     simplest technique to satisfy this requirement is to loop until an
     acceptable position is found.
  3) The calories should be between 1 and 9 calories, (including 9)
  4) The glyph should be a digit '1' to '9', matching the calories
  5) The color should be an int between 1 and 7 (including 7), corresponding to the
     GameBoard color enum
  (Note that the random method is inclusive of the minimum bound and exclusive of the maximum,
  so a caller wishing for a number from x to y, including y, should call random(x,y+1); )
  */
  Candy newCandy(const Snake &snake) {
    Candy result;
    // Add code here to meet the requirements listed above
    return result;
  }
private:
  int _rowCount = 0;
  int _colCount = 0;
  mt19937 _generator;
};
#endif

Additions to the Snake Class

Add a method to Snake called:
bool headIntersects(int row, int col);

This method should return true if the snake's head has the same row and col as the given parameters.

Add another method to Snake called:
void eat(int calories, Color color);

When called, the snake should increase its calories by the amount passed. The snake's step() method should refer to its calorie count and grow while it has > 0 calories.

The honors section will use the color parameter to change the color of the snake to the value passed in the color parameter. The regular section may ignore the color parameter.

Additions to main.cpp

Include Candy and CandyMaker headers
Before the main loop, declare a local variable of type CandyMaker. Call its constructor with the size of the board.
Before the main loop, declare a local variable of type Candy. Initialize it with the result of calling the CandyMaker's newCandy() method.
Before the main loop, draw the newly initialized candy using its draw() method.
Inside the main loop, look for the comment /*** Code for eating candy goes here. ***/.

Here, use the snake's headIntersects() method to determine if the snake head is touching the candy.
If so, the snake is eating the candy. When that happens:

Call the snake's eat() method with the candy's position and calories.
Update the candy variable's values by assigning the result of newCandy().
Redraw the updated candy using its draw() method.
Honors (and more extra-credit fun for everyone else)

Different Glyphs for Head and Body Nodes

The head of the snake should be represented by an at-sign ('@') while the body nodes should be represented by a lowercase o ('o'). This will require modifying both the setTiles and step methods of Snake.

State Changes After Eating

When a snake eats a Candy, it should change in a way that is visible to the user. Since candies have color, have the snake change its color to the color of the last candy it ate.

Minimize Redrawing

Snakes move by adding new head segments, and sometimes removing tail segments. In general only tiles at the head and tail must be redrawn at any step. Having a differentiated head and body glyph should require one (but only one) additional call to setTile() when a new head is added. State changes that affect the whole snake's appearance should require one (but only one) complete traversal of the snake to present that change.
