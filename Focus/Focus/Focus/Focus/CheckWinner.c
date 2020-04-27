//
// Created by azubi on 13/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "CheckWinner.h"
int checkwinner(square board[BOARD_SIZE][BOARD_SIZE], struct square * head[BOARD_SIZE][BOARD_SIZE]){//piececolor is enemy colour
    int flag=2,green=1,red=1;//0 flag no more top green and red wins / 1 red no more top red and green wins/ 0 flag continue
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j].type==VALID && head[i][j]->color22==GREEN){
                green=0;
            }else if(board[i][j].type==VALID && head[i][j]->color22==RED){
                red=0;
            }
        }
    }




    if(green==1){
        flag=0;
    }else if(red==1){
        flag=1;
    }
    return flag;
}