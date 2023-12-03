#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class A_star_2D
{
	vector<vector<int>> map;
	
public:

	A_star_2D(string map_file);
	void show_map();

    double calculateHeuristic(Point2D current, Point2D goal);
};

