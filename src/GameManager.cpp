//
// Created by Giuseppe Crescenzi on 14/05/25.
//

#include "GameManager.h"

GameManager::GameManager(const int p) : players(p){}

void GameManager::run() {
    Board board;
    board.PrintBoard();
    players = 1;
}