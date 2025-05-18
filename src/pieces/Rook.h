//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#ifndef ROOK_H
#define ROOK_H

#include "../Piece.h"
class Board;

class Rook final: public Piece {
public:
    Rook(const int x, const int y, const team color, const bool castle = true) : Piece(x, y, color, 8, PieceType::Rook, true), canCastle(castle) {}
    bool isLegalMove(int newX, int newY, Board& board) override;
    // should be set to false when the rook gets moved for the first time
    void setCanCastle(const bool castle) {
        canCastle = castle;
    }
    [[nodiscard]] bool getCanCastle() const {
        return canCastle;
    }
private:
    bool canCastle;
};



#endif //ROOK_H
