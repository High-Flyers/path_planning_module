#include "A_star_2D.h"

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

A_star_2D::A_star_2D(string map_file)
{
	vector<vector<int>> read_data;

	ifstream file;
	file.open(map_file);

	if (file.is_open())
	{
		while (not file.eof())
		{
			string line;
			vector <int> row;
			getline(file, line);

			for (char x : line)
				row.push_back((int)x - 48);

			read_data.push_back(row);
		}
	}
	map = read_data;
}

void A_star_2D::show_map()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
			cout << '[' << map[i][j] << ']';
		cout << '\n';
	}
}

double A_star_2D::calculateCost(Point2D from, Point2D to)
{
	double dist{};
	double deltaX = fabs(to.x - from.x), deltaY = fabs(to.y - from.y);

	if (from.x == to.x)
		dist = deltaY;
	else if (from.y == to.y)
		dist = deltaX;	
	else if (deltaX > deltaY)
	{
		dist += deltaX - deltaY;
		dist += sqrt(2 * pow(deltaY, 2));
	}
	else
	{
		dist += deltaY - deltaX;	
		dist += sqrt(2 * pow(deltaX, 2));
	}
	return dist;
}

bool A_star_2D::isValid(Point2D point)
{
	return bool(point.access);
}

unordered_map <string,Point2D> A_star_2D::getVisitedNodes()
{
	return VisitedNodes;
}

double A_star_2D::calculateHeuristic(Point2D current, Point2D goal) {
    double dx = goal.x - current.x;
    double dy = goal.y - current.y;
    return sqrt(dx * dx + dy * dy);
}

void A_star_2D::setCostFactors(double movementCost, double heuristicWeight) {
    this->movementCost = movementCost;
    this->heuristicWeight = heuristicWeight;
}

double A_star_2D::getMovementCost() {
    return movementCost;
}

double A_star_2D::getHeuristicWeight() {
    return heuristicWeight;
}
