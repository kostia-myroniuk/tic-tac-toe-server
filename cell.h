#ifndef CELL_H
#define CELL_H

enum class CellMark {
    UNMARKED,
    X,
    O
};

class Cell
{
public:
    Cell(int _row, int _column);
    int GetRow();
    int GetColumn();
    CellMark GetMark();
    bool SetMark(CellMark _mark);

private:
    int row;
    int column;
    CellMark mark;
};

#endif // CELL_H
