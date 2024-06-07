//============================================================
// FILE: King.h
//============================================================
#pragma once
#include "ChessPiece.h"

class King : public ChessPiece {
public:
    // Constructors, assignments, and destructor
    King(SDL_Renderer* renderer, Team team);
    ~King();

    // Public Methods
    bool isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) override;
};

