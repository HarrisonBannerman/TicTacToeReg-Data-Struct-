#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
   public:
      Board();
      char
         getOne(),
         getTwo(),
         getThree(),
         getFour(),
         getFive(),
         getSix(),
         getSeven(),
         getEight(),
         getNine();
      void
         setOne(char),
         setTwo(char),
         setThree(char),
         setFour(char),
         setFive(char),
         setSix(char),
         setSeven(char),
         setEight(char),
         setNine(char),
         displayBoard(),
         setPiece(int,char),
         resetBoard();
      bool
         checkWin();
   protected:
   private:
      char one, two, three, four, five, six, seven, eight, nine;
};

#endif
