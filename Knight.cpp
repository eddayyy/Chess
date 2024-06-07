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

/*******************************************************************************
**  Public methods
*******************************************************************************/
bool Knight::isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}