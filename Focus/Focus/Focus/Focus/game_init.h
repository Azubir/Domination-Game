
#ifndef FOCUS_GAME_INIT_H
#define FOCUS_GAME_INIT_H

#endif //FOCUS_GAME_INIT_H


#define BOARD_SIZE 8
#define PLAYERS_NUM 3

//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the color associated with the player
    color player_color;
    char name[10];
    int captured_pieces;
    int own_pieces_stock;
    /*
     * A player should also be characterized by:
     * name,
     * number of adversary's pieces captured,
     * number of own pieces kept.
     *
    */
}player;

// A piece
typedef struct piece {
    //the color associated with a piece
   color p_color;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
   struct piece * stack;

    //number of pieces on the square
    int num_pieces;
    color color22;
    struct square *next;
}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);


struct square *push1(struct square *head, int value,color x);//prototype definition to assign another piece to the stack

//struct square * pop(struct square *head);

int getCount(struct square* head);//prototype definition to get the number of pieces in a square

struct square * mergestack(struct square *head1,struct square *head2);//protototype definition to combine two stacks
