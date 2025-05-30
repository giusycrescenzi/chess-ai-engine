//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#ifndef QUEEN_H
#define QUEEN_H

#include "../Piece.h"
class Board;

class Queen final : public Piece {
public:
    Queen(const int x, const int y, const team color) : Piece(x, y, color, 8, PieceType::Queen, true) {}
    bool isLegalMove(int newX, int newY, Board& board) override;
};



#endif //QUEEN_H
