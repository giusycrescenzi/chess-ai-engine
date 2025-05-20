//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#ifndef KING_H
#define KING_H

#include "../Piece.h"
class Board;

class King final : public Piece {
public:
    King(const int x, const int y, const team color, const bool castle = true) : Piece(x, y, color, 1, PieceType::King, true), canCastle(castle) {}
    bool isLegalMove(int newX, int newY, Board& board) override;
private:
    bool canCastle;
    bool isKing {true};
};

#endif //KING_H