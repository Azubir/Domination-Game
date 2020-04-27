//
// Created by azubi on 21/04/2020.
//

#include "CheckingValidity.h"
#include <stdio.h>
#include <stdlib.h>

int validity(int getcount,int r,int c,int r2,int c2) {
    int flag = 0;//0 is false and 1 is true

    //in each case theirs an array with the all the valid moves given the situation of the size of the stack the program will go from one
    //condition to another until a valid move/condition  is satisfied if so flag will be assigned 1
    //and the loop is exited and it will return 1 which means its a valid move
    //otherwise if no condition is evaluated to true flag with the value 0 is returned which indicates
    //otherwise if no condition is evaluated to true flag with the value 0 is returned which indicates
                                       //its an invalid move

    if (c == c2) {//This is when player moved the piece to a different row but the same column
        if (getcount == 1) {//when the player moved one step
            for (int i = 0; i < 2; i++) {
                int one[] = {r + 1, r - 1};//list of valid steps the player could take
                if (r2 == one[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 2) {//when the player moved two steps
            int two[] = {r + 1, r - 1, r + 2, r - 2};//list of valid steps the player could take
            for (int i = 0; i < 4; i++) {
                if (r2 == two[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 3) {//when the player moved three steps
            int three[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3};//list of valid steps the player could take
            for (int i = 0; i < 6; i++) {
                if (r2 == three[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 4) {//when the player moved four steps
            int four[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3, r + 4, r - 4};//list of valid steps the player could take
            for (int i = 0; i < 8; i++) {
                if (r2 == four[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 5) {//when the player moved five steps
            int five[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3, r + 4, r - 4, r + 5, r - 5};//list of valid steps the player could take
            for (int i = 0; i < 10; i++) {
                if (r2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    } else if (r == r2) {//This is when player moved the piece to a different column but the same column
        if (getcount == 1) {//when the player moved one step
            int one[] = {c + 1, c - 1};//list of valid steps the player could take
            for (int i = 0; i < 2; i++) {//if it evaluates to true the loop is broken and returning 1;
                if (c2 == one[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 2) {//when the player moved two steps
            int two[] = {c + 1, c - 1, c + 2, c - 2};//list of valid steps the player could take
            for (int i = 0; i < 4; i++) {
                if (c2 == two[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 3) {//when the player moved four steps
            int three[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};//list of valid steps the player could take
            for (int i = 0; i < 6; i++) {
                if (c2 == three[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 4) {//when the player moved four steps
            int four[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4};//list of valid steps the player could take
            for (int i = 0; i < 8; i++) {
                if (c2 == four[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 5) {//when the player moved five steps
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4, c + 5, c - 5};//list of valid steps the player could take
            for (int i = 0; i < 10; i++) {
                if (c2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 2) {//this when the size of the square is two and the player move the pieces to a different row and column
        if (r2 - r == 1 || r2 - r == -1) {//when the player moved the piece one step while the size of the square is two
            int two[] = {c + 1, c - 1};//list of valid steps the player could take
            for (int i = 0; i < 2; i++) {
                if (c2 == two[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 3) {//this when the size of the square is three and the player move the pieces to a different row and column
        if (r2 - r == 1 || r2 - r == -1) {//when the player moved the piece one step while the size of the square is three
            int three[] = {c + 1, c - 1, c + 2, c - 2};//list of valid steps the player could take
            for (int i = 0; i < 4; i++) {
                if (c2 == three[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2 || r2 - r == -2) {//when the player moved the piece two step while the size of the square is three
            int three[] = {c + 1, c - 1};//list of valid steps the player could take
            for (int i = 0; i < 2; i++) {
                if (c2 == three[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 4) {//this when the size of the square is four and the player move the pieces to a different row and column
        if (r2 - r == 1) {//when the player moved the piece one step while the size of the square is four
            int four[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};//list of valid steps the player could take
            for (int i = 0; i < 6; i++) {
                if (c2 == four[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2) {//when the player moved the piece two step while the size of the square is four
            int four[] = {c + 1, c - 1, c + 2, c - 2};//list of valid steps the player could take
            for (int i = 0; i < 4; i++) {
                if (c2 == four[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 3) {//when the player moved the piece three step while the size of the square is four
            int four[] = {c + 1, c - 1};//list of valid steps the player could take
            for (int i = 0; i < 2; i++) {
                if (c2 == four[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 5) {//this when the size of the square is five and the player move the pieces to a different row and column
        if (r2 - r == 1) {//when the player moved the piece one step while the size of the square is five
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4};//list of valid steps the player could take
            for (int i = 0; i < 8; i++) {
                if (c2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2) {//when the player moved the piece two step while the size of the square is five
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};//list of valid steps the player could take
            for (int i = 0; i < 6; i++) {
                if (c2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 3) {//when the player moved the piece three step while the size of the square is five
            int five[] = {c + 1, c - 1, c + 2, c - 2};//list of valid steps the player could take
            for (int i = 0; i < 4; i++) {
                if (c2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 4) {//when the player moved the piece four step while the size of the square is five
            int five[] = {c + 1, c - 1};//list of valid steps the player could take
            for (int i = 0; i < 2; i++) {
                if (c2 == five[i]) {//if it evaluates to true the loop is broken and returning 1;
                    flag = 1;
                    break;
                }
            }
        }
    }

    return flag;
}