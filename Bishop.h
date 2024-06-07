//============================================================
// FILE: Bishop.h
//============================================================
#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece {
public:
	// Constructors, assignments, and destructor
	Bishop(SDL_Renderer* renderer, Team team);
	~Bishop();

	// Public Methods
	bool isLegalMove(int startX, int startY, int endX, int endY) override;

};

