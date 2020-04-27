#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM]){
players[0].player_color=RED,players[0].captured_pieces=0,players[0].own_pieces_stock=0;//assigning relevant information about the first player which is required for the game

players[1].player_color=GREEN, players[1].captured_pieces=0, players[1].own_pieces_stock=0;//assigning relevant information about the first player which is required for the game

    // implement here the functionality to initialize the players
printf("\nEnter name of first player:\n");
fgets(players[0].name,10,stdin);//getting the name of the first player from the user

    printf("\nEnter name of second player:\n");
fgets(players[1].name,10,stdin);//getting the name of the second player from the user
}

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

struct square *push1(struct square *head, int value,color x){//this is to assign the pieces to the squares in a stack form
    square *curr =head;//assigning the linked list to a pointer
    head  = malloc( sizeof( square ) );//assigning sufficient memory
    head->num_pieces=value;//assigning the piece
    head->color22=x;//assigning the color of the piece
    head->next= curr;//linking  this piece to the next piece which is assigned in the pointer

    return head;
}

/*struct square * pop(struct square *head){

    while(head!=NULL) {
        struct square *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}*/

int getCount(struct square* head)//this is to find the number of pieces in a square
{
    // Base case
    if (head == NULL)
        return 0;

    // count is 1 + count of remaining list
    return 1 + getCount(head->next);
}

struct square * mergestack(struct square *head1,struct square *head2){//this  is to combine two stacks
    struct square *list=NULL;//creating a linked list
    list=head1;//assigning  the linked list the stack from the square it is moved
    struct square *curr=list;//assigning this linked list to another linked list
    while(curr->next!=NULL){
        curr=curr->next;//traversing in order to reach the last node of the stack
    }

    curr->next=head2;//connecting the last element of the first stack to the next stack
    return head1;//returning the new stack
}

