    #include "TicTacToe.h"

    //takes the input from the player and then "cleans" the stdin from any leftovers '\n' or other chars that should not 
    //be taken as input and then finally returns the input
    char playerInput(char player){
        char input;
        if(player == '2')
        	input = numGenerator();
        if(player == '1'){
            printf("Player 1, select a tile:  ");
            input = getchar();
            while(getchar() != '\n');
        }
        return input;
    }

    //takes the chosenTile, player and board so it can computs the play, if it is a valid play the function saves it on
    //the board and then changes to the other player's turn, if it is an invalid tile it says so, and finally if it is not a valid
    //play, meaning choosing a tile already selected, the function does nothing and keeps the player's turn until a valid play is made
    char computePlay(char board[9], char chosenTile, char player){
        char mark = (player == '1') ? 'X' : 'O';
        int flag = 1;
        while(flag == 1){
            switch (chosenTile){
            case '1':
                if(board[0] == chosenTile){
                    board[0] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '2':
                if(board[1] == chosenTile){
                    board[1] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '3':
                if(board[2] == chosenTile){
                    board[2] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '4':
                if(board[3] == chosenTile){
                    board[3] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '5':
                if(board[4] == chosenTile){
                    board[4] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '6':
                if(board[5] == chosenTile){
                    board[5] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                    chosenTile = numGenerator();
                }
                break;
            case '7':
                if(board[6] == chosenTile){
                    board[6] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                   chosenTile = numGenerator(); 
                }
                break;
            case '8':
                if(board[7] == chosenTile){
                    board[7] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                   chosenTile = numGenerator(); 
                }
                break;
            case '9':
                if(board[8] == chosenTile){
                    board[8] = mark;
                    player = (player == '1') ? '2' : '1';
                    flag = 0;
                }
                else{
                   chosenTile = numGenerator(); 
                }
                break;
            default:
                printf("Not a valid tile");
                break;
            }
        }
        return player;
    }

    //checks if someone won in any of the horizontal lines, if someone wins it returns 1, if not returns 0
    int checkHor(char board[9]){
        int flag = 0;
        for(int i = 0; i < 9; i += 3){
            if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
                flag = 1;
        }
        return flag;
    }

    //checks if someone won in any of the vertical lines, if someone wins it returns 1, if not returns 0
    int checkVer(char board[9]){
        int flag = 0;
        for(int i = 0; i < 3; ++i){
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
                flag = 1;
        }
        return flag;
    }

    //checks if someone won in any of the diagonal lines, if someone wins it returns 1, if not returns 0
    int checkDiag(char board[9]){
        int flag = 0;
        if (board[0] == board[4] && board[4] == board[8])
            flag = 1;
            
        else if (board[2] == board[4] && board[4] == board[6])
            flag = 1;

        return flag;
    }

    //checks if it is a draw, if it is returns 1, if not returns 0
    int checkDraw(char board[9]){
        int flag = 0;
        if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
            board[3] != '4' && board[4] != '5' && board[5] != '6' && 
            board[6] != '7' && board[7] != '8' && board[8] != '9')
            flag = 1;

        return flag;
    }

    //checks if the game is over by checking possible win conditions and a possible draw then it returns a number accordingly
    //if it is not over returns -1, if it is a draw returns 0, if someone won returns 1
    int isOver(char board[9]){
        int flag = -1;
        if(checkHor(board) || checkDiag(board) || checkVer(board))
           flag = 1;
        else if(checkDraw(board))
           flag = 0;

        return flag;
    }

    //prints the board in a for loop
    void printBoard(char board[9]){
        clearScreen();
        for(int i = 0; i < 9; i += 3){
            printf("\t\t\t\t\t     |     |     \n");
            printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[i], board[i + 1], board[i + 2]);
            if(i != 6)  printf("\t\t\t\t\t_____|_____|_____\n");
            if(i == 6)  printf("\t\t\t\t\t     |     |     \n\n");
        }
        printf("\t\t\t\tPlayer 1: X\t\tPc: O\n\n");
    }

    //decides if there was a winner, if there is one prints out the winner, if there is none prints out that is was a draw
    void whoWon(int endGame, char player){
        player = (player == '1') ? '2' : '1';
        if (endGame == 1)
            printf("Player %c won the game\n", player);
        else
            printf("The game was a draw\n");
        }

    //checks the OS and defines which command to use in order to clear the screen
    void clearScreen(){
    #ifdef WINDOWS
        system("cls");
    #else
        system ("clear");
    #endif
    }
    //generates a random number so the pc can make a random play
    char numGenerator(){
        srand(time(NULL));
        char randomNum = (rand() % 9);
        return randomNum + 49;
    }