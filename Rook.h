//============================================================
// FILE: Rook.h
//============================================================
#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece {
public:
    // Constructors, assignments, and destructor
    Rook(SDL_Renderer* renderer, Team team);
    ~Rook();

    // Public Methods
    bool isLegalMove(int startX, int startY, int endX, int endY, const std::unique_ptr<ChessPiece> board[8][8]) override;
};
