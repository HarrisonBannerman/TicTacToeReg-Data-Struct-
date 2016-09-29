
//Roosevelt Bannerman
//TicTacToe Program
//No Error Checking
#include <iostream>
#include "Board.h"

void displayWelcome();
std::string obtainPlayerOneName();
std::string obtainPlayerTwoName();
char obtainPlayerOnePiece(std::string);
char calculatePlayerTwoPiece(char);
int calculateFirst(char,char);
int obtainPlayerMove(std::string);
void displayFirst(std::string);
void displayScores(std::string[],int[],int);
char runAgain();

int main(){

   displayWelcome();

   //Obtains both player's names and puts them in an array
   std::string playerOneName = obtainPlayerOneName();
   std::string playerTwoName = obtainPlayerTwoName();
   std::string names[2] = {playerOneName,playerTwoName};

   //Obtains both player's pieces and puts them in an array
   char playerOnePiece = obtainPlayerOnePiece(playerOneName);
   char playerTwoPiece = calculatePlayerTwoPiece(playerOnePiece);
   char pieces[2] = {playerOnePiece,playerTwoPiece};

   //Creates an array for both player's scores and a variable to record draws
   int scores[2] = {0,0};
   int draws = 0;

   //Creates the gameboard and figures out who is going first for the first game
   Board gameBoard;
   int turnPlayer = calculateFirst(playerOnePiece,playerTwoPiece); //0 means player 1 is first
   char playAgain = '\0';

   do{
      bool gameOver = false;
      int counter = 0;
      gameBoard.displayBoard();
      std::cout << std::endl << std::endl;
      do{
         //Completes the current player's turn
         //Obtains move, sets piece, check for win, and redisplays the board
         int choice = obtainPlayerMove(names[turnPlayer]);
         counter++;
         gameBoard.setPiece(choice,pieces[turnPlayer]);
         gameBoard.displayBoard();
         gameOver = gameBoard.checkWin();
         if(gameOver == true){ //Ends the game if there is a winner
            std::cout << "\n\n\t" << names[turnPlayer] << " wins!";
            scores[turnPlayer]++;
            gameBoard.displayBoard();
            displayScores(names,scores,draws);
            turnPlayer++;
            turnPlayer = turnPlayer % 2;
         }
         else if(counter == 9){ //Ends the game if 9 moves have been made
            std::cout << "\n\n\t The game has ended in a draw!";
            draws++;
            displayScores(names,scores,draws);
            gameOver = true;
            turnPlayer++;
            turnPlayer = turnPlayer % 2;
         }
         else{ //Switches players
            turnPlayer++;
            turnPlayer = turnPlayer % 2;
         }
      }while(gameOver == false); //Runs until the game is over

      //Clears the board and asks if the players want to play again
      gameBoard.resetBoard();
      playAgain = runAgain();
   }while(playAgain=='y'); //Runs again until the players quit
   std::cout << std::endl << std::endl;
}

void displayWelcome(){ //Displays Welcome Message

   std::cout << "\n\n\tWelcome to the Tic-Tac-Toe game!";
}

std::string obtainPlayerOneName(){ //Returns the first player's name

   std::string name;
   bool isInvalid = false;

   do{
      std::cout << "\n\n\tPlayer one please enter your first and last name: ";
      std::getline(std::cin,name);


      for(unsigned int i=0;i<name.length();i++){
         char temp = name[i];
         if(temp > 'z' || (temp < 'A' && temp !=' ')){
            isInvalid = true;
            std::cout << "\n\tInvalid Input.";
            break;
         }
         else if( 'Z' < temp && temp < 'a'){
            isInvalid = true;
            std::cout << "\n\tInvalid Input.";
            break;
         }
         else{
            isInvalid = false;
         }
      }
   }while(isInvalid);

   return name;
}

std::string obtainPlayerTwoName(){ //Returns the second player's name
   std::string name;
   bool isInvalid = false;

   do{
      std::cout << "\n\n\tPlayer two please enter your first and last name: ";
      std::getline(std::cin,name);


      for(unsigned int i=0;i<name.length();i++){
         char temp = name[i];
         if(temp > 'z' || (temp < 'A' && temp !=' ')){
            isInvalid = true;
            std::cout << "\n\tInvalid Input.";
            break;
         }
         else if( 'Z' < temp && temp < 'a'){
            isInvalid = true;
            std::cout << "\n\tInvalid Input.";
            break;
         }
         else{
            isInvalid = false;
         }
      }
   }while(isInvalid);

   return name;
}

char obtainPlayerOnePiece(std::string name){ //Returns the first player's game piece

   std::string piece;
   bool isInvalid = false;

   do{
      std::cout << "\n\t";

      displayFirst(name);

      std::cout << " would you like to play as 'x' or 'o': ";
      std::cin >> piece;

      if(piece.length() > 1){
         isInvalid = true;
         std::cout << "\n\tInvalid Input.";
      }
      else if(piece[0] == 'x'){
         isInvalid = false;
      }
      else if(piece[0] == 'o'){
         isInvalid = false;
      }
      else{
         isInvalid = true;
         std::cout << "\n\tInvalid Input.";
      }
   }while(isInvalid);

   return piece[0];


}

char calculatePlayerTwoPiece(char piece){ //Returns the second player's game piece

   if(piece == 'x'){
      return 'o';
   }
   else{
      return 'x';
   }
}

int calculateFirst(char one, char two){ //Returns which player goes first

   if(one < two){
      return 0; //player 1 is first
   }
   else{
      return 1; //player 2 is first
   }
}

int obtainPlayerMove(std::string name){ //Returns the current player's move

   std::string choice;
   bool isInvalid = false;

   do{
      std::cout << "\n\t";
      displayFirst(name);
      std::cout << " what move would you like to make: ";
      std::cin >> choice;
      int temp = choice[0] - '0';
      if(choice.length() > 1){
         std::cout << "\n\tInvalid Input.";
         isInvalid = true;
      }
      else if(choice[0] > 57 || choice[0] < 49){
         std::cout << "\n\tInvalid Input.";
         isInvalid = true;
      }
      else{
         isInvalid = false;
      }
   }while(isInvalid);

   int selection = choice[0] - '0';

   return selection;
}

void displayFirst(std::string name){ //Displays the player's first name

   for(unsigned int i = 0;i<=name.length();i++){
      if(name[i]== ' ')
         break;
      else{
         std::cout << name[i];
      }
   }
}

void displayScores(std::string names[], int scores[],int draws){ //Displays the current scores

   std::cout << std::endl;

   for(unsigned int i=0;i<2;i++){
      std::cout << "\n\t" << names[i] << " - " << scores[i];
   }
   std::cout << "\n\tDraws - " << draws;
}

char runAgain(){ //Returns whether the players want to play again
   std::string choice;
   bool isInvalid = false;

   do{
      std::cout << "\n\n\n\tWould you like to play again(y/n): ";
      std::cin >> choice;

      if(choice.length() > 1){
         isInvalid = true;
         std::cout << "\n\tInvalid Input.";
      }
      else if(choice[0] == 'y'){
         isInvalid = false;
      }
      else if(choice[0] == 'n'){
         isInvalid = false;
      }
      else{
         isInvalid = true;
         std::cout << "\n\tInvalid Input.";
      }
   }while(isInvalid);

   return choice[0];
}
