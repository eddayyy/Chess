//============================================================
// FILE: ImagePathGenerator.cpp
//============================================================
#include "ImagePathGenerator.h"

std::string ImagePathGenerator::generateImagePath(Team team, const std::string& pieceType) {
    std::string basePath = "textures/";
    std::string colorStr;

    // Determine the appropriate color string based on the input parameter
    switch (team) {
    case Team::WHITE:
        colorStr = "light";
        break;
    case Team::BLACK:
        colorStr = "dark";
        break;
    default:
        return "";
    }

    // Combine the base path, color string, and piece string to form the complete image path
    return basePath + colorStr + pieceType + ".png";
}