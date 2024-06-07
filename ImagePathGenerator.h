//============================================================
// FILE: ImagePathGenerator.h
//============================================================
#pragma once
#include <string>
#include "ChessPiece.h"  // Assuming Team enum is defined here

class ImagePathGenerator {
public:
    static std::string generateImagePath(Team team, const std::string& pieceType);
};
