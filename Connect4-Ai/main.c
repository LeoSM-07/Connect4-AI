//
// main.c
// Connect4-Ai
//
// Created by LeoSM_07 on 1/3/23.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define width 7
#define height 6
void placePiece(int player, int column, int board[][7]);
void populateBoard(long n, int board[][7]);
void printBoard(long n);

int main () {
    long currentBoard = 23;

    currentBoard = 44455554221;
    printBoard(currentBoard);
    return 0;
}

bool canPlay(int col) {
    return true;
};

/// Add a piece in a give column. Will add to the first empty spot starting from the bottom.
/// - Parameters:
///   - player: The player who the piece to be added belongs to
///   - column: The column to add the piece
///   - board: The board to add the piece on
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

/// Fill out the board based on a specific `int` instruction set
/// - Parameters:
///   - n: The state of the game, each turn represented by a digit of the int
///   - board: The game board
void populateBoard(long n, int board[][7]) {
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
        /* uncomment for verbose printing */
        // printf("player %d went in: %d\n", player, column);
        placePiece(player, column, board);
    }
}

/// Nicely prints out the board as it is passed
void printBoard(long n) {
    int board[6][7] = {0};
    populateBoard(n, board);
    printf("\nCurrent Board (%ld):\n\n", n);

    int i,j;
    for(i=5; i>=0; i--) {
        printf("%d ", i);
        for (j=0; j<7; j++) {
            int current = board[i][j];

            switch (current) {
            case 0:
                printf("[ ] ");
                break;
            case 1:
                printf("[X] ");
                break;
            case 2:
                printf("[O] ");
                break;
            }

        }
        printf("\n");
    }
    printf("   0   1   2   3   4   5   6\n");
}




