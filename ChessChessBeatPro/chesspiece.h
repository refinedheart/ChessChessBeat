#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <vector>

#include <QRandomGenerator>





class ChessPiece
{
public:
    ChessPiece(int PieceCnt = 0);
    QRandomGenerator *myrnd;
    int rd(int l, int r);
    std :: vector <int> Xpos, Ypos;
    bool vis[100];
    bool inq[20][20];
    int cnt;
    struct Seq {
        int l, r;
    }whitechess, blackchess;
    void regeneratepos(int i);
};

#endif // CHESSPIECE_H
