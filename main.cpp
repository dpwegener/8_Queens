#include "eight_queens.hpp"
#include "n_queens.hpp"
#include <iostream>

int main(int, char**) {
    std::cout << "Finding all safe 8 queen boards\n\n";

    unsigned char board[8]{0,0,0,0,0,0,0,0};
    addQueen(board, 0);
    
    std::cout << "Found all 8 queen boards\n";

    std::cout << "Finding all valid 9 queen boards\n\n";
    N_Queens<9> queens9;
    queens9.addQueen(0);
    
    std::cout << "Found all 9 queen boards\n";

    std::cout << "Finding all valid 10 queen boards\n\n";
    N_Queens<10> nqueens;
    nqueens.addQueen(0);
    
    std::cout << "Found all 10 queen boards\n";

    std::cout << "Finding all valid 11 queen boards\n\n";
    N_Queens<11> queens11;
    queens11.addQueen(0);
    
    std::cout << "Found all 11 queen boards\n";

    std::cout << "Finding all valid 12 queen boards\n\n";
    N_Queens<12> queens12;
    queens12.addQueen(0);
    
    std::cout << "Found " << queens12.validBoardCount << " 12 queen boards\n";

    std::cout << "Finding all valid 13 queen boards\n\n";
    N_Queens<13> queens13;
    queens13.addQueen(0);
    
    std::cout << "Found " << queens13.validBoardCount << " 13 queen boards\n";
}
