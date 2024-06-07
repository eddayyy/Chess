//============================================================
// FILE: main.cpp
//============================================================
#include "BoardState.h"

int main(int argc, char* argv[]) {
	BoardState drawBoard;

	drawBoard.initializeBoard();
	drawBoard.renderBoard();

	return 0;
}
