#include <stdio.h>
#include<stdlib.h>
#include "input_output.h"

struct square * push(int value, struct square *top){
    struct square *curr = top;
    top = malloc(sizeof(square));
    top->num_pieces = value;
    top->next= curr;
    return top;
}

struct square *push1(square *head, int value){
    square *new = malloc( sizeof( square ) );
    int success= new !=NULL;
    if(success){
        new->num_pieces=value;
        new->next= head;
        head=new;
    }
    return head;
}

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);
    //printf("\n\n %d ",players[0].own_pieces_remaining);
    printf("\n %s ",players[0].name);
    printf("\n %s ",players[1].name);
    printf("\n test: %d ",board[2][5].num_pieces);

   /* //pointer to the top of the stack
    struct square *top =NULL;
    //pointer to the current element of the stack
    struct square *curr = NULL;

    top =  push(1, top);
           printf("Stack Data: %d\n", top->num_pieces);*/

 square *HEAD[BOARD_SIZE][BOARD_SIZE] = { 0 };
    HEAD[2][5]=push1(HEAD[2][5],2);
printf("\n try 1: %d", HEAD[2][5]->num_pieces);
    board[2][5].num_pieces=HEAD[2][5]->num_pieces;
    printf("\n actuall 1: %d", board[2][5].num_pieces);
    return 0;
}
