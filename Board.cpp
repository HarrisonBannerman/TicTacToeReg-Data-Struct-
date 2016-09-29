#include "Board.h"

Board::Board()
{
   one = '1';
   two = '2';
   three = '3';
   four = '4';
   five = '5';
   six  = '6';
   seven = '7';
   eight = '8';
   nine = '9';
}

void Board::resetBoard(){
   one = '1';
   two = '2';
   three = '3';
   four = '4';
   five = '5';
   six  = '6';
   seven = '7';
   eight = '8';
   nine = '9';
}

void Board::setPiece(int location,char piece){

   switch(location){
   case 1:{
      setOne(piece);
      break;
      }
   case 2:{
      setTwo(piece);
      break;
      }
   case 3:{
      setThree(piece);
      break;
      }
   case 4:{
      setFour(piece);
      break;
      }
   case 5:{
      setFive(piece);
      break;
      }
   case 6:{
      setSix(piece);
      break;
      }
   case 7:{
      setSeven(piece);
      break;
      }
   case 8:{
      setEight(piece);
      break;
      }
   case 9:{
      setNine(piece);
      break;
      }
   }

}

char Board::getOne(){
   return one;
}

char Board::getTwo(){
   return one;
}

char Board::getThree(){
   return one;
}

char Board::getFour(){
   return one;
}

char Board::getFive(){
   return one;
}

char Board::getSix(){
   return one;
}

char Board::getSeven(){
   return one;
}

char Board::getEight(){
   return one;
}

char Board::getNine(){
   return one;
}

void Board::setOne(char piece){
   one = piece;
}

void Board::setTwo(char piece){
   two = piece;
}

void Board::setThree(char piece){
   three = piece;
}

void Board::setFour(char piece){
   four = piece;
}

void Board::setFive(char piece){
   five = piece;
}

void Board::setSix(char piece){
   six = piece;
}

void Board::setSeven(char piece){
   seven = piece;
}

void Board::setEight(char piece){
   eight = piece;
}

void Board::setNine(char piece){
   nine = piece;
}

void Board::displayBoard(){
   std::cout << "\n\t| " << one << " | " << two << " | " << three << " |";
   std::cout << "\n\t| " << four << " | " << five << " | " << six << " |";
   std::cout << "\n\t| " << seven << " | " << eight << " | " << nine << " |";
   std::cout << std::endl;
}

bool Board::checkWin(){

   if(one == two && one == three){
      one = toupper(one);
      two = toupper(two);
      three = toupper(three);
      return true;
   }
   else if(four == five && four == six){
      four = toupper(four);
      five = toupper(five);
      six = toupper(six);
      return true;
   }
   else if(seven == eight && seven == nine){
      seven = toupper(seven);
      eight = toupper(eight);
      nine = toupper(nine);
      return true;
   }
   else if(one == four && one == seven){
      one = toupper(one);
      four = toupper(four);
      seven = toupper(seven);
      return true;
   }
   else if(two == five && two == eight){
      two = toupper(two);
      five = toupper(five);
      eight = toupper(eight);
      return true;
   }
   else if(three == six && three == nine){
      three = toupper(three);
      six = toupper(six);
      nine = toupper(nine);
      return true;
   }
   else if(one == five && one == nine){
      one = toupper(one);
      five = toupper(five);
      nine = toupper(nine);
      return true;
   }
   else if(three == five && three == seven){
      three = toupper(three);
      five = toupper(five);
      seven = toupper(seven);
      return true;
   }
   else{
      return false;
   }
}
