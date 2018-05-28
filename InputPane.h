//
// Created by user on 18. 5. 28.
//

#pragma once

#include "Pane.h"

class InputPane : public Pane {
public:
    friend class CBattleShipApp;
    InputPane(int x, int y, int width, int height);

    virtual void Draw();
};
