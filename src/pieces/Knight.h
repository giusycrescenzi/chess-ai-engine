//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Piece.h"
class Board;

class Knight final : public Piece {
public:
    Knight(const int x, const int y, const team color) : Piece(x, y, color, 3, PieceType::Knight, true) {}
    bool isLegalMove(int newX, int newY, Board& board) override;
};

#endif //KNIGHT_H