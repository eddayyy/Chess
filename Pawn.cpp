//============================================================
// FILE: Pawn.cpp
//============================================================
#include "Pawn.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Pawn::Pawn(SDL_Renderer* renderer, Team team)
    : ChessPiece(renderer, team, "Pawn") {}

Pawn::~Pawn(){}

bool Pawn::isLegalMove(int startX, int startY, int endX, int endY)
{
    // Temp definition
    return true;
}


