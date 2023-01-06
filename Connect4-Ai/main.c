//
// main.c
// Connect4-Ai
//
// Created by LeoSM_07 on 1/3/23.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(int board[][7]) {
    printf("\nCurrent Board:\n\n");

    int i,j;
    for(i=5; i>=0; i--) {
        printf("%d ", i);
        for (j=0; j<7; j++) {
            if (board[i][j] == 0) {
                printf("[ ] ");
            } else {
                printf("[%d] ", board[i][j]);
            }

        }
        printf("\n");
    }
    printf("   0   1   2   3   4   5   6\n");
}

void placePiece(int player, int column, int board[][7]) {
    int boardColumn[6];

    // populate boardColumn
    for (int i = 0; i < 6; i++) {
        boardColumn[i] = board[i][column];
    }

    for (int i = 0; i < 6; i++) {
        if (boardColumn[i] == 0) {
            board[i][column] = player;
            break;
        }
    }
}

void populateBoard(int n, int board[][7]) {
    int i = 0;
    int digits[42];
    while (n > 0) {
        int digit = n % 10;
        digits[i] = digit-1;
        i++;
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--) {
        int player = j%2+1;
        int column = digits[j];
        printf("player %d went in: %d\n", player, column);
        placePiece(player, column, board);
    }
}

int main () {
    int board[6][7] = {0};

    populateBoard(4453, board);
    printBoard(board);
    return 0;
}




