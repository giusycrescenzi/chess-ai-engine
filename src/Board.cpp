#include "Board.h"

Board::Board() {
    // two rows of pawns
    for (int i = 0; i < BOARD_X; i++) {
        squares[i][1] = new Pawn(i, 1, WHITE);
        squares[i][6] = new Pawn(i, 6, BLACK);
    }
    //bruteforcing other pieces (maybe there's a better way (REFACTOR?)
    squares[0][0] = new Rook(0,0,WHITE);
    squares[7][0] = new Rook(7,0,WHITE);
    squares[0][7] = new Rook(0,7,BLACK);
    squares[7][7] = new Rook(7,7,BLACK);
    squares[1][0] = new Knight(1,0,WHITE);
    squares[6][0] = new Knight(6,0,WHITE);
    squares[1][7] = new Knight(1,7,BLACK);
    squares[6][7] = new Knight(6,7,BLACK);
    squares[2][0] = new Bishop(2,0,WHITE);
    squares[5][0] = new Bishop(5,0,WHITE);
    squares[2][7] = new Bishop(2,7,BLACK);
    squares[5][7] = new Bishop(5,7,BLACK);
    squares[3][0] = new Queen(3,0,WHITE);
    squares[4][7] = new Queen(4,7,BLACK);
    squares[4][0] = new King(4, 0, WHITE);
    squares[3][7] = new King(3,7,BLACK);
}
Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete squares[i][j];
        }
    }
}
void Board::PrintBoard() const {
    for (int j = 0; j < BOARD_X; j++) {
        for (int i = 0; i < BOARD_Y; i++) {
            if (squares[i][j] != nullptr) {
                switch (squares[i][j]->getType()) {
                    case PieceType::Pawn :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♙";
                        else
                            std::cout<<"♟";
                    break;
                    case PieceType::Knight :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♘";
                        else
                            std::cout<<"♞";
                    break;
                    case PieceType::Bishop :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♗";
                        else
                            std::cout<<"♝";
                    break;
                    case PieceType::Rook :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♖";
                        else
                            std::cout<<"♜";
                    break;
                    case PieceType::Queen :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♕";
                        else
                            std::cout<<"♛";
                    break;
                    case PieceType::King :
                        if (squares[i][j]->getColor()==WHITE)
                            std::cout<<"♔";
                        else
                            std::cout<<"♚";
                    break;
                    default: break;
                }
            } else {
                std::cout<<".";
            }
            if (i != BOARD_X-1)
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
