#include <stdio.h>
#include<stdlib.h>
//#include "input_output.h"
#include "PlayGame.h"
int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);


    initialize_board(board);
    print_board3(board);
    print_board(board);

    square *HEAD[BOARD_SIZE][BOARD_SIZE] = { NULL };

    getting(HEAD,board);

    Play(HEAD,board,players);

    return 0;
}
