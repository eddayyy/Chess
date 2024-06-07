//============================================================
// FILE: Pawn.h
//============================================================
#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
	// Constructors, assignments, and destructor
	Pawn(SDL_Renderer* renderer, Team team);
	~Pawn();

	// Public Methods
	bool isLegalMove(int startX, int startY, int endX, int endY) override;

};

