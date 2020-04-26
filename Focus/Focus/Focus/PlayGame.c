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
                HEAD[i][j] = push1(HEAD[i][j], 1, board[i][j].stack->p_color);
            }
        }
    }
}
void Play(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]) {
    int g,l=1;
        for (int i = 2; i < 105; i++) {
        int r, c, r2, c2, k;
        printf("Enter 0 if you want to move piece from the board or enter 1 if you want to move piece from pieces that you have reserved or\n Enter 2 if you want to display %s captured and reserved pieces or\n Enter 3 if you want to display %s captured and reserved pieces\n",
               players[0].name, players[1].name);
        scanf("%d", &k);
        if (k == 0) {
            if (i % 2 == 0) {
                printf("%s turn(RED)\n", players[0].name);
                printf("Enter the row of the piece or stack you wish to move: \n");
                scanf("%d", &r);
                printf("Enter the column of the piece or stack you wish to move: \n");
                scanf("%d", &c);
                if ((board[r][c].type != INVALID && board[r][c].num_pieces != 0) &&
                    HEAD[r][c]->color22 == players[0].player_color) {
                    printf("Enter the row where you want to place the stack : \n");
                    scanf("%d", &r2);
                    printf("Enter the column where you want to place the stack :  \n");
                    scanf("%d", &c2);
                    g = validity(getCount(HEAD[r][c]), r, c, r2, c2);
                    if (g == 1) {
                        HEAD[r2][c2] = mergestack(HEAD[r][c], HEAD[r2][c2]);
                        board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;
                        if(getCount(HEAD[r2][c2])>5) {//top color will always be red since it was the red piece player move who would have cause this condition to evaluate to true
                            while (getCount(HEAD[r2][c2])>5) {
                                color lastcolor;
                                struct square *curr, *pre,*node;
                                curr = HEAD[r2][c2];
                                node=HEAD[r2][c2];
                                while (curr->next) {
                                    pre = curr;
                                    curr = curr->next;
                                }
                                lastcolor = curr->color22;
                                pre->next = curr->next;
                                HEAD[r2][c2]=node;
                                if(lastcolor==RED){
                                    players[0].own_pieces_stock+=1;
                                }else{
                                    players[0].captured_pieces+=1;
                                }
                            }
                            struct square *temp=NULL;
                            HEAD[r][c] = temp;
                            print_board2(board, HEAD);
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);
                        }else {
                            struct square *temp=NULL;
                            HEAD[r][c] = temp;
                            print_board2(board, HEAD);
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);
                        }
                    } else {
                        printf("INVALID MOVE\n");
                    }
                } else {
                    printf("Either you tried to move an invalid piece or you chose a top color that is not yours!!!\n");
                }
            } else {
                printf("%s turn(GREEN)\n", players[1].name);
                printf("Enter the row of the piece or stack you wish to move: \n");
                scanf("%d", &r);
                printf("Enter the column of the piece or stack you wish to move: \n");
                scanf("%d", &c);
                if ((board[r][c].type != INVALID || board[r][c].num_pieces != 0) &&
                    HEAD[r][c]->color22 == players[1].player_color) {
                    printf("Enter the row where you want to place the stack : \n");
                    scanf("%d", &r2);
                    printf("Enter the column where you want to place the stack :  \n");
                    scanf("%d", &c2);
                    g = validity(getCount(HEAD[r][c]), r, c, r2, c2);
                    if (g == 1) {
                        HEAD[r2][c2] = mergestack(HEAD[r][c], HEAD[r2][c2]);
                        board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;
                        if(getCount(HEAD[r2][c2])>5) {//top color will always be red since it was the red piece player move who would have cause this condition to evaluate to true
                            while (getCount(HEAD[r2][c2])>5) {
                                color lastcolor;
                                struct square *curr, *pre,*node;
                                curr = HEAD[r2][c2];
                                node=HEAD[r2][c2];
                                while (curr->next) {
                                    pre = curr;
                                    curr = curr->next;
                                }
                                lastcolor = curr->color22;
                                pre->next = curr->next;
                                HEAD[r2][c2]=node;
                                if(lastcolor==GREEN){
                                    players[1].own_pieces_stock+=1;
                                }else{
                                    players[1].captured_pieces+=1;
                                }
                            }
                            struct square *temp=NULL;
                            HEAD[r][c] = temp;
                            print_board2(board, HEAD);
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);
                        }else {
                            struct square *temp=NULL;
                            HEAD[r][c] = temp;
                            print_board2(board, HEAD);
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);
                        }
                    } else {
                        printf("INVALID MOVE");
                    }
                } else {
                    printf("Either you tried to move an invalid piece or you chose a top color that is not yours!!!\n");
                }
            }
        }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (k == 1) {
            if (i % 2 == 0) {
                if (players[0].own_pieces_stock == 0) {
                    printf("You have no pieces reserved!!!\n");
                } else {
                    printf("%s turn(RED)\n", players[0].name);

                    printf("Enter the row where you want to place the stack : \n");
                    scanf("%d", &r2);
                    printf("Enter the column where you want to place the stack :  \n");
                    scanf("%d", &c2);

                    HEAD[r2][c2] = push1(HEAD[r2][c2], 1, RED);
                    players[0].own_pieces_stock--;
                    board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;
                    if(getCount(HEAD[r2][c2])>5) {//top color will always be red since it was the red piece player move who would have cause this condition to evaluate to true
                        while (getCount(HEAD[r2][c2])>5) {
                            color lastcolor;
                            struct square *curr, *pre,*node;
                            curr = HEAD[r2][c2];
                            node=HEAD[r2][c2];
                            while (curr->next) {
                                pre = curr;
                                curr = curr->next;
                            }
                            lastcolor = curr->color22;
                            pre->next = curr->next;
                            HEAD[r2][c2]=node;
                            if(lastcolor==RED){
                                players[0].own_pieces_stock+=1;
                            }else{
                                players[0].captured_pieces+=1;
                            }
                        }
                        print_board2(board, HEAD);
                        printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                               players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);
                    }else {
                        print_board2(board, HEAD);
                        printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                               players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);
                    }
                }
            } else {
                if (players[0].own_pieces_stock == 0) {
                    printf("You have no pieces reserved!!!\n");
                } else {
                    printf("%s turn(GREEN)\n", players[1].name);
                    printf("Enter the row where you want to place the stack : \n");
                    scanf("%d", &r2);
                    printf("Enter the column where you want to place the stack :  \n");
                    scanf("%d", &c2);
                    HEAD[r2][c2] = push1(HEAD[r2][c2], 1, GREEN);
                    board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;
                    if(getCount(HEAD[r2][c2])>5) {//top color will always be red since it was the red piece player move who would have cause this condition to evaluate to true
                        while (getCount(HEAD[r2][c2])>5) {
                            color lastcolor;
                            struct square *curr, *pre,*node;
                            curr = HEAD[r2][c2];
                            node=HEAD[r2][c2];
                            while (curr->next) {
                                pre = curr;
                                curr = curr->next;
                            }
                            lastcolor = curr->color22;
                            pre->next = curr->next;
                            HEAD[r2][c2]=node;
                            if(lastcolor==GREEN){
                                players[1].own_pieces_stock+=1;
                            }else{
                                players[1].captured_pieces+=1;
                            }
                        }
                        print_board2(board, HEAD);
                        printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                               players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);
                    }else {
                        print_board2(board, HEAD);
                        printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                               players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);
                    }
                }
            }
        }
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (k == 2) {
            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n", players[0].name,
                   players[0].own_pieces_stock, players[0].captured_pieces);
        } else if (k == 3) {
            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n", players[1].name,
                   players[1].own_pieces_stock, players[1].captured_pieces);
        }
    }
}


