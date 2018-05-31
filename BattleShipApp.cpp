#include "BattleShipApp.h"
#include "BattleShipMap.h"
#include <vector>

void CBattleShipApp::Init() {

    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_WHITE);

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

        m_pMap->Draw();

        if (m_pMap->getFromCode(cmd) == '0') {
            m_pMap2->getFromCode(cmd) = 'M';
            wattron(m_pInputPane->m_pWindow, COLOR_PAIR(4));
            mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : MISS"); // 변경사항
            wattron(m_pInputPane->m_pWindow, COLOR_PAIR(3));
        } else {
            m_pMap2->getFromCode(cmd) = 'H';
            wattron(m_pInputPane->m_pWindow, COLOR_PAIR(1));
            mvwprintw(m_pInputPane->m_pWindow, 3, 2, "Result : SUCCESS"); // 변경사항
            wattron(m_pInputPane->m_pWindow, COLOR_PAIR(3));
        }


        bool is_destroyed[] = {true, true, true, true}; // A,B,C,D 순서
        // 따로 배들의 좌표를 저장해놓는 자료구조를 안 만들어 놔서 화면에 H 이 체크된 것을 보고 모두 격추되었는지 is_destroyed 에 기록함
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (m_pMap->m_mapData[i][j] != '0' && m_pMap2->m_mapData[i][j] != 'H') {
                    is_destroyed[m_pMap->m_mapData[i][j] - 65] = false;
                }
            }
        }
        m_pMap2->Draw();

        int x = 0;
        int j = 1;
        for (int k = 0; k < 4; ++k) {
            x = x | (is_destroyed[k] ? j : 0);
            j *= 2;
        }

        //m_pStatPane->Draw(1 | 4);
        m_pStatPane->Draw(x);

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


