#include "BattleShipMap.h"
#include "Random.h"
#include <string>
#include <cstdlib>
using namespace std;

CBattleShipMap::CBattleShipMap(const char* name, int x, int y)
        : Pane(x, y, MAP_SIZE + 3, MAP_SIZE + 2) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            // 맵 데이터 초기화
            m_mapData[i][j] = '0';
        }
    }

    for (int i = 0; i < MAP_SIZE; ++i) {
        mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
    }

    mvwprintw(m_pWindow, 0, 3, name); // < MAP > 이라는 글자 출력

}

void CBattleShipMap::randomDeploy(){

    Make mg;

    int size1[5] = {5,4,3,2,2};
    int size_count = 0;

    srand((unsigned int) time(NULL));
    int direction = -1;
    // battleship 랜덤 배치
    while (1) {
        int left, right;
        left = rand() % 8;
        right = rand() % 8;
        direction = rand() % 4;

        if (size_count > 4) {
            break;
        } else {
            if (mg.Random_select_position(left, right, direction, size1[size_count], m_mapData) == 0) {
                size_count++;
            }
        }
    }
}
void CBattleShipMap::Draw() {
    wattron(m_pWindow, COLOR_PAIR(1)); //색결정
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            //숫자 좌표 설정
            mvwprintw(m_pWindow, i + 1, j + 2, "%c", m_mapData[i][j]);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));
    wrefresh(m_pWindow);
}
