#include "StatPane.h"
#include "BattleShipMap.h"

class CBattleShipApp{
public:
//    CBattleShipApp();
//    ~CBattleShipApp();
    
    void play();
protected:
    void Init();
    void Render();
    void Destroy();
    
protected:
    CBattleShipMap* m_pMap;
    StatPane* m_pStatPane;
    InputPane* m_pInputPane;
};
