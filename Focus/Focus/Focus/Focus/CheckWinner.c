//
// Created by azubi on 13/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "CheckWinner.h"



int checkwinner(square board[BOARD_SIZE][BOARD_SIZE], struct square * HEAD[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){//piececolor is enemy colour
    int green=0,red=0,l=0;//0 flag no more top green and red wins / 1 red no more top red and green wins/ 0 flag continue
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){//in order to check each square of the board
            if(board[i][j].type == VALID) {//the square has to be valid in the first place
                if(/*board[i][j].stack == NULL ||*/HEAD[i][j]==NULL)//if theres no pieces we dont do anything
                    l++;
                else{
                    if (board[i][j].stack->p_color == GREEN) {//we keep count of the number of top pieces that are green 
                       green++;
                    }
                    else {//we keep count of the number of top pieces that are red
                        red++;
                    }
                }
            }
        }
    }









    if(green==0 && players[0].own_pieces_stock==0){//check if theres no more green top colors and the players doesnt have any received pieces
        printf("%s WINS\nCOLOUR: RED\nCAPTURED PIECES(ENEMYS): %d\nRESERVED PIECES: %d",players[0].name,players[0].captured_pieces,players[0].own_pieces_stock);//prints out the winner information
        return 0;
    }else if(red==0 && players[1].own_pieces_stock==0){//check if theres no more red top colors and the players doesnt have any received pieces
        printf("%s WINS\nCOLOUR: GREEN\nCAPTURED PIECES(ENEMYS): %d\nRESERVED PIECES: %d",players[1].name,players[1].captured_pieces,players[1].own_pieces_stock);//prints out the winner information
        return 0;
    }else{
        return 1;
    }

}
