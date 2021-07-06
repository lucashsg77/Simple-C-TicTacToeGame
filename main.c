#include "TicTacToe.h"

int main(){
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = '1', chosenTile;
    int endGame = 3;
    do{
        printBoard(board);
        chosenTile = playerInput(player);
        player = computePlay(board, chosenTile, player);
        endGame = isOver(board);
    }while (endGame == -1);
    
    printBoard(board);
    whoWon(endGame, player);
    return 0;
}