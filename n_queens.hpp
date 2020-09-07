#if !defined(N_QUEENS)
#define N_QUEENS

#include <bitset>
#include <cstddef>
#include <iostream>

template<std::size_t QUEENS>
struct N_Queens {

std::bitset<QUEENS> board[QUEENS];
int validBoardCount = 0;

void printBoard() const {
    std::cout << "Valid Board: " << validBoardCount << '\n';
    for (std::bitset<QUEENS> const & row: board) {
        std::cout << "     " << row << '\n';
    }
    std::cout << "---\n\n";
}

bool isSafe(int row, std::bitset<QUEENS> const & column) const {
    std::bitset<QUEENS> diag_right = column >> 1;
    std::bitset<QUEENS> diag_left = column << 1;
    for (int check_row = row -1; check_row >= 0; --check_row) {
        if ((board[check_row] & (diag_left | column | diag_right)).any()) {
            return false;
        }
        diag_right = diag_right >> 1;
        diag_left = diag_left << 1;
    }
    return true;

}

void addQueen(int row) {
    if (row >= QUEENS) {
        ++validBoardCount;
        printBoard();
    } else {
        std::bitset<QUEENS> column{1};
        while(column.any()) {
            if (isSafe(row, column)) {
                board[row] = column;
                addQueen(row + 1);
            }
            column = column << 1;
        }
        board[row] = column;
    }

}
};

#endif // N_QUEENS
