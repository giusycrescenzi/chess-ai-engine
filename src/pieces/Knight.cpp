//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "Knight.h"
#include "../Board.h"

bool Knight::isLegalMove(int newX, int newY, Board& board) {
    if ((newX-xPos)+(newY-yPos)==movements
            && board.getSquare(newX, newY) == nullptr){
        return true;
    }
    return false;
}