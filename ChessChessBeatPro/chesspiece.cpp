#include "chesspiece.h"

ChessPiece::ChessPiece(int PieceCnt) {
    myrnd = new QRandomGenerator(time(0));
    cnt = PieceCnt;
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
