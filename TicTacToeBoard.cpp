#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X) {
    turn = O;
    return turn;
  }
  turn = X;
  return turn;
}


/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (getWinner() == Blank || getWinner() == Invalid) {
    if (board[row][column] == ' ') {
      board[row][column] = turn;
      return board[row][column];
    }  
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row >= BOARDSIZE || column >= BOARDSIZE || row < 0 || column < 0) {
    return Invalid;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
/* 
BUG: Returns 'Blank' as a winner if the 1st row or column is blank even if there is a
tic-tac-toe in row/column 2/3
ie: 
' ' | 'X' | ' '
' ' | 'X' | ' '
' ' | 'X' | ' '
or
' ' | ' ' | ' '
'X' | 'X' | 'X'
' ' | ' ' | ' '
Will return Blank.
*/
Piece TicTacToeBoard::getWinner()
{
  // Check Columns
  for (int i = 0; i < BOARDSIZE; i++) {
    if ((getPiece(i,0) == getPiece(i,1)) && (getPiece(i,1) == getPiece(i,2))) {
      return getPiece(i,0);
    }
  }
  
  // Check Rows
  for (int i = 0; i < BOARDSIZE; i++) {
    if ((getPiece(0,i) == getPiece(1,i)) && (getPiece(1,i) == getPiece(2,i))) {
      return getPiece(0,i);
    }
  }
  
  // Check Diagonals
  if (((getPiece(0,0) == getPiece(1,1)) && (getPiece(1,1) == getPiece(2,2))) ||
      ((getPiece(0,2) == getPiece(1,1)) && (getPiece(1,1) == getPiece(2,0))))
  {
    return getPiece(1,1);
  }  
  return Invalid;
}

#include <iostream>
void TicTacToeBoard::printBoard()
{
   for(int i=0; i<BOARDSIZE; i++)
   {
    for(int j=0; j<BOARDSIZE; j++)
    {
      std::cout << "| " << board[i][j] << " ";
    }
   std::cout << "|" <<std::endl;
   }
}