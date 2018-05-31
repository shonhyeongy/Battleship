#include "BattleShipApp.h"
#include "BattleShipMap.h"

void CBattleShipApp::Init() {

    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    m_pMap = new CBattleShipMap("Defender");
    m_pMap2 = new CBattleShipMap("Attacker", 4, 25);
    m_pStatPane = new StatPane(30, 3, 30, 6);
    m_pInputPane = new InputPane(30, 15, 30, 5);
}

void CBattleShipApp::play() {
    Init();
    Render();

    while (true) {
        move(17, 40);
        keypad(m_pInputPane->m_pWindow, false);
        char cmd[2];
        scanw("%s", cmd);
        string scmd(cmd);
        if (scmd == "gg") {
            break;
        }
        mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : SUCCESS"); // 변경사항
        wrefresh(m_pInputPane->m_pWindow); // 누적된 변경사항 화면에 표시

    }

    Destroy();
}

void CBattleShipApp::Render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");
    m_pMap->randomDeploy();
    m_pMap->Draw();
    m_pMap2->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();
}

void CBattleShipApp::Destroy() {

    getch();
    endwin();
    delete m_pMap;
}
