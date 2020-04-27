#include <stdio.h>
#include "PlayGame.h"
int main() {
     title();
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);//assigning the players their relevant info


    initialize_board(board);//setting up the board
    print_board3(board);//printing an index of the board
    print_board(board);//printing the board

    square *HEAD[BOARD_SIZE][BOARD_SIZE] = { NULL };//creating an array of linked list which will be used for containing the number of pieces and color at each square of the board

    getting(HEAD,board);//assigning the pieces to the relevant squares of the board

   Play(HEAD,board,players);//Playing the game


    return 0;
}
