#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

struct Point2D {
    double x, y;
    int access;
    Point2D(double x, double y) : x(x), y(y) {}
};