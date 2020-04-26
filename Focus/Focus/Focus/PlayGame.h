//
// Created by azubi on 06/04/2020.
//

#ifndef FOCUS_PLAYGAME_H
#define FOCUS_PLAYGAME_H

#endif //FOCUS_PLAYGAME_H

//#include "input_output.h"
#include "CheckWinner.h"
#include "CheckingValidity.h"
void getting(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE]);
void Play(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]);