#include "Pawn.h"
#include "../Board.h"

Pawn::Pawn(const int x, const int y, const team color) :
    Piece(x, y, color, 1, PieceType::Pawn, true), firstMove(true), lastMove(false), canEat(false) {}

bool Pawn::isLegalMove(const int newX, const int newY, Board& board) {
    if (firstMove) {
        if (color == WHITE && board.getSquare(yPos+1, xPos)==nullptr && board.getSquare(yPos+2, xPos)==nullptr) {
            if (newY - yPos > 0 && newY - yPos <= 2 && newX == xPos) {
                firstMove =  false;
                return true;
            }
        } else if (board.getSquare(yPos-1, xPos)==nullptr && board.getSquare(yPos-2, xPos)==nullptr) {
            if (yPos - newY > 0 && yPos - newY <= 2 && newX == xPos) {
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
        if (color == WHITE && board.getSquare(yPos+1, xPos)==nullptr) {
            if (newX == xPos && newY == yPos+movements) {
                return true;
            }
        } else if (board.getSquare(yPos-1, xPos)==nullptr) {
            if (newX == xPos && newY == yPos-movements) {
                return true;
            }
        }
    }
    return false;
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
