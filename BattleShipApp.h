#include "StatPane.h"
#include "InputPane.h"
#include "BattleShipMap.h"

class CBattleShipApp {
public:

    void play();

protected:
    void Init();

    void Render();

    void Destroy();

protected:
    CBattleShipMap *m_pMap;
    CBattleShipMap *m_pMap2;
    StatPane *m_pStatPane;
    InputPane *m_pInputPane;
};
