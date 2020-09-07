#include "eight_queens.hpp"
#include <iostream>

int main(int, char**) {
    std::cout << "Finding all safe 8 queen boards\n\n";

    unsigned char board[8]{0,0,0,0,0,0,0,0};
    addQueen(board, 0);
    
    std::cout << "Found all boards\n";
}
