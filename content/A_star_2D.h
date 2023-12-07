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
	vector<vector<int>> map;
	unordered_map<string, Point2D> VisitedNodes;
	
public:

	A_star_2D(string map_file);
	void show_map();
	double calculateCost(Point2D from, Point2D to);
	bool isValid(Point2D point);
	unordered_map<string, Point2D> getVisitedNodes();

	
};

