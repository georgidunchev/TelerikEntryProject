#include "piece.h"

Piece::Piece(piecesEnum t, Board * b)
{
    if(t == KING)
    {
        king = true;
        x = 3;
        y = 7;
        symbol = 'K';
    }
    else
    {
        king = false;
        y = 0;
        x = (t-1)*2;
        symbol = 'A'+(t-1);
    }
    board = b;
}

void Piece::move(char a, char b)
{
    int tX=0,tY=0;
    if(a == 'U' && y>0 && king)
    {
        if(b == 'L' && x>0)
        {
            tX--; tY--;
            setSuccessfulMove(true);
            return;
        }
        if(b == 'R' && x<7)
        {
            tX++; tY--;
            setSuccessfulMove(true);
            return;
        }
    }

    if(a == 'D' && y<7)
    {
        if(b == 'L' && x>0)
        {
            tX--; tY++;
            setSuccessfulMove(true);
            return;
        }
        if(b == 'R' && x<7)
        {
            tX++; tY++;
            setSuccessfulMove(true);
            return;
        }
    }
//    board->
    setSuccessfulMove(false);
}

void Piece::setSuccessfulMove(bool b)
{
    successfulMove = b;
}

bool Piece::getSuccessfulMove()
{
    return successfulMove;
}

int Piece::getX()
{
    return x;
}

int Piece::getY()
{
    return y;
}
char Piece::getSymbol()
{
    return symbol;
}
