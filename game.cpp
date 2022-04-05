#include "game.h"

Game::Game(GameSettings *settings)
    : board(settings->GetBoardSize(), settings->GetWinSequenceSize())
{
    currentPlayerSide = PlayerSide::X;
}

Board *Game::GetBoard()
{
    return &board;
}

QString Game::JsonTurnHistory()
{
    QString jsonResult = "{\n\"turns\": [\n";

    for (int index = 0; index < turnHistory.size(); index++) {
        jsonResult += "\t{\n";

        Turn* turn = turnHistory[index];

        jsonResult += "\"row\": ";
        jsonResult += QString::number(turn->GetRow(), 10);
        jsonResult += ",\n";

        jsonResult += "\"column\": ";
        jsonResult += QString::number(turn->GetColumn(), 10);
        jsonResult += ",\n";

        jsonResult += "\"player\": ";
        if (turn->GetPlayerSide() == PlayerSide::X) {
            jsonResult += "\"X\"";
        }
        else {
            jsonResult += "\"O\"";
        }

        if (index < turnHistory.size() - 1) {
            jsonResult += "\t},\n";
        }
        else {
            jsonResult += "\t}\n";
        }
    }

    jsonResult += "\t]\n}";

    return jsonResult;
}

bool Game::MakeTurn(Turn* turn)
{
    if (currentPlayerSide == turn->GetPlayerSide()) {
        CellMark cellMark = PlayerSideMark(turn->GetPlayerSide());

        bool successful = board.SetCellMark(turn->GetRow(), turn->GetColumn(), cellMark);
        if (successful) {
            currentPlayerSide = OppositePlayerSide(currentPlayerSide);
            turnHistory.push_back(turn);
            return true;
        }
    }

    return false;
}

PlayerSide Game::OppositePlayerSide(PlayerSide playerSide)
{
    if (playerSide == PlayerSide::X) {
        return PlayerSide::O;
    }
    else {
        return PlayerSide::X;
    }
}

CellMark Game::PlayerSideMark(PlayerSide playerSide)
{
    if (playerSide == PlayerSide::X) {
        return CellMark::X;
    }
    else {
        return CellMark::O;
    }
}
