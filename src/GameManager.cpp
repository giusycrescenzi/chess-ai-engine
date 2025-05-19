//
// Created by Giuseppe Crescenzi on 14/05/25.
//

#include "GameManager.h"

GameManager::GameManager(const int p) : players(p){}

void GameManager::run() {
    Board board;
    board.PrintBoard();
    // will it be a man vs ai or a two players match?
    do {
        std::cout << "Enter number of players: ";
        std::cin >> players;
        std::cout << std::endl;
    } while (players < 1 || players > 2);
    if (players == 2) {
        MultiPlayer(board);
    }
    else {
        SinglePlayer(board);
    }
}

void GameManager::SinglePlayer(Board& board) {

}

void GameManager::MultiPlayer(Board& board) {

}