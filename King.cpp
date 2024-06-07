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
bool King::isLegalMove(int startX, int startY, int endX, int endY) {
    return true;
}
