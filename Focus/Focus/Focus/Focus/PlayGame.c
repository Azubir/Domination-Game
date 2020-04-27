//
// Created by azubi on 06/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "PlayGame.h"
void getting(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE]) {//function which assigns each piece and its color to its relevant square
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].type != INVALID && board[i][j].num_pieces != 0) {
                HEAD[i][j] = push1(HEAD[i][j], 1, board[i][j].stack->p_color);//these are assigned to a an array of linked list which will contain all of the game information
            }
        }
    }
}
void Play(struct square *HEAD[BOARD_SIZE][BOARD_SIZE],square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]) {//function to play the game
    int g,flag=2;//initialising variables which will ne used to operate the game
        for (int i = 2; i < 105; i++) {//a loop which will allow the the game to be played i amount of times
            int r, c, r2, c2, k,l=i%2;//initialising variables which will ne used to operate the game
            printf("(%s turn) Enter 0 if you want to move piece from the board or enter 1 if you want to move piece from pieces that you have reserved or\n Enter 2 if you want to display %s captured and reserved pieces or\n Enter 3 if you want to display %s captured and reserved pieces\n",
                   players[l].name,players[0].name, players[1].name);//asking the user which choice he wants to pick
            scanf("%d", &k);//storing that choice into k
            if (k == 0) {
                if (i % 2 == 0) {//modulo 2 to decide which player turn it is
                    printf("%s turn(RED)\n", players[0].name);
                    printf("Enter the row of the piece or stack you wish to move: \n");
                    scanf("%d", &r);//asking for the row of the piece to be moved from
                    printf("Enter the column of the piece or stack you wish to move: \n");
                    scanf("%d", &c);//asking for the column of the piece to be moved from
                    if ((board[r][c].type != INVALID && board[r][c].num_pieces != 0) &&
                        HEAD[r][c]->color22 == players[0].player_color) {//check wether the the piece/stack to be moved is the same top color as the player and that theirs a piece and that the square is not invalid
                        printf("Enter the row where you want to place the stack : \n");
                        scanf("%d", &r2);//asking for the row of the piece to be moved to
                        printf("Enter the column where you want to place the stack :  \n");
                        scanf("%d", &c2);//asking for the column of the piece to be moved to
                        g = validity(getCount(HEAD[r][c]), r, c, r2, c2);//function which checks the number of steps thats been taken is a valid or invalid move depending on the size of the stack if it is a valid move 1 is returned
                        if (g == 1) {//if g==1 then its a valid move and it continues
                            HEAD[r2][c2] = mergestack(HEAD[r][c], HEAD[r2][c2]);//a function which combines the piece/stack from which moved from to place on the top of the new location piece/stack
                            board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;//assigning the top color of the new combined stack to the board color which will be used later to calculate the winner
                            if (getCount(HEAD[r2][c2]) >5) {//a function which counts the number of pieces in the square
                                while (getCount(HEAD[r2][c2]) > 5) {//this contains the stack to be of size 5
                                    color lastcolor;//intialising an enum variable color
                                    struct square *curr, *pre, *node;//intialising 3 linked lists
                                    curr = HEAD[r2][c2];//assigning the new combined stack/piece linked list to curr
                                    node = HEAD[r2][c2];//assigning the new combined stack/piece linked list to node
                                    while (curr->next) {//traversing until the end of the linked list and storing the node before the last to pre
                                        pre = curr;
                                        curr = curr->next;
                                    }
                                    lastcolor = curr->color22;//storing the last color of the stack/piece to lastcolor
                                    pre->next = curr->next;//assigning the second last node to NULL
                                    HEAD[r2][c2] = node;//assigning the new linked list back to head
                                    if (lastcolor == RED) {//we only calculate for the red player since it was the red player move and the top color must be red
                                        players[0].own_pieces_stock += 1;//if the lastcolor was red then the number of pieces he has reserved will be incremented by one
                                    } else {
                                        players[0].captured_pieces += 1;//if the lastcolor was not red then the number of pieces he has captured will be incremented by one
                                    }
                                }
                                struct square *temp = NULL;//declaring a linked list and assigning NULL to it
                                HEAD[r][c] = temp;//assigning the new empty linked list to HEAD[r][c] which was the position from which was the piece moved from and this empties the square from any pieces
                                print_board2(board, HEAD);//prints the new board
                                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                       players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);//prints out the first player name,pieces he has reserved,pieces he has captured
                            } else {//if th stack size is 5 or lower
                                struct square *temp = NULL;//declaring a linked list and assigning NULL to it
                                HEAD[r][c] = temp;//assigning the new empty linked list to HEAD[r][c] which was the position from which was the piece moved from and this empties the square from any pieces
                                print_board2(board, HEAD);//prints the new board
                                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                       players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);//prints out the first player name,pieces he has reserved,pieces he has captured
                            }
                        } else {
                            printf("INVALID MOVE\n");//if the player made an illegal move
                        }
                    } else {
                        printf("Either you tried to move an invalid piece or you chose a top color that is not yours!!!\n");//if the player chose a top color thats not his or the piece is invalid
                    }
                } else {
                    printf("%s turn(GREEN)\n", players[1].name);
                    printf("Enter the row of the piece or stack you wish to move: \n");
                    scanf("%d", &r);//asking for the row of the piece to be moved from
                    printf("Enter the column of the piece or stack you wish to move: \n");
                    scanf("%d", &c);//asking for the column of the piece to be moved from
                    if ((board[r][c].type != INVALID || board[r][c].num_pieces != 0) &&
                        HEAD[r][c]->color22 == players[1].player_color) {//check wether the the piece/stack to be moved is the same top color as the player and that theirs a piece and that the square is not invalid
                        printf("Enter the row where you want to place the stack : \n");
                        scanf("%d", &r2);//asking for the row of the piece to be moved to
                        printf("Enter the column where you want to place the stack :  \n");
                        scanf("%d", &c2);//asking for the column of the piece to be moved to
                        g = validity(getCount(HEAD[r][c]), r, c, r2, c2);//function which checks the number of steps thats been taken is a valid or invalid move depending on the size of the stack if it is a valid move 1 is returned
                        if (g == 1) {//if g==1 then its a valid move and it continues
                            HEAD[r2][c2] = mergestack(HEAD[r][c], HEAD[r2][c2]);//a function which combines the piece/stack from which moved from to place on the top of the new location piece/stack
                            board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;//assigning the top color of the new combined stack to the board color which will be used later to calculate the winner
                            if (getCount(HEAD[r2][c2]) >5) {//this contains the stack to be of size 5
                                while (getCount(HEAD[r2][c2]) > 5) {//a function which counts the number of pieces in the square
                                    color lastcolor;//intialising an enum variable color
                                    struct square *curr, *pre, *node;//intialising 3 linked lists
                                    curr = HEAD[r2][c2];//assigning the new combined stack/piece linked list to curr
                                    node = HEAD[r2][c2];//assigning the new combined stack/piece linked list to node
                                    while (curr->next) {//traversing until the end of the linked list and storing the node before the last to pre
                                        pre = curr;
                                        curr = curr->next;
                                    }
                                    lastcolor = curr->color22;//storing the last color of the stack/piece to lastcolor
                                    pre->next = curr->next;//assigning the second last node to NULL
                                    HEAD[r2][c2] = node;//assigning the new linked list back to head
                                    if (lastcolor == GREEN) {//we only calculate for the green player since it was the green player move and the top color must be green
                                        players[1].own_pieces_stock += 1;//if the lastcolor was green then the number of pieces he has reserved will be incremented by one
                                    } else {
                                        players[1].captured_pieces += 1;//if the lastcolor was not red then the number of pieces he has captured will be incremented by one
                                    }
                                }
                                struct square *temp = NULL;//declaring a linked list and assigning NULL to it
                                HEAD[r][c] = temp;//assigning the new empty linked list to HEAD[r][c] which was the position from which was the piece moved from and this empties the square from any pieces
                                print_board2(board, HEAD);//prints the new board
                                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                       players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);//prints out the second player name,pieces he has reserved,pieces he has captured
                            } else {
                                struct square *temp = NULL;//declaring a linked list and assigning NULL to it
                                HEAD[r][c] = temp;//assigning the new empty linked list to HEAD[r][c] which was the position from which was the piece moved from and this empties the square from any pieces
                                print_board2(board, HEAD);//prints the new board
                                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                       players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);//prints out the second player name,pieces he has reserved,pieces he has captured
                            }
                        } else {
                            printf("INVALID MOVE");//if the player made an illegal move
                        }
                    } else {
                        printf("Either you tried to move an invalid piece or you chose a top color that is not yours!!!\n");//if the player chose a top color thats not his or the piece is invalid
                    }
                }
            }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if (k == 1) {//if the player chose to move a piece from his reserved pieces he has
                if (i % 2 == 0) {//this is to decide player turn it is
                    if (players[0].own_pieces_stock == 0) {//checks whether theirs no pieces reserved by the player
                        printf("You have no pieces reserved!!!\n");//if theirs no pieces reserved the player cant move any pieces and this is printed out to the player
                    } else {
                        printf("%s turn(RED)\n", players[0].name);//if theirs is pieces reserved then the game continues

                        printf("Enter the row where you want to place the stack : \n");
                        scanf("%d", &r2);//asking for the row of the piece to be moved to
                        printf("Enter the column where you want to place the stack :  \n");
                        scanf("%d", &c2);//asking for the column of the piece to be moved to

                        HEAD[r2][c2] = push1(HEAD[r2][c2], 1, RED);//combining the stack/piece
                        players[0].own_pieces_stock--;//decrementing the pieces reserved by one
                        board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;//assigning the top color of the new combined stack to the board color which will be used later to calculate the winner
                        if (getCount(HEAD[r2][c2]) >5) {//this contains the stack to be of size 5
                            while (getCount(HEAD[r2][c2]) > 5) {//a function which counts the number of pieces in the square
                                color lastcolor;//intialising an enum variable color
                                struct square *curr, *pre, *node;//intialising 3 linked lists
                                curr = HEAD[r2][c2];//assigning the new combined stack/piece linked list to curr
                                node = HEAD[r2][c2];//assigning the new combined stack/piece linked list to node
                                while (curr->next) {//traversing until the end of the linked list and storing the node before the last to pre
                                    pre = curr;
                                    curr = curr->next;
                                }
                                lastcolor = curr->color22;//storing the last color of the stack/piece to lastcolor
                                pre->next = curr->next;//assigning the second last node to NULL
                                HEAD[r2][c2] = node;//assigning the new linked list back to head
                                if (lastcolor == RED) {//we only calculate for the red player since it was the red player move and the top color must be red
                                    players[0].own_pieces_stock += 1;//if the lastcolor was red then the number of pieces he has reserved will be incremented by one
                                } else {
                                    players[0].captured_pieces += 1;//if the lastcolor was green then the number of pieces he has reserved will be incremented by one
                                }
                            }
                            print_board2(board, HEAD);//prints the new board
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);//prints out the first player name,pieces he has reserved,pieces he has captured
                        } else {
                            print_board2(board, HEAD);//prints the new board
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[0].name, players[0].own_pieces_stock, players[0].captured_pieces);//prints out the first player name,pieces he has reserved,pieces he has captured
                        }
                    }
                } else {
                    if (players[1].own_pieces_stock == 0) {//checks whether theirs no pieces reserved by the player
                        printf("You have no pieces reserved!!!\n");//if theirs no pieces reserved the player cant move any pieces and this is printed out to the player
                    } else {
                        printf("%s turn(GREEN)\n", players[1].name);
                        printf("Enter the row where you want to place the stack : \n");
                        scanf("%d", &r2);//asking for the row of the piece to be moved to
                        printf("Enter the column where you want to place the stack :  \n");
                        scanf("%d", &c2);//asking for the column of the piece to be moved to
                        HEAD[r2][c2] = push1(HEAD[r2][c2], 1, GREEN);//combining the stack/piece
                        players[0].own_pieces_stock--;//decrementing the pieces reserved by one
                        board[r2][c2].stack->p_color = HEAD[r2][c2]->color22;//assigning the top color of the new combined stack to the board color which will be used later to calculate the winner
                        if (getCount(HEAD[r2][c2]) >5) {//a function which counts the number of pieces in the square
                            while (getCount(HEAD[r2][c2]) > 5) {//this contains the stack to be of size 5
                                color lastcolor;//initializing an enum variable color
                                struct square *curr, *pre, *node;//initialising 3 linked lists
                                curr = HEAD[r2][c2];//assigning the new combined stack/piece linked list to curr
                                node = HEAD[r2][c2];//assigning the new combined stack/piece linked list to node
                                while (curr->next) {//traversing until the end of the linked list and storing the node before the last to pre
                                    pre = curr;
                                    curr = curr->next;
                                }
                                lastcolor = curr->color22;//storing the last color of the stack/piece to lastcolor
                                pre->next = curr->next;//assigning the second last node to NULL
                                HEAD[r2][c2] = node;//assigning the new linked list back to head
                                if (lastcolor == GREEN) {//we only calculate for the green player since it was the green player move and the top color must be green
                                    players[1].own_pieces_stock += 1;//if the lastcolor was green then the number of pieces he has reserved will be incremented by one
                                } else {
                                    players[1].captured_pieces += 1;//if the lastcolor was red then the number of pieces he has captured will be incremented by one
                                }
                            }
                            print_board2(board, HEAD);//prints the new board
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);//prints out the second player name,pieces he has reserved,pieces he has captured
                        } else {
                            print_board2(board, HEAD);//prints the new board
                            printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                                   players[1].name, players[1].own_pieces_stock, players[1].captured_pieces);//prints out the second player name,pieces he has reserved,pieces he has captured
                        }
                    }
                }
            }
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if (k == 2) {//if the player choses to print out hte player information
                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                       players[0].name,players[0].own_pieces_stock, players[0].captured_pieces);//prints out the first player name,pieces he has reserved,pieces he has captured
            } else if (k == 3) {//if the player choses to print out hte player information
                printf("%s has %d of his own pieces reserved.\nand has %d of the enemys pieces captured\n",
                       players[1].name,players[1].own_pieces_stock, players[1].captured_pieces);//prints out the second player name,pieces he has reserved,pieces he has captured
            }
           // flag=checkwinner(board,HEAD);
        }
}


