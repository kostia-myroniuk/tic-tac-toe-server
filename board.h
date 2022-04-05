#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>
#include <map>

#include "cell.h"
#include "board_size.h"

enum class BoardState {
    UNFINISHED,
    PLAYER_X_WON,
    PLAYER_O_WON,
    DRAW
};

class Board
{
public:
    Board(int _size, int _winSequenceSize);
    int GetSize();
    int GetWinSequenceSize();
    Cell* GetCell(int row, int column);
    bool SetCellMark(int row, int column, CellMark mark);
    BoardState GetBoardState();

private:
    int size;
    int winSequenceSize;
    std::vector<Cell> cells;
};

#endif // BOARD_H
