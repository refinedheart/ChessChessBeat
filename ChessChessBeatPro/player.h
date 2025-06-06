#ifndef PLAYER_H
#define PLAYER_H


#include <QPixmap>
#include <QLabel>


#include <vector>

#include <QTimer>


// LeftTop = (466, 188)
// Delta d = 26
const int gapx = 26;
const int gapy = 26;
const int StartXpos = 450 + gapx;
// const int StartYpos = 188 - 68 - gapy; // (1, 1)
const int StartYpos = 100 + gapy;
const int siz = 20;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const int limitTraps = 3;

const int TrapScaleVal[] = {1, 2, 4, 5, 10};

inline QPoint GetNextPos(QPoint now, int dir) {
    int x = now.x(), y = now.y();
    // qDebug() << "dir = " << dir << " x = " << x << "dx = " << dx[dir];
    x += dx[dir] * gapx;
    y += dy[dir] * gapy;
    return QPoint(x, y);
}
inline QPoint GetCoordPos(int x, int y) {
    // (1, 1) = (StartX, StartY)
    return QPoint(StartXpos + (x - 1) * gapx, StartYpos + (y - 1) * gapy);
}

inline int regetposx(int x) {
    return (x - StartXpos) / gapx + 1;
}
inline int regetposy(int y) {
    return (y - StartYpos) / gapy + 1;
}

inline long long getTime() {
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return timestamp;
}

class Player
{
public:
    // QLabel *item;
    QPoint pos;
    QString graph;
    int scores;
    int Stopcnt;
    int layTrapcnt;
    int successTrapcnt;
    int getItemCnt;
    struct moveMent {
        int dir;
        long long t;
        moveMent(int dir_ = 0, long long t_ = 0) {
            dir = dir_;
            t = t_;
        }
    };


    std :: vector <moveMent> kp;
    // int Penalty
    // int scores;
    Player(QString pic = "", int fg = 0);
    ~Player();
    struct TrapItem {
        int flag; // human1 or machine2
        int val; // stop options
        int x, y; // pixel position
        TrapItem(int flag_ = 0, int val_ = 0, int x_ = 0, int y_ = 0) {
            flag = flag_;
            val = val_;
            x = x_;
            y = y_;
        }
    };


    int restTraps;
    int trapScale;
    // int Uptime, Downtime, Lefttime, Righttime;
// private:
    // std :: vector <TrapItem> m_vec;
    TrapItem **vec;
    int **id;
    // std :: vector <int> *m_id_ptr;
    // void init(){
    //     m_id_ptr = new std::vector<int>;
    //     delete m_id_ptr;
    // }
public:
    bool checkStop();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void UpdatePos();
    bool checkOutOfWidget(QPoint npos);
    void changeTrapScale() {
        ++trapScale;
        trapScale %= 5;
    }

    // void keyPressEvent(QKeyEvent *event) override;


};

#endif // PLAYER_H
