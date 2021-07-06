#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

char board[9];

char playerInput(char player);

char computePlay(char board[9], char chosenTile, char player);

int checkHor(char board[9]);

int checkVer(char board[9]);

int checkDiag(char board[9]);

int checkDraw(char board[9]);

int isOver(char board[9]);

void printBoard(char board[9]);

void clearScreen();

void whoWon(int endGame, char player);

char numGenerator();

#endif