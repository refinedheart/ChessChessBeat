#include "chesspiece.h"

ChessPiece::ChessPiece(int PieceCnt, int ItemCnt) {
    myrnd = new QRandomGenerator(time(0));
    cnt = PieceCnt; Itemcnt = ItemCnt;
    whitechess.l = 0;
    whitechess.r = cnt / 2 - 1;
    blackchess.l = cnt / 2;
    blackchess.r = cnt - 1;
    memset(vis, 0, sizeof vis);
    memset(inq, 0, sizeof inq);
    Xpos.resize(PieceCnt);
    Ypos.resize(PieceCnt);
    for(int i = 0; i < cnt; ++i) {
        Xpos[i] = rd(1, 19);
        Ypos[i] = rd(1, 19);
        while(inq[Xpos[i]][Ypos[i]]) {
            Xpos[i] = rd(1, 19);
            Ypos[i] = rd(1, 19);
        }
        inq[Xpos[i]][Ypos[i]] = 1;
    }
    XS.resize(ItemCnt);
    YS.resize(ItemCnt);
    for(int i = 0; i < ItemCnt; ++i) {
        XS[i] = rd(1, 19);
        YS[i] = rd(1, 19);
        while(inq[XS[i]][YS[i]]) {
            XS[i] = rd(1, 19);
            YS[i] = rd(1, 19);
        }
        inq[XS[i]][YS[i]] = 1;
    }
    for(int i = 0; i < ItemCnt; ++i) {

    }
}

int ChessPiece :: rd(int l, int r) {
    return (myrnd -> bounded(l, r));
}

void ChessPiece :: regeneratepos(int i) {
    inq[Xpos[i]][Ypos[i]] = 0;
    Xpos[i] = rd(1, 19);
    Ypos[i] = rd(1, 19);
    while(inq[Xpos[i]][Ypos[i]]) {
        Xpos[i] = rd(1, 19);
        Ypos[i] = rd(1, 19);
    }
    inq[Xpos[i]][Ypos[i]] = 1;
}


void ChessPiece :: regenerateStopItem(int i) {
    inq[XS[i]][YS[i]] = 0;
    XS[i] = rd(1, 19);
    YS[i] = rd(1, 19);
    while(inq[XS[i]][YS[i]]) {
        XS[i] = rd(1, 19);
        YS[i] = rd(1, 19);
    }
    inq[XS[i]][YS[i]] = 1;
}
