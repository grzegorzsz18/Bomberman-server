#include "Serializer.h"

using namespace std;


string serializeObstacles(Map* map){
    string obstacles = "o:";
    obstacles.append(to_string(map->cells.size()));
    obstacles.append("|");
    for(int i = 0; i < map->cells.size() ; i++){
        if(map->cells.at(i)->obstacle == nullptr){
            obstacles.append("0");
            continue;
        }
        if(map->cells.at(i)->obstacle->isDestroyable()){
            obstacles.append("1");
            continue;
        }
        else{
            obstacles.append("2");
            continue;
        }
    }
    obstacles.append("+++");
    return obstacles;
}

string serializePlayers(Map* map){
    string players = "p:";
    players.append(to_string(map->players.size()));
    for(int i = 0; i< map->players.size(); i++){
        Player* p = map->players.at(i);
        players.append(p->name);
        players.append(",");
        players.append(to_string(p->lifes));
        players.append(",");
        players.append(to_string(p->isAlive));
        players.append(",");
        players.append(to_string(p->avaliableBombs));
        players.append("{");
        players.append(to_string(p->position->x));
        players.append(",");
        players.append(to_string(p->position->y));
        players.append("}|");

    }

    players.append("+++");
    return players;
}

string serializeBombs(Map* map){
    int bombsQuantity = 0;
    string bombs = "";
    for(int i = 0; i < map->cells.size() ; i++){
        if(map->cells.at(i)->bomb != nullptr){
            bombsQuantity ++;
            bombs.append(to_string(i));
            bombs.append(",");
            bombs.append(to_string(map->cells.at(i)->bomb->power));
            bombs.append(",");
            bombs.append(to_string(map->cells.at(i)->bomb->durationTime));
            bombs.append("|");
        }
    }
    string returnedValue = "";
    returnedValue.append("b:");
    returnedValue.append(to_string(bombsQuantity));
    returnedValue.append("|");
    returnedValue.append(bombs);
    returnedValue.append("+++");
    return returnedValue;

}