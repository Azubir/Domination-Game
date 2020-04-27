#ifndef FOCUS_INPUT_OUTPUT_H
#define FOCUS_INPUT_OUTPUT_H

#endif //FOCUS_INPUT_OUTPUT_H

#include "game_init.h"

//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);//prototype definition to print out the original/first layed out board
void print_board2(square board[BOARD_SIZE][BOARD_SIZE], struct square *HEAD[BOARD_SIZE][BOARD_SIZE]);//prototype definition to printout the board after every change happened in the board
void print_board3(square board[BOARD_SIZE][BOARD_SIZE]);//prototype definition to printout the index board
void title();//prototype definition to print out the title game