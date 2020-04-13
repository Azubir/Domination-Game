#include <stdio.h>
#include "input_output.h"
/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */


void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("|\n");
    }
}

void print_board2(square board[BOARD_SIZE][BOARD_SIZE], struct square *HEAD[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(/*board[i][j].stack == NULL ||*/HEAD[i][j]==NULL)
                    printf("|    ");
                else{
                    if (board[i][j].stack->p_color == GREEN) {
                        switch(getCount(HEAD[i][j]))
                        {
                            case 1:
                                printf("| G1 ");
                                break;
                            case 2:
                                printf("| G2 ");
                                break;
                            case 3:
                                printf("| G3 ");
                                break;
                            case 4:
                                printf("| G4 ");
                                break;
                            case 5:
                                printf("| G5 ");
                        }
                       // printf("| G ");
                    }
                    else {
                        switch(getCount(HEAD[i][j]))
                        {
                            case 1:
                                printf("| R1 ");
                                break;
                            case 2:
                                printf("| R2 ");
                                break;
                            case 3:
                                printf("| R3 ");
                                break;
                            case 4:
                                printf("| R4 ");
                                break;
                            case 5:
                                printf("| R5 ");
                        }
                       // printf("| R ");
                    }
                }
            }
            else
                printf("| -- ");
        }
        printf("|\n");
    }
}

void print_board3(square board[BOARD_SIZE][BOARD_SIZE]){
    int i,j;
    printf("****** The Board Index ******\n");
    for( i = 0; i < BOARD_SIZE; i ++){
        for ( j = 0; j < BOARD_SIZE; j++){
                printf("| %d,%d ",i,j);
        }
        printf("|\n");
    }
}