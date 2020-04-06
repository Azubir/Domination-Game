#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM]){
players[0].player_color=RED,players[0].captured_pieces=0,players[0].own_pieces_remaining=20;
//players[0].name[10] = "Playerone";
players[1].player_color=GREEN, /*players[1].name[10]= "Playertwo",*/ players[1].captured_pieces=0, players[1].own_pieces_remaining=20;

    // implement here the functionality to initialize the players
printf("\nEnter name of first player:\n");
fgets(players[0].name,10,stdin);

printf("\nEnter name of second player:\n");
fgets(players[1].name,10,stdin);
}//use modulo 2 to determine which player to go next

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){//initialises the board and assigns the colour to each of the element as well as the number of pieces there are

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);

                }
            }
        }

    }

}

struct square *push1(struct square *head, int value,color x){
    square *curr =head;
    head  = malloc( sizeof( square ) );
    head->num_pieces=value;
    head->color22=x;
    head->next= curr;

    return head;
}

struct square * pop(struct square *head){
    struct square *curr = head;
    if(curr!=NULL){
        head = curr->next;
        //printf("/nStack Data: %d,,%d\n", curr->num_pieces,curr->color22);
        free(curr);
    }
    return head;
}

int getCount(struct square* head)
{
    // Base case
    if (head == NULL)
        return 0;

    // count is 1 + count of remaining list
    return 1 + getCount(head->next);
}