#include <stdio.h>
#include <stdbool.h>

int n = 8;
int chessboard[8][8] = {0}; // Initializes all elements to 0 on a 4x4 chessboard

typedef struct {
    int row;
    int col; //initialises rows and columns in a structure called position
} position;

bool safe_position(position p, int n) { //finds safe positions for a queen 
    for (int i = 0; i < n; i++) {
        if (chessboard[p.row][i] || chessboard[i][p.col])
            return false;
        if (p.row + i < n && p.col + i < n && chessboard[p.row + i][p.col + i]) //checks if there's a queen in the same row
            return false;
        if (p.row - i >= 0 && p.col - i >= 0 && chessboard[p.row - i][p.col - i]) //checks if there's a queen in the same column
            return false;
        if (p.row + i < n && p.col - i >= 0 && chessboard[p.row + i][p.col - i]) //checks diagonal from left to right downwards
            return false;
        if (p.row - i >= 0 && p.col + i < n && chessboard[p.row - i][p.col + i]) //checks diagonal from right to left upwards
            return false;
    }
    return true;
}

void printchessboard(int n) { //shows the current state of the chessboard
    for (int i = 0; i < n; i++) { //goes through the rows
        for (int j = 0; j < n; j++) { //goes through the columns
            printf("%d ", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void find_all_solutions(int n, int row) { //finds all possible solutions meaning all possible ways all n queens can be in different ways without attacking each other 
    if (row == n) {
        printchessboard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        position p = {row, col};

        if (safe_position(p, n)) {
            chessboard[p.row][p.col] = 1; //if the place is safe, it places a queen there and then moves to the next row
            find_all_solutions(n, row + 1);
            chessboard[p.row][p.col] = 0; // Backtracks if there's a clash in the safe positions
        }
    }
}

int main() {
    find_all_solutions(n, 0);
    return 0;
}
