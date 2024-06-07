//============================================================
// FILE: Pawn.cpp
//============================================================
#include "Pawn.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Pawn::Pawn(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "Pawn") {}

Pawn::~Pawn() {}

bool Pawn::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    int direction = (team() == Team::WHITE) ? -1 : 1;
    int startRow = (team() == Team::WHITE) ? 6 : 1;

    if (startX == endX) {
        if (endY == startY + direction) {
            return true;
        }
        if (startY == startRow && endY == startY + 2 * direction) {
            return true;
        }
    }
    else if (abs(startX - endX) == 1 && endY == startY + direction) {
        if (board[endX][endY] && board[endX][endY]->team() != team()) {
            return true;
        }
    }
    return false;
}
