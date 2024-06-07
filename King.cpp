//============================================================
// FILE: King.cpp
//============================================================
#include "King.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
King::King(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "King") {}

King::~King() {}

/*******************************************************************************
**  Public methods
*******************************************************************************/
bool King::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    return abs(endX - startX) <= 1 && abs(endY - startY) <= 1;
}