#pragma once
#include <memory>
#include "Point.h"
#include "ITriggerable.h"

// -----------------------------------------------------------------------------
// MazeCell
class MazeCell {
public:
    Point pos;
    std::unique_ptr<ITriggerable> content;
    MazeCell(int x=0, int y=0) : pos(x,y), content(nullptr) {}
};
