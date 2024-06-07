//============================================================
// FILE: BoardState.cpp
//============================================================
#include "ChessPiece.h"
#include "BoardState.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Constructor
BoardState::BoardState() : currentTurn(Team::WHITE)
{
	SDLinit();
	IMG_Init(IMG_INIT_PNG);
	_window = SDL_CreateWindow("Chess Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_BOARD_SIZE * _SQUARE_SIZE,
		_BOARD_SIZE * _SQUARE_SIZE,
		SDL_WINDOW_SHOWN);

	_renderer = SDL_CreateRenderer(_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

// Destructor
BoardState::~BoardState()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

/*******************************************************************************
**  Accessors
*******************************************************************************/

int BoardState::boardSize() const noexcept
{
	return _BOARD_SIZE;
}

int BoardState::squareSize() const noexcept
{
	return _SQUARE_SIZE;
}

SDL_Window* BoardState::window() const noexcept
{
	return _window;
}

struct PieceInfo {
	std::string type;
	Team team;
	int x;
	int y;
};

/*******************************************************************************
**  Public methods
*******************************************************************************/

int BoardState::SDLinit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize!\nSDL_Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	return 0;
}

void BoardState::initializeBoard()
{
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            _board[x][y] = nullptr;
        }
    }

    std::vector<PieceInfo> initialPieces = {
        // Black back row
        {"Rook", Team::BLACK, 0, 0}, {"Knight", Team::BLACK, 1, 0},
        {"Bishop", Team::BLACK, 2, 0}, {"Queen", Team::BLACK, 3, 0},
        {"King", Team::BLACK, 4, 0}, {"Bishop", Team::BLACK, 5, 0},
        {"Knight", Team::BLACK, 6, 0}, {"Rook", Team::BLACK, 7, 0},

        // Black pawns
        {"Pawn", Team::BLACK, 0, 1}, {"Pawn", Team::BLACK, 1, 1},
        {"Pawn", Team::BLACK, 2, 1}, {"Pawn", Team::BLACK, 3, 1},
        {"Pawn", Team::BLACK, 4, 1}, {"Pawn", Team::BLACK, 5, 1},
        {"Pawn", Team::BLACK, 6, 1}, {"Pawn", Team::BLACK, 7, 1},

        // White back row
        {"Rook", Team::WHITE, 0, 7}, {"Knight", Team::WHITE, 1, 7},
        {"Bishop", Team::WHITE, 2, 7}, {"Queen", Team::WHITE, 3, 7},
        {"King", Team::WHITE, 4, 7}, {"Bishop", Team::WHITE, 5, 7},
        {"Knight", Team::WHITE, 6, 7}, {"Rook", Team::WHITE, 7, 7},

        // White pawns
        {"Pawn", Team::WHITE, 0, 6}, {"Pawn", Team::WHITE, 1, 6},
        {"Pawn", Team::WHITE, 2, 6}, {"Pawn", Team::WHITE, 3, 6},
        {"Pawn", Team::WHITE, 4, 6}, {"Pawn", Team::WHITE, 5, 6},
        {"Pawn", Team::WHITE, 6, 6}, {"Pawn", Team::WHITE, 7, 6},
    };

    for (const auto& pieceInfo : initialPieces) {
        initPiece(pieceInfo.type, pieceInfo.team, pieceInfo.x, pieceInfo.y);
    }
}

void BoardState::initPiece(const std::string& type, Team team, int x, int y)
{
    if (type == "Pawn") {
        _board[x][y] = std::make_unique<Pawn>(_renderer, team);
    }
    else if (type == "Knight") {
        _board[x][y] = std::make_unique<Knight>(_renderer, team);
    }
    else if (type == "Bishop") {
        _board[x][y] = std::make_unique<Bishop>(_renderer, team);
    }
    else if (type == "Rook") {
        _board[x][y] = std::make_unique<Rook>(_renderer, team);
    }
    else if (type == "Queen") {
        _board[x][y] = std::make_unique<Queen>(_renderer, team);
    }
    else if (type == "King") {
        _board[x][y] = std::make_unique<King>(_renderer, team);
    }
    setPosition(x, y, x * _SQUARE_SIZE, y * _SQUARE_SIZE);
}

