//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#ifndef BISHOP_H
#define BISHOP_H

#include "../Piece.h"
class Board;

class Bishop final : public Piece {
public:
    Bishop(int x, int y, team color);
    bool isLegalMove(int newX, int newY) override;
    void eat(Piece &enemy) override;
};



#endif //BISHOP_H
