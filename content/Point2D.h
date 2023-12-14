#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

struct coords {

    double x, y;
};

struct Point2D : coords{

    bool access;
    double mCost = DBL_MAX,
        hCost = DBL_MAX,
        fCost = DBL_MAX;
    coords parent;


    Point2D(double X, double Y)
    {
        this->x = X;
        this->y = Y;
    }
};