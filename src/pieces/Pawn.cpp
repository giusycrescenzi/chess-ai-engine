#include "Pawn.h"

Pawn::Pawn(int x, int y, color color) :
    Piece(x, y, color, 1, true, PieceType::Pawn), firstMove(true), lastMove(false), canEat(false), canPromote(false) {}

bool Pawn::isLegalMove(int newX, int newY) {
    if (firstMove) {
        if (newX - xPos > 0 && newX - xPos <= 2 && newY == yPos) {
            firstMove =  false;
            // TODO CALL MOVE METHOD
            return true;
        }
    }
    if (lastMove) {
        // TODO IMPLEMENT EXCEPION HANDLING
        return false;
    }
    if (!firstMove && newX == xPos+1 && newY == yPos) {
        return true;
    }
    return false;
}