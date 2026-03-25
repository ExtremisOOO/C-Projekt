#pragma once

// -----------------------------------------------------------------------------
// Klasa Point
struct Point {
    int x, y;
    Point(int x0=0, int y0=0): x(x0), y(y0) {}
    void set(int nx, int ny) { x = nx; y = ny; }
};
