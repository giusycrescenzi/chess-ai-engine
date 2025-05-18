#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"
class Board;

class Pawn final : public Piece {
public:
    Pawn(int x, int y, team color);
    // this function return value will be checked to call the move method
    bool isLegalMove(int newX, int newY, Board& board) override;
    void checkPosition(); // to check if you can promote
    // this method needs user input to choose which promotion
    void Promote(Piece& promotion);
    // TODO bool CanEat();


    void setIsFirst(const bool isFirst) {
        firstMove = isFirst;
    }
    void setIsLast(const bool isLast) {
        lastMove = isLast;
    }
    void SetCanEat(const bool e) {
        canEat = e;
    }
    [[nodiscard]] bool isFirstMove() const {
        return firstMove;
    }
    [[nodiscard]] bool isLastMove() const {
        return lastMove;
    }
    [[nodiscard]] bool CanEat() const {
        return canEat;
    }
private:
    bool firstMove;
    bool lastMove;
    bool canEat;
};

#endif