//============================================================
// FILE: Knight.h
//============================================================
#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece {
public:
	// Constructors, assignments, and destructor
	Knight(SDL_Renderer* renderer, Team team);
	~Knight();

	// Public Methods
	bool isLegalMove(int startX, int startY, int endX, int endY) override;

};

