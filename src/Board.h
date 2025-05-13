#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

class Board {
public:
    Board();
    ~Board();

    [[nodiscard]] Piece* getSquare(int x, int y) const {
        return squares[y][x];
    }
private:
    Piece* squares[BOARD_X][BOARD_Y] = {nullptr};
};


#endif //BOARD_H