//============================================================
// FILE: Queen.h
//============================================================
#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece {
public:
	// Constructors, assignments, and destructor
	Queen(SDL_Renderer* renderer, Team team);
	~Queen();

	// Public Methods
	bool isLegalMove(int startX, int startY, int endX, int endY) override;

};

