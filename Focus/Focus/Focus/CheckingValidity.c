//
// Created by azubi on 21/04/2020.
//

#include "CheckingValidity.h"
#include <stdio.h>
#include <stdlib.h>

int validity(int getcount,int r,int c,int r2,int c2) {
    int flag = 0;//0 is false and 1 is true


    if (c == c2) {
        if (getcount == 1) {
            for (int i = 0; i < 2; i++) {
                int one[] = {r + 1, r - 1};
                if (r2 == one[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 2) {
            int two[] = {r + 1, r - 1, r + 2, r - 2};
            for (int i = 0; i < 4; i++) {
                if (r2 == two[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 3) {
            int three[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3};
            for (int i = 0; i < 6; i++) {
                if (r2 == three[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 4) {
            int four[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3, r + 4, r - 4};
            for (int i = 0; i < 8; i++) {
                if (r2 == four[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 5) {
            int five[] = {r + 1, r - 1, r + 2, r - 2, r + 3, r - 3, r + 4, r - 4, r + 5, r - 5};
            for (int i = 0; i < 10; i++) {
                if (r2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    } else if (r == r2) {
        if (getcount == 1) {
            int one[] = {c + 1, c - 1};
            for (int i = 0; i < 2; i++) {
                if (c2 == one[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 2) {
            int two[] = {c + 1, c - 1, c + 2, c - 2};
            for (int i = 0; i < 4; i++) {
                if (c2 == two[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 3) {
            int three[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};
            for (int i = 0; i < 6; i++) {
                if (c2 == three[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 4) {
            int four[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4};
            for (int i = 0; i < 8; i++) {
                if (c2 == four[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (getcount == 5) {
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4, c + 5, c - 5};
            for (int i = 0; i < 10; i++) {
                if (c2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 2) {
        if (r2 - r == 1 || r2 - r == -1) {
            int two[] = {c + 1, c - 1};
            for (int i = 0; i < 2; i++) {
                if (c2 == two[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 3) {
        if (r2 - r == 1 || r2 - r == -1) {
            int three[] = {c + 1, c - 1, c + 2, c - 2};
            for (int i = 0; i < 4; i++) {
                if (c2 == three[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2 || r2 - r == -2) {
            int three[] = {c + 1, c - 1};
            for (int i = 0; i < 2; i++) {
                if (c2 == three[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 4) {
        if (r2 - r == 1) {
            int four[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};
            for (int i = 0; i < 6; i++) {
                if (c2 == four[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2) {
            int four[] = {c + 1, c - 1, c + 2, c - 2};
            for (int i = 0; i < 4; i++) {
                if (c2 == four[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 3) {
            int four[] = {c + 1, c - 1};
            for (int i = 0; i < 2; i++) {
                if (c2 == four[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    } else if (getcount == 5) {
        if (r2 - r == 1) {
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3, c + 4, c - 4};
            for (int i = 0; i < 8; i++) {
                if (c2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 2) {
            int five[] = {c + 1, c - 1, c + 2, c - 2, c + 3, c - 3};
            for (int i = 0; i < 6; i++) {
                if (c2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 3) {
            int five[] = {c + 1, c - 1, c + 2, c - 2};
            for (int i = 0; i < 4; i++) {
                if (c2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        } else if (r2 - r == 4) {
            int five[] = {c + 1, c - 1};
            for (int i = 0; i < 2; i++) {
                if (c2 == five[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    }

/*if(flag==1){
    printf("VALID");
}else{
    printf("INVALID");
}*/

    return flag;
}