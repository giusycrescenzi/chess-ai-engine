//
// Created by Giuseppe Crescenzi on 13/05/25.
//

#include "Bishop.h"
#include "../Board.h"
Bishop::Bishop(int x, int y, team color) :
    Piece(x, y, color, 8, PieceType::Bishop, true){}
