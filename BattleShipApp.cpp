#include "BattleShipApp.h"
#include "BattleShipMap.h"

void CBattleShipApp::Init(){
    
    initscr();
    start_color();
    cbreak();
    refresh();
    
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    
    m_pMap = new CBattleShipMap();
    m_pStatPane = new StatPane(30,3,30,6);
    m_pInputPane = new InputPane(30,15,30,4);
}

void CBattleShipApp::play(){
    Init();
    Render();
    Destroy();
}

void CBattleShipApp::Render(){
    mvprintw(1,1, "<< Battle Ship Game >>");
    
    m_pMap->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();
    
    refresh();
}

void CBattleShipApp::Destroy(){
    
    getch();
    endwin();
    delete m_pMap;

}
