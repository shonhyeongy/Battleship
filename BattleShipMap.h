
#include "Pane.h"
#include <string>
using namespace std;

#define MAP_SIZE 8
#ifndef CBattleShipMap_h
#define CBattleShipMap_h

class CBattleShipMap : public Pane {
public:
    CBattleShipMap(const char* name, int x = 4, int y = 4); // m_mapData 를 모두 0으로 초기화

    void Draw();
    void randomDeploy(); //m_mapData 를 randomize

protected:
    friend class CBattleShipApp;
    char m_mapData[MAP_SIZE][MAP_SIZE];

};

#endif