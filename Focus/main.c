#include <stdio.h>
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
int l;
   l= Play(HEAD,board,players);
    if(l==0){
        printf("%s won",players[0].name);
    }else{
        printf("%s won",players[1].name);
    }

    return 0;
}
