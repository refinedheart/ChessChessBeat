#include "chesspiece.h"

ChessPiece::ChessPiece() {
    myrnd = new QRandomGenerator(time(0));
}

int ChessPiece :: rd(int l, int r) {
    return (myrnd -> bounded(l, r));
}
