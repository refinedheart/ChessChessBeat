#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <vector>

#include <QRandomGenerator>

#include <QString>



class ChessPiece
{
public:
    ChessPiece(int PieceCnt = 0, int ItemCnt = 0);
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
    void regenerateStopItem(int i);
    // type1: Stop by 3 options
    std :: vector <int> XS, YS;
    int Itemcnt;
};

#endif // CHESSPIECE_H
