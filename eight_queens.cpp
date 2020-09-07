#include "eight_queens.hpp"

#include <bitset>
#include <iostream>

bool isSafe(unsigned char const (& board)[8], int row, unsigned char column) {
    unsigned char diag_right = column >> 1;
    unsigned char diag_left = column << 1;
    for (int check_row = row -1; check_row >= 0; --check_row) {
        if (board[check_row] & (diag_left | column | diag_right)) {
            return false;
        }
        diag_right = diag_right >> 1;
        diag_left = diag_left << 1;
    }
    return true;
}

void printBoard(unsigned char const (& board)[8]) {
    static int boardCount = 0;
    std::cout << "Valid Board: " << ++boardCount << '\n';
    for (unsigned char const & row: board) {
        std::cout << "     " << std::bitset<8>(row) << '\n';
    }
    std::cout << "---\n\n";

}

void addQueen(unsigned char (& board)[8], int row) {
    if (row >= sizeof(board)) {
        printBoard(board);
    } else {
        unsigned char column = 0x80;
        while(column) {
            if (isSafe(board, row, column)) {
                board[row] = column;
                addQueen(board, row + 1);
            }
            column = column >> 1;
        }
        board[row] = column;
    }
}