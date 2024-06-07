//============================================================
// FILE: Bishop.cpp
//============================================================
#include "Bishop.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Bishop::Bishop(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "Bishop") {}

Bishop::~Bishop() {}

/*******************************************************************************
**  Public methods
*******************************************************************************/
bool Bishop::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    if (abs(endX - startX) != abs(endY - startY)) {
        return false;
    }
    return true;
}