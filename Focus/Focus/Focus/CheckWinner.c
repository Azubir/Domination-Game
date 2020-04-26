//
// Created by azubi on 13/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "CheckWinner.h"
int checkwinner(square board[BOARD_SIZE][BOARD_SIZE],struct square *head[BOARD_SIZE][BOARD_SIZE],color piececolor){//piececolor is enemy colour
    int validsquares = 44, count=0,flag=1;//continue
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ( board[i][j].type==VALID && board[i][j].stack->p_color == piececolor) {
                count+=1;
            }
        }
    }
    if(count>0){
        flag=0;//winner
    }
        return flag;
}