int BoardState::renderBoard()
{
    initializeBoard();
    bool quit = false;
    SDL_Event e;

    int offsetX = 0, offsetY = 0; // Offsets for dragging
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                int gridX = mouseX / _SQUARE_SIZE;
                int gridY = mouseY / _SQUARE_SIZE;

                if (gridX >= 0 && gridX < _BOARD_SIZE && gridY >= 0 && gridY < _BOARD_SIZE)
                {
                    if (_board[gridX][gridY] && _board[gridX][gridY]->team() == currentTurn)
                    {
                        draggingX = gridX;
                        draggingY = gridY;
                        offsetX = mouseX - gridX * _SQUARE_SIZE;
                        offsetY = mouseY - gridY * _SQUARE_SIZE;
                    }
                }
            }
            else if (e.type == SDL_MOUSEMOTION && draggingX != -1 && draggingY != -1)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                setPosition(draggingX, draggingY, mouseX - offsetX, mouseY - offsetY);
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                int gridX = mouseX / _SQUARE_SIZE;
                int gridY = mouseY / _SQUARE_SIZE;

                if (draggingX != -1 && draggingY != -1)
                {
                    bool moved = movePiece(draggingX, draggingY, gridX, gridY);
                    if (moved) {
                        currentTurn = (currentTurn == Team::WHITE) ? Team::BLACK : Team::WHITE;
                    }
                    setPosition(gridX, gridY, gridX * _SQUARE_SIZE, gridY * _SQUARE_SIZE);

                    draggingX = -1;
                    draggingY = -1;
                }
            }
        }

        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
        SDL_RenderClear(_renderer);

        for (int row = 0; row < _BOARD_SIZE; row++)
        {
            for (int col = 0; col < _BOARD_SIZE; col++)
            {
                if ((row + col) % 2 == 0)
                {
                    SDL_SetRenderDrawColor(_renderer, 240, 217, 181, 255);
                }
                else
                {
                    SDL_SetRenderDrawColor(_renderer, 181, 136, 99, 255);
                }
                SDL_Rect rect;
                rect.x = col * _SQUARE_SIZE;
                rect.y = row * _SQUARE_SIZE;
                rect.w = _SQUARE_SIZE;
                rect.h = _SQUARE_SIZE;
                SDL_RenderFillRect(_renderer, &rect);
            }
        }

        for (int y = 0; y < _BOARD_SIZE; y++) {
            for (int x = 0; x < _BOARD_SIZE; x++) {
                if (_board[x][y]) {
                    int renderX = (x == draggingX && y == draggingY) ? _board[x][y]->_screenX : x * _SQUARE_SIZE;
                    int renderY = (x == draggingX && y == draggingY) ? _board[x][y]->_screenY : y * _SQUARE_SIZE;
                    _board[x][y]->render(_renderer, renderX, renderY, _SQUARE_SIZE);
                }
            }
        }

        SDL_RenderPresent(_renderer);
    }
    return 0;
}

/*******************************************************************************
**  Helper functions
*******************************************************************************/

bool BoardState::movePiece(int startX, int startY, int endX, int endY)
{
    if (_board[startX][startY] &&
        _board[startX][startY]->isLegalMove(startX, startY, endX, endY, _board) &&
        (dynamic_cast<Knight*>(_board[startX][startY].get()) || isPathClear(startX, startY, endX, endY)) &&
        (!_board[endX][endY] || _board[endX][endY]->team() != _board[startX][startY]->team()))
    {
        _board[endX][endY] = std::move(_board[startX][startY]);
        _board[startX][startY] = nullptr;
        return true;
    }
    return false;
}

bool BoardState::isPathClear(int startX, int startY, int endX, int endY)
{
    int dx = (endX - startX == 0) ? 0 : (endX - startX) / abs(endX - startX);
    int dy = (endY - startY == 0) ? 0 : (endY - startY) / abs(endY - startY);

    int x = startX + dx;
    int y = startY + dy;

    while (x != endX || y != endY) {
        if (_board[x][y] != nullptr) {
            return false;
        }
        x += dx;
        y += dy;
    }

    return true;
}

void BoardState::setPosition(int gridX, int gridY, int posX, int posY)
{
    if (_board[gridX][gridY]) {
        _board[gridX][gridY]->_screenX = posX;
        _board[gridX][gridY]->_screenY = posY;
    }
}

void BoardState::setPiece(int x, int y, std::unique_ptr<ChessPiece> piece)
{
    _board[x][y] = std::move(piece);
}