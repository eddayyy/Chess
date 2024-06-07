//============================================================
// FILE: Rook.cpp
//============================================================
#include "Rook.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Rook::Rook(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "Rook") {}

Rook::~Rook() {}

/*******************************************************************************
**  Public methods
*******************************************************************************/
bool Rook::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    if (startX != endX && startY != endY) {
        return false;
    }
    return true;
}