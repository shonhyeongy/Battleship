//
// Created by user on 18. 5. 28.
//

#include "Pane.h"
#pragma once

class InputPane : public Pane {
public:
    InputPane(int x, int y, int width, int height);

    virtual void Draw();
};
