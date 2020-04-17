//
// Created by azubi on 13/04/2020.
//
#include <stdio.h>
#include "CheckWinner.h"
int checkwinner(square board[BOARD_SIZE][BOARD_SIZE],struct square *head[BOARD_SIZE][BOARD_SIZE],int enemypieces) {
    int flag;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == VALID && enemypieces != 0) {
                flag = 1;
                break;
            } else if(enemypieces==0){
                if(board[i][j].stack->p_color==GREEN)
                {
                    flag=1;
                    break;
                }
            }
            else if()
        }
    }
}