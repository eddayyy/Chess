//============================================================
// FILE: ChessPiece.cpp
//============================================================
#include "Pawn.h"
#include "ChessPiece.h"
#include "ImagePathGenerator.h"
#include <iostream>
#include <SDL_image.h>

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Constructor
ChessPiece::ChessPiece(SDL_Renderer* renderer, Team team, const std::string& pieceType)
    : _team(team)
{
    std::string imagePath = ImagePathGenerator::generateImagePath(team, pieceType);

    SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());
    if (!imageSurface)
    {
        std::cerr << "Unable to load image \"" << imagePath << "\"! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    _texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    if (!_texture)
    {
        std::cerr << "Unable to create texture from \"" << imagePath << "\"! SDL Error: " << SDL_GetError() << std::endl;
    }
}

// Destructor
ChessPiece::~ChessPiece()
{
    SDL_DestroyTexture(_texture);
}


/*******************************************************************************
**  Public methods
*******************************************************************************/

void ChessPiece::render(SDL_Renderer* renderer, int x, int y, int squareSize)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = squareSize;
    destRect.h = squareSize;

    SDL_RenderCopy(renderer, _texture, NULL, &destRect);
}

void ChessPiece::setPosition(int x, int y)
{
    _screenX = x;
    _screenY = y;
}

/*******************************************************************************
**  Accessors
*******************************************************************************/
Team ChessPiece::team() const {
    return _team;
}

SDL_Texture* ChessPiece::texture() {
    return _texture;
}

std::string ChessPiece::pieceType() const {
    return _pieceType;
}
