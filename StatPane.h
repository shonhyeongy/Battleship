//
//  StatPane.hpp
//  BattleShip_v1
//
//  Created by 손현기 on 2018. 5. 24..
//  Copyright © 2018년 손현기. All rights reserved.
//

#ifndef StatPane_hpp
#define StatPane_hpp

#include <stdio.h>
#include "Pane.h"


class StatPane : public Pane {
public:
    StatPane(int x, int y, int width, int height);

    virtual void Draw();
};

class InputPane : public Pane {
public:
    InputPane(int x, int y, int width, int height);

    virtual void Draw();
};

#endif /* StatPane_hpp */