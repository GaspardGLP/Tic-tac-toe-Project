#include <stdio.h>

//Display Board Function
void display_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %c  ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}


//Check if board is full or not
int check_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.') {
                return 0;
            }
        }
    }
    return 1;
}

//Check lines, colognes and diagonals
int victory_handling(char board[3][3]) {
    int winner = 0;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {
            winner = 1;
            return winner;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '.') {
            winner = 1;
            return winner;
        }
    }
}

int main() {
    display_board(3);

}