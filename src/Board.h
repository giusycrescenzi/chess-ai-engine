#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <iostream>
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"

class Board {
public:
    Board();
    ~Board();
    void PrintBoard() const;

    [[nodiscard]] Piece* getSquare(const int x, const int y) const {
        return squares[y][x];
    }
private:
    Piece* squares[BOARD_X][BOARD_Y] = {nullptr};
};


#endif //BOARD_H