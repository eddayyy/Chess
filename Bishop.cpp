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
bool Bishop::isLegalMove(int startX, int startY, int endX, int endY) {
    return true;
}
