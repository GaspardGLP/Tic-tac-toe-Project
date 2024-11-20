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
            printf("-----+-----+-----\n");
        }
    }
    printf("\n");
}

//Check if board is full or not
int check_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
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

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {
        winner = 1;
        return winner;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {
        winner = 1;
        return winner;
    }
    return winner;
}

// Game Function
void game() {
    char board[3][3];
    int lin, col;
    int turns = 0;
    char player = 'X';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '.';
        }
    }

    printf("Welcome to Tic-Tac-Toe Game\n");
    display_board(board);

    while (1) {
        printf("Player %c, enter your move (line and column between 1 and 3):", player);
        scanf("%d %d", &lin, &col);

        if (lin < 1 || lin > 3 || col < 1 || col > 3) {
            printf("Invalid position, Please enter a line and colum between 1 and 3.\n");
            continue;
        }

        lin--;
        col--;

        if (board[lin][col] != '.') {
            printf("This cell is already occupied! Try again.\n");
            continue;
        }

        board[lin][col] = player;
        display_board(board);

        if (victory_handling(board)) {
            printf("Congratulations! Player %c has won!\n", player);
            break;
        }

        if (check_board(board)) {
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
        turns++;
    }
    printf("Game Over. Thanks for playing!\n");
}

int main() {
    game();
    return 0;
}
