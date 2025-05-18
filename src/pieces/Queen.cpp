//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "Queen.h"
#include "../Board.h"

// copy paste bishop and rook movement
// THERE IS PROBABLY A BETTER WAY, I'LL THINK ABOUT IT REFACTORING
bool Queen::isLegalMove(const int newX, const int newY, Board &board) {
    // if it doesn't move like a bishop or a rook something is wrong
    if (abs(newX-xPos) != abs(newY-yPos) && newX!=xPos && newY!=yPos) {
        return false;
    }
    // bishop movement
    if (newX!=xPos && newY!=yPos) {
        const int stepX = newX-xPos > 0 ? 1 : -1;
        const int stepY = newY-yPos > 0 ? 1 : -1;
        int x = xPos + stepX;
        int y = yPos + stepY;
        while (x != newX && y != newY) {
            if (board.getSquare(x, y) != nullptr)
                return false; //there's a piece
            x += stepX;
            y += stepY;
        }
        if (board.getSquare(newX, newY)== nullptr)
            return true;
        if (board.getSquare(newX, newY)->getColor() == this->getColor())
            return false;
        Piece* enemy = board.getSquare(newX, newY);
        enemy->die();
        return true;
    }
    // rook movement
    if (abs(newX-xPos) != abs(newY-yPos)) {
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
    return false; //verified when newX=xPos and newY=yPos
}