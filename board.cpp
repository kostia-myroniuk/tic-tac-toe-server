#include "board.h"

Board::Board(int _size, int _winSequenceSize)
{
    size = std::clamp(_size, MIN_BOARD_SIZE, MAX_BOARD_SIZE);
    winSequenceSize = std::clamp(_winSequenceSize, MIN_BOARD_SIZE, size);

    cells.reserve(size * size);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cells.push_back(Cell(row + 1, col + 1));
        }
    }
}

int Board::GetSize()
{
    return size;
}

int Board::GetWinSequenceSize()
{
    return winSequenceSize;
}

Cell* Board::GetCell(int row, int column)
{
    if (row > 0 && row < size && column > 0 && column < size) {
        return &cells[row * size + column];
    }
    else {
        return nullptr;
    }
}

BoardState Board::GetBoardState()
{
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (cells[row * size + col].GetMark() == CellMark::UNMARKED) {
                return BoardState::UNFINISHED;
            }
        }
    }

    std::vector<CellMark> playerMarks { CellMark::X, CellMark::O };
    std::map<CellMark, BoardState> markStateMap {
        { CellMark::X, BoardState::PLAYER_X_WON },
        { CellMark::O, BoardState::PLAYER_O_WON }
    };

    for (int playerIndex = 0; playerIndex < 2; playerIndex++) {
        CellMark playerMark = playerMarks[playerIndex];

        // Horizontal check
        for (int row = 0; row < size; row++) {
            int sequenceSize = 0;
            for (int col = 0; col < size; col++) {
                if (cells[row * size + col].GetMark() == playerMark) {
                    sequenceSize++;
                    if (sequenceSize == winSequenceSize) {
                        return markStateMap[playerMark];
                    }
                }
                else {
                    sequenceSize = 0;
                }
            }
        }

        // Vertical check
        for (int col = 0; col < size; col++) {
            int sequenceSize = 0;
            for (int row = 0; row < size; row++) {
                if (cells[row * size + col].GetMark() == playerMark) {
                    sequenceSize++;
                    if (sequenceSize == winSequenceSize) {
                        return markStateMap[playerMark];
                    }
                }
                else {
                    sequenceSize = 0;
                }
            }
        }

        // Diagonal check
        for (int row = 0; row <= size - winSequenceSize; row++) {
            for (int col = 0; col <= size - winSequenceSize; col++) {
                int sequenceSize = 0;
                for (int shift = 0; shift < winSequenceSize; shift++) {
                    if (cells[(row + shift) * size + col + shift].GetMark() == playerMark) {
                        sequenceSize++;
                    }
                }
                if (sequenceSize == winSequenceSize) {
                    return markStateMap[playerMark];
                }
            }
        }
    }

    return BoardState::DRAW;
}
