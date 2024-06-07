//============================================================
// FILE: ChessPiece.h
//============================================================
#pragma once
#include <SDL.h>
#include <memory>
#include <string>

enum class Team {
	NONE,
	BLACK,
	WHITE
};

class ChessPiece {
public:

	// Constructors, assignments, and destructor
	ChessPiece(SDL_Renderer* renderer, Team team, const std::string& pieceType);
	virtual ~ChessPiece();

	// Public methods
	void render(SDL_Renderer* renderer, int x, int y, int squareSize);
	virtual bool isLegalMove(int startX, int startY, int endX, int endY) = 0;
	void setPosition(int x, int y);

	// Accessors
	Team team();
	SDL_Texture* texture();
	int _screenX, _screenY;

private:
	// Private members

	SDL_Texture* _texture;
	Team _team;
};


