//
// Created by azubi on 13/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "CheckWinner.h"



int checkwinner(square board[BOARD_SIZE][BOARD_SIZE], struct square * HEAD[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){//piececolor is enemy colour
    int green=0,red=0,l=0;//0 flag no more top green and red wins / 1 red no more top red and green wins/ 0 flag continue
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j].type == VALID) {
                if(/*board[i][j].stack == NULL ||*/HEAD[i][j]==NULL)
                    l++;
                else{
                    if (board[i][j].stack->p_color == GREEN) {
                       green++;
                    }
                    else {
                        red++;
                    }
                }
            }
        }
    }
