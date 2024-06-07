//============================================================
// FILE: Knight.cpp
//============================================================
#include "Knight.h"

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/
Knight::Knight(SDL_Renderer* renderer, Team team)
	: ChessPiece(renderer, team, "Knight") {}

Knight::~Knight(){}

bool Knight::isLegalMove(int startX, int startY, int endX, int endY)
{
    // Temp definition
    return true;
}