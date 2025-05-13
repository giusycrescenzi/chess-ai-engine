#ifndef PIECE_H
#define PIECE_H

#define BLACK 0
#define WHITE 1
#include <set>
typedef unsigned short int color;

enum class PieceType {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

template <int M>
class Piece {
public:
    Piece(int x, int y, color color, int move = M, bool isAlive = true, PieceType type);
    virtual ~Piece() = default;
    virtual void eat(Piece& enemy) = 0;
    virtual bool isLegalMove(int newX, int newY) = 0;

    virtual void die() {
        setAlive(false);
    }

    [[nodiscard]] int getX() const {
        return xPos;
    }
    [[nodiscard]] int getY() const {
        return yPos;
    }
    [[nodiscard]] bool isAlive() const {
        return alive;
    }
    [[nodiscard]] color getColor() const {
        return pieceColor;
    }
    [[nodiscard]] int getMovements() const {
        return movements;
    }
    [[nodiscard]]PieceType getType() const {
        return type;
    }

protected:
    int xPos, yPos;
    color pieceColor;
    int movements;
    bool alive;
    PieceType type;
    virtual void move(int newX, int newY); //islegalMove will call it eventually
    void setX(const int x) {
        xPos = x;
    }
    void setY(const int y) {
        yPos = y;
    }
    void setAlive(const bool a) {
        alive = a;
    }
};

template<int M>
Piece<M>::Piece(const int x, const int y, color color, const int move, const bool isAlive, PieceType type) {
    xPos = x;
    yPos = y;
    movements = move;
    this->type = type;
    this->pieceColor = color;
    alive = isAlive;
}
template<int M>
void Piece<M>::move(const int newX, const int newY) {
    xPos = newX;
    yPos = newY;
}

#endif // PIECE_H