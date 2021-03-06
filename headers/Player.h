#ifndef PROJECTBOOM_PLAYER_H
#define PROJECTBOOM_PLAYER_H
#include <iostream>
#include <vector>
#include <netinet/in.h>
#include "Point.h"
#include "Bomb.h"

using namespace std;

class Point;
class Bomb;

class Player {

public:
    void setSocket(sockaddr_in* sock);
    void plantBomb(Bomb* bomb);
    bool isPlayerOnField(int x, int y);
    void removeBomb(Bomb* bomb);
    Point* position;
    int id;
    string name = "";
    int avaliableBombs;
    int lifes;
    bool isAlive;
    bool isActive;
    Player();
    vector<Bomb*> bombs;
    int bombPower;
    int lastResponseTime;
    sockaddr_in socket;

};


#endif //PROJECTBOOM_PLAYER_H
