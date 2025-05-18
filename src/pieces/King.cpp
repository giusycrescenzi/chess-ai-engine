//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "King.h"
#include "../Board.h"

bool King::isLegalMove(const int newX, const int newY, Board &board) {
    if (abs(newX - xPos) > movements || abs(newX - xPos) > movements)
        return false;
    if (board.getSquare(newX, newY) == nullptr)
        return true;
    if (newY==yPos && newX==xPos)
        return false;
    if (board.getSquare(newX, newY)->getColor() == this->color)
        return false;
    Piece* enemy = board.getSquare(newX, newY);
    enemy->die();
    return true;
}