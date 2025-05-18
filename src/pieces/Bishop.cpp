//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "Bishop.h"
#include "../Board.h"
Bishop::Bishop(const int x, const int y, const team color) :
    Piece(x, y, color, 8, PieceType::Bishop, true){}

bool Bishop::isLegalMove(const int newX, const int newY, Board& board) {
    if (abs(newX-xPos) != abs(newY-yPos))
        return false;
    // find the direction of the movements by its versors
    const int stepX = newX-xPos > 0 ? 1 : -1;
    const int stepY = newY-yPos > 0 ? 1 : -1;
    // check for obstacles along the path (except the last step)
    int x = xPos + stepX;
    int y = yPos + stepY;
    while (x != newX && y != newY) {
        if (board.getSquare(x, y) != nullptr)
            return false; //there's a piece
        x += stepX;
        y += stepY;
    }
    // check the last square
    if (board.getSquare(newX, newY)== nullptr)
        return true;
    if (board.getSquare(newX, newY)->getColor() == this->getColor())
        return false;
    // if the last step has an enemy piece, eat it
    Piece* enemy = board.getSquare(newX, newY);
    enemy->die();
    return true;
}
