#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "game.h"
#include "board.h"

//class Game;

class Piece
{
public:
    Piece(piecesEnum t, Board * b);
    void move(char a, char b);
    bool getSuccessfulMove();
    void setSuccessfulMove(bool b);
    int getX();
    int getY();
    char getSymbol();
private:
    bool king;
    std::string movement;
    int x,y;
    bool successfulMove;
    char symbol;
    Board * board;
};

#endif // PIECE_H
