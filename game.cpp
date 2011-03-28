#include "game.h"
#include "piece.h"

Game::Game()
{
    directions[0] = "KUL";
    directions[1] = "KUR";
    directions[2] = "KDL";
    directions[3] = "KDR";
    directions[4] = "ADL";
    directions[5] = "ADR";
    directions[6] = "BDL";
    directions[7] = "BDR";
    directions[8] = "CDL";
    directions[9] = "CDR";
    directions[10] = "DDL";
    directions[11] = "DDR";

    pieces[KING] = new Piece(KING, &gameBoard);
    pieces[PAWNA] = new Piece(PAWNA, &gameBoard);
    pieces[PAWNB] = new Piece(PAWNB, &gameBoard);
    pieces[PAWNC] = new Piece(PAWNC, &gameBoard);
    pieces[PAWND] = new Piece(PAWND, &gameBoard);

    currentTurn = 0;
    do{
        drawBoard();
    }while(!promptAction());
}

void Game::drawBoard()
{
    cout << "    0 1 2 3 4 5 6 7\n"
         << "   -----------------\n";
    for(int line=0;line<8;line++)
    {
        cout << line << " | ";
        for(int row=0;row<8;row++)
        {
            bool cont = false;
            for(int i = 0;i<5;i++)
            {
                if(pieces[i]->getX()==row && pieces[i]->getY()==line)
                {
                    cout << pieces[i]->getSymbol() << " ";
                    cont=true;
                    break;
                }
            }

            if(cont) continue;

            if(line%2==0)
                if(row%2==0)
                    cout<<"+ ";
                else
                    cout<<"- ";
            else
                if(row%2==0)
                    cout<<"- ";
                else
                    cout<<"+ ";
        }
        cout << "|\n";
    }
    cout << "   -----------------\n";
}

bool Game::promptAction()
{

    bool kingsTurn = !(currentTurn%2);
//    cout << kingsTurn;
    char direction[3];

    if(kingsTurn)
        cout << "King's turn: ";
    else
        cout << "Pawn's turn: ";

    cin >> direction;

    for(int i = 0; i < 12; i++)
    {
        piecesEnum p;
        if(directions[i] == direction)
        {
            cout<<i<<" "<<direction[0];

            if(direction[0] == 'K' && !kingsTurn)
                cout<<"Command a Pawn.";
            if(direction[0] != 'K' && kingsTurn)
                cout<<"Command the King.";
            if(direction[0]=='K' && kingsTurn)
                p = KING;
            if(direction[0]=='A' && !kingsTurn)
                p = PAWNA;
            if(direction[0]=='B' && !kingsTurn)
                p = PAWNB;
            if(direction[0]=='C' && !kingsTurn)
                p = PAWNC;
            if(direction[0]=='D' && !kingsTurn)
                p = PAWND;

            pieces[p]->move(direction[1],direction[2]);
            if(pieces[p]->getSuccessfulMove())
            {
                return true;
            }
            else
            {
                cout<<"Illegal move!\n";
                return false;
            }
        }
    }
    cout<<"Illegal move!\n";
    return false;
}

bool Game::isPositionValid(int x, int y)
{

}
