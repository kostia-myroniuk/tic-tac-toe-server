#include "cell.h"

Cell::Cell(int _row, int _column)
{
    row = _row;
    column = _column;
    mark = CellMark::UNMARKED;
}

int Cell::GetRow()
{
    return row;
}

int Cell::GetColumn()
{
    return column;
}

CellMark Cell::GetMark()
{
    return mark;
}

bool Cell::SetMark(CellMark _mark)
{
    if (mark == CellMark::UNMARKED) {
        mark = _mark;
        return true;
    }
    else {
        return false;
    }
}
