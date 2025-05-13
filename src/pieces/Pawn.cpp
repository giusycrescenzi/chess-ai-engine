#include "Pawn.h"

Pawn::Pawn(const int x, const int y, const team color) :
    Piece(x, y, color, 1, PieceType::Pawn, true), firstMove(true), lastMove(false), canEat(false) {}

bool Pawn::isLegalMove(const int newX, const int newY) {
    if (firstMove) {
        if (color == WHITE) {
            if (newX - xPos > 0 && newX - xPos <= 2 && newY == yPos) {
                firstMove =  false;
                return true;
            }
        } else {
            if (xPos - newX > 0 && xPos - newX <= 2 && newY == yPos) {
                firstMove = false;
                return true;
            }
        }
    }
    if (lastMove) {
        // TODO IMPLEMENT EXCEPION HANDLING
        return false;
    }
    if (!firstMove) {
        if (color == WHITE) {
            if (newY == yPos && newX == xPos+1) {
                return true;
            }
        } else {
            if (newY == yPos && newX == xPos-1) {
                return true;
            }
        }
    }
    return false;
}

void Pawn::eat(Piece& enemy) {
    enemy.die();
}
void Pawn::checkPosition() {
    if (color == WHITE) {
        if (yPos == BOARD_Y)
            lastMove = true;
    }
    else { //if the piece is black
        if (yPos == 0)
            lastMove = true;
    }
}
void Pawn::Promote(Piece& promotion) {
    promotion.setX(xPos);
    promotion.setY(yPos);
    this->alive = false; // the pawn dies and a Piece with the same position appears
}
