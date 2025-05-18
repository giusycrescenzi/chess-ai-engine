#ifndef PIECE_H
#define PIECE_H

#define BLACK 0
#define WHITE 1
#define BOARD_X 8
#define BOARD_Y 8

typedef unsigned short int team;

enum class PieceType {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King,
    Empty
};
class Board;

class Piece {
public:
    Piece(int x, int y, team color, int move, PieceType type, bool isAlive = true);
    virtual ~Piece() = default;
    virtual bool isLegalMove(int newX, int newY, Board& board) = 0;
    virtual void move(int newX, int newY); //islegalMove will call it eventually

    virtual void eat(Piece& enemy) {
        enemy.die();
    }
    virtual void die() {
        setAlive(false);
    }

    void setX(const int x) {
        xPos = x;
    }
    void setY(const int y) {
        yPos = y;
    }
    void setAlive(const bool a) {
        alive = a;
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
    [[nodiscard]] team getColor() const {
        return color;
    }
    [[nodiscard]] int getMovements() const {
        return movements;
    }
    [[nodiscard]]PieceType getType() const {
        return type;
    }

protected:
    int xPos, yPos;
    team color;
    int movements;
    bool alive;
    PieceType type;

};

#endif // PIECE_H