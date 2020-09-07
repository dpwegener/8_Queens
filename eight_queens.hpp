#if !defined(EIGHT_QUEENS)
#define EIGHT_QUEENS

bool isSafe(unsigned char const (& board)[8], int row, unsigned char column);

void printBoard(unsigned char const (& board)[8]);

void addQueen(unsigned char (& board)[8], int row);

#endif // EIGHT_QUEENS
