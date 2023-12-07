#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Point2D {
    double x,y;
    Point2D( double x, double y) : x(x), y(y) {}
}

class A_star_2D
{
	vector<Point2D> map;
    double movementCost;
    double heuristicWeight;
public:

	A_star_2D(string map_file);
	void show_map();

    double calculateHeuristic(Point2D current, Point2D goal);

    void setCostFactors(double movementCost, double heuristicWeight);
    double getMovementCost();
    double getHeuristicWeight();

};

