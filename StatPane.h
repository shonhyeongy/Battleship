//
//  StatPane.hpp
//  BattleShip_v1
//
//  Created by 손현기 on 2018. 5. 24..
//  Copyright © 2018년 손현기. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "Pane.h"

class StatPane : public Pane {
public:
    StatPane(int x, int y, int width, int height);

    virtual void Draw(int number = 0);
};