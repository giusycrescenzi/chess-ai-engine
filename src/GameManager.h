//
// Created by Giuseppe Crescenzi on 14/05/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include <sstream>

class GameManager {
public:
    explicit GameManager(int p = 0);
    void run();


private:
    Board board;
    int players;
    void SinglePlayer(Board& board);
    void MultiPlayer(Board& board);
    std::string pieceTypeToString(PieceType type);
};



#endif //GAMEMANAGER_H
