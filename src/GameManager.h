//
// Created by Giuseppe Crescenzi on 14/05/25.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"

class GameManager {
public:
    explicit GameManager(int p = 1);
    void run();
private:
    int players;
};



#endif //GAMEMANAGER_H
