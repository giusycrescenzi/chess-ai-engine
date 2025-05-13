#ifdef PIECE_H
#define PIECE_H

#define BLACK 0
#define WHITE 1
typedef unsigned short int color;

template <int X, int Y, int M>
class Piece {
    public:
        Piece();
        Piece(int x, int y, color pieceColor, int movements, bool isAlive = true, std::string type = "");
        virtual ~Piece();
        virtual void move(int newX, int newY) = 0;
        virtual void eat(Piece& enemy) = 0;
        virtual void die() = 0;
        virtual void revive() = 0;


        void setX(int x);
        void setY(int y);
        void setAlive(bool alive);

        int getX() const;
        int getY() const;
        bool isAlive() const;
        color getColor() const;
        int getMovements() const;
        std::string getType() const;

    protected:
        int x, y;
        color pieceColor;
        int movements;
        bool isAlive;
        std::string type;
};

#endif // PIECE_H