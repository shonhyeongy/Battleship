//
//  StatPane.cpp
//  BattleShip_v1
//
//  Created by 손현기 on 2018. 5. 24..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
:Pane(x,y,width,height)
{
    mvwprintw(m_pWindow,0,3,"< STATUS >");
}

void StatPane::Draw(){
    
    wattron(m_pWindow,COLOR_PAIR(2));
    mvwprintw(m_pWindow,1,2,"AIRCRAFT : AAAAA");
    mvwprintw(m_pWindow,2,2,"BATTLESHIP : BBBB");
    mvwprintw(m_pWindow,3,2,"CRUISER : CCC");
    mvwprintw(m_pWindow,4,2,"DESTROYER : DD DD");
    wattron(m_pWindow,COLOR_PAIR(2));
    
    wrefresh(m_pWindow);
    
}

