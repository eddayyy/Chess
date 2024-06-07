//============================================================
// FILE: BoardState.h
//============================================================
#pragma once

#include <SDL.h>
#include <memory>
#include "ChessPiece.h"

class BoardState
{
public:
    BoardState();
    ~BoardState();

    // Methods
    int  SDLinit();
    int  renderBoard();

    // Helper Functions
    void initializeBoard();
    void initPiece(const std::string& type, Team team, int x, int y);

    void setPiece(int x, int y, std::unique_ptr<ChessPiece> piece);
    void movePiece(int startX, int startY, int endX, int endY); // Added method for piece movement
    void setPosition(int gridX, int gridY, int x, int y);

    // Accessors
    SDL_Window* window() const noexcept;
    int boardSize() const noexcept;
    int squareSize() const noexcept;

private:
    int _BOARD_SIZE = 8;
    int _SQUARE_SIZE = 100;
    int _SELECTED_X = -1;
    int _SELECTED_Y = -1;
    bool _PIECE_SELECTED = false;
    int selectedX = 0, selectedY = 0, draggingX = -1, draggingY = -1;

    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::unique_ptr<ChessPiece> _board[8][8]; // The board holding chess pieces
};
