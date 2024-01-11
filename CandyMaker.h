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
  CandyMaker(int rowCount, int colCount, unsigned int seed = random_device{}())
      : _rowCount(rowCount), _colCount(colCount), _generator(seed) {}

  // This method returns a random integer uniformly distributed between
  // a min and a max (excluding the max). Uniform distribution means that
  // every number in the given range is equally likely. Use it as is:
  int random(int min, int max) {
    uniform_int_distribution<int> uniform(min, max - 1);
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
  5) The color should be an int between 1 and 7 (including 7), corresponding to
  the GameBoard color enum

  (Note that the random method is inclusive of the minimum bound and exclusive
  of the maximum, so a caller wishing for a number from x to y, including y,
  should call random(x,y+1); )

  */
  Candy newCandy(const Snake &snake) {
    Candy result;
    int row = random(0, _rowCount);
    int col = random(0, _colCount);

    // ====> DJH: Very well written!
    while (snake.intersects(row, col)) {
      row = random(0, _rowCount);
      col = random(0, _colCount);
    }
    result.setRow(row);
    result.setCol(col);

    result.setGlyph(random('1', '9'+ 1));
    result.setCalories(result.glyph() - '0');
    result.setColor(Color(random(1, 8)));

    return result;
  }

private:
  int _rowCount = 0;
  int _colCount = 0;
  mt19937 _generator;
};

#endif

/****
In C++, a small cluster of classes enables the generation of random numbers.
The most important of these is called mt19937, after the algorithm used to
produce random (seeming numbers)

To prepare for random number generation, first create a seed, like this:

  int seed = random_device{}();
  mt19937 _generator(seed);

To get a random integer that is greater than or equal to zero and less than some
max value, do this:

  uniform_int_distribution<int> uniform(0, max-1);
  int myRandomInt = uniform(_generator);

WHen developing code that uses random values, it's often important to make the
random sequences repeat from run to run. This way, if there's a condition that
must be tested and retried a few times, we can be certain to reproduce


  const static int mySeed = 3210; // pick an int out of a hat for the seed

****/
