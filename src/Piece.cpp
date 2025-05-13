//
// Created by Giuseppe Crescenzi on 13/05/25.
//
#include "Piece.h"

Piece::Piece(const int x, const int y, team color, const int move, const PieceType type,const bool isAlive) {
    xPos = x;
    yPos = y;
    movements = move;
    this->type = type;
    this->color = color;
    alive = isAlive;
    this->type = type;
}
void Piece::move(const int newX, const int newY) {
    xPos = newX;
    yPos = newY;
}
