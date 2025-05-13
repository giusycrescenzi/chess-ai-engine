#include "Board.h"

#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"

Board::Board() {
    // two rows of pawns
    for (int i = 0; i < BOARD_X; i++) {
        squares[i][1] = new Pawn(i, 1, WHITE);
        squares[i][6] = new Pawn(i, 6, BLACK);
    }
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete squares[i][j];
        }
    }
}
