//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "Rook.h"
#include "../Board.h"

bool Rook::isLegalMove(const int newX,const int newY, Board& board) {
    if (newX != xPos && newY != yPos)
        return false;
    if (newX == xPos) {
        int y = yPos;
        const int step =  newY-y > 0 ? 1 : -1;
        while (y != yPos) {
          if (board.getSquare(newX, y) != nullptr)
            return false;
          y += step;
        }
    }
    else {
      int x = xPos;
      const int step =  newX-x > 0 ? 1 : -1;
      while (x != xPos) {
        if (board.getSquare(x, newY) != nullptr)
          return false;
        x += step;
      }
    }
    if(board.getSquare(newX, newY) == nullptr)
      return true;
    if (board.getSquare(newX, newY)->getColor() == this->getColor())
      return false;
    Piece* enemy = board.getSquare(newX, newY);
    enemy->die();
    return true;
}