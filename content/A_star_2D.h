#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <deque>

#include "Point2d.h"

using namespace std;

class A_star_2D
{
	vector<vector<double>> map;
	unordered_map<string,Point2D> openNodes;
	unordered_map<string,Point2D> visitedNodes;
	double movementCost;
	double heuristicCost;  
	vector<coords> neighbourhood;

public:

	A_star_2D(string map_file);

	unordered_map<string, Point2D> getVisitedNodes();

	void show_map();
	bool isValid(Point2D point);
	Point2D startValidation(coords point);
	void setCostFactors(double movementCost, double heuristicCost);
	double getMovementCost();
	double getHeuristicCost();
	string getOptimalNodeIndex();
	double calculateFullCost(Point2D start, Point2D current, Point2D goal);
	double calculateMovement(Point2D start, Point2D current);
	double calculateHeuristic(Point2D current, Point2D goal);
	string getCoordsInString(Point2D point);
	string getCoordsInString(coords point);
	coords getCoords(Point2D point);
	deque<coords> pathPlanner(coords startCoords, coords finishCoords);

};

