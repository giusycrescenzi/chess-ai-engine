#ifndef PAWN_H
#define PAWN_H

#include "../pieces/Bishop.h"
#include "../Piece.h"

class Pawn final : public Piece<1> {
public:
    Pawn(int x, int y, color color);
    bool isLegalMove(int newX, int newY) override;
    void eat(Piece &enemy) override;
    void checkPromotion(); // to check if you can promote the pawn to any other piece
    void Promote();
    bool CanEat();

    void setIsFirst(const bool isFirst) {
        firstMove = isFirst;
    }
    void setIsLast(const bool isLast) {
        lastMove = isLast;
    }
    void SetCanEat(const bool e) {
        canEat = e;
    }
    void setCanPromote(const bool e) {
        canPromote = e;
    }
    [[nodiscard]] bool isFirstMove() const {
        return firstMove;
    }
    [[nodiscard]] bool isLastMove() const {
        return lastMove;
    }
    [[nodiscard]] bool isEat() const {
        return canEat;
    }
    [[nodiscard]] bool isPromote() const {
        return canPromote;
    }
private:
    bool firstMove;
    bool lastMove;
    bool canEat;
    bool canPromote;
};

#endif