
#include "Pane.h"

#define MAP_SIZE 8
#ifndef CBattleShipMap_h
#define CBattleShipMap_h

class CBattleShipMap : public Pane {
public:
    CBattleShipMap();

    ~CBattleShipMap();

    void Draw();

protected:
    char m_mapData[MAP_SIZE][MAP_SIZE];

};

#endif