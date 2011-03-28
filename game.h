#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "piece.h"
#include "board.h"

class Piece;
typedef enum piecesEnum {KING, PAWNA, PAWNB, PAWNC, PAWND};

class Game
{
public:
    Game();
    bool isPositionValid(int x, int y);
private:
    enum Movement {KUL, KUR, KDL, KDR, ADL, ADR, BDL, BDR, CDL, CDR, DDL, DDR};
    std::string directions[12];
//    enum piecesEnum {KING, PAWNA, PAWNB, PAWNC, PAWND};

    Piece * pieces[5];
    int currentTurn;

    void drawBoard();
    bool promptAction();
    Board gameBoard;
};

#endif // GAME_H
