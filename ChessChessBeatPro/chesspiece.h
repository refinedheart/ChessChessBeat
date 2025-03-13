#ifndef CHESSPIECE_H
#define CHESSPIECE_H



#include <QRandomGenerator>





class ChessPiece
{
public:
    ChessPiece();
    QRandomGenerator *myrnd;
    int rd(int l, int r);
};

#endif // CHESSPIECE_H
