//
// Created by azubi on 06/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "PlayGame.h"
void getting(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].type != INVALID && board[i][j].num_pieces != 0) {
                HEAD[i][j] = push1(HEAD[i][j], board[i][j].num_pieces, board[i][j].stack->p_color);
            }
        }
    }
}
void Play(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]){
    for(int i=2; i<5;i++) {
        int r, c, r2, c2;
        if (i % 2 == 0) {
            printf("%s turn(RED)\n", players[0].name);
            printf("Enter the row of the piece or stack you wish to move: \n");
            scanf("%d", &r);
            printf("Enter the column of the piece or stack you wish to move: \n");
            scanf("%d", &c);
            if ((board[r][c].type != INVALID || board[r][c].num_pieces != 0) && HEAD[r][c]->color22 == players[0].player_color){
                printf("Enter the row where you want to place the stack : \n");
                scanf("%d", &r2);
                printf("Enter the column where you want to place the stack :  \n");
                scanf("%d", &c2);
                if (getCount(HEAD[r][c]) < 6) {
                    HEAD[r2][c2]=push1(HEAD[r2][c2], HEAD[r][c]->num_pieces, HEAD[r][c]->color22);
                    HEAD[r][c]=pop(HEAD[r][c]);
                    board[r2][c2].stack->p_color=HEAD[r2][c2]->color22;
                    print_board2(board,HEAD);
                }
            }
            else{
                printf("Either you tried to move an invalid piece or you chose a top color thats not yours!!!\n");
            }
        }
        else{
            printf("%s turn(GREEN)\n", players[1].name);
            printf("Enter the row of the piece or stack you wish to move: \n");
            scanf("%d", &r);
            printf("Enter the column of the piece or stack you wish to move: \n");
            scanf("%d", &c);
            if ((board[r][c].type != INVALID || board[r][c].num_pieces != 0) && HEAD[r][c]->color22 == players[1].player_color){
                printf("Enter the row where you want to place the stack : \n");
                scanf("%d", &r2);
                printf("Enter the column where you want to place the stack :  \n");
                scanf("%d", &c2);
                if (getCount(HEAD[r][c]) < 6) {
                    HEAD[r2][c2]=push1(HEAD[r2][c2], HEAD[r][c]->num_pieces, HEAD[r][c]->color22);
                    HEAD[r][c]=pop(HEAD[r][c]);
                    board[r2][c2].stack->p_color=HEAD[r2][c2]->color22;
                    print_board2(board,HEAD);
                }
            }
            else{
                printf("Either you tried to move an invalid piece or you chose a top color thats not yours!!!\n");
            }
        }
    }
}