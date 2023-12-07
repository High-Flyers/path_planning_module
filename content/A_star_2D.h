#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

#include "Point2d.h"

using namespace std;

class A_star_2D
{
	vector<Point2D> map;
	unordered_map<string, Point2D> VisitedNodes;
	double movementCost;
  double heuristicWeight;   

public:

	A_star_2D(string map_file);
	void show_map();
	double calculateCost(Point2D from, Point2D to);
	bool isValid(Point2D point);
	unordered_map<string, Point2D> getVisitedNodes();
  double calculateHeuristic(Point2D current, Point2D goal);

  void setCostFactors(double movementCost, double heuristicWeight);
  double getMovementCost();
  double getHeuristicWeight();
};

