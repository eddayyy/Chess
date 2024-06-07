//============================================================
// FILE: Queen.cpp
//============================================================
#include "Queen.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Queen::Queen(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "Queen") {}

Queen::~Queen() {}

/*******************************************************************************
**  Public methods
*******************************************************************************/
bool Queen::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    if (startX != endX && startY != endY && abs(endX - startX) != abs(endY - startY)) {
        return false;
    }
    return true;
}