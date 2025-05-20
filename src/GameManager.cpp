//
// Created by Giuseppe Crescenzi on 14/05/25.
//

#include "GameManager.h"

GameManager::GameManager(const int p) : players(p){}

void GameManager::run() {
    Board board;
    board.PrintBoard();
    // will it be a man vs AI or a two players match?
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
    while (true) {
        // TODO MINIMAX ALGORITHM
        break;
    }
}

void GameManager::MultiPlayer(Board& board) {
    bool break_game_loop = false;
    int oldX, oldY, newX, newY;
    std::string input;
    for (int i = 1, j = 0; !break_game_loop; i = (i+1)%2) {
        j = 2-i;
        // this whole block checks if the piece coordinates are legal
        std::cout << "player " << j << " turn" << std::endl;
        std::cout << "starting coordinates in the format x,y => ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (char comma; ss >> oldX >> comma >> oldY && comma == ',' && ss.eof()) {
            std::cout<<"moving "<< pieceTypeToString(board.getSquare(oldX, oldY)->getType()) << std::endl;
        } else {
            std::cerr << "Invalid format. Please enter coordinates as x,y (e.g. 2,3)\n";
        }
        std::cout << "ending coordinates in the format x,y => ";
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
        std::stringstream ss2(input);
        if (char comma; ss2 >> newX >> comma >> newY && comma == ',' && ss.eof()) {
            if (board.getSquare(oldX,oldY)->isLegalMove(newX,newY,board)) {
                board.getSquare(newX,newY)->move(newX,newY);
                board.PrintBoard();
                std::cout<<std::endl;
            } else {
                std::cerr << "illegal movement" << std::endl;
            }
        } else {
            std::cerr << "Invalid format. Please enter coordinates as x,y\n";
        }
        // check if the game ended to break the loop
        if (board.getSquare(newX,newY)->getType()==PieceType::King) {
            std::cout<<"player " << j << "won!" << std::endl;
            break_game_loop = true;
        }
    }
}

std::string GameManager::pieceTypeToString(const PieceType type) {
    switch (type) {
        case PieceType::Pawn:   return "Pawn";
        case PieceType::Knight: return "Knight";
        case PieceType::Bishop: return "Bishop";
        case PieceType::Rook:   return "Rook";
        case PieceType::Queen:  return "Queen";
        case PieceType::King:   return "King";
        default:                return "Unknown";
    }
}

















