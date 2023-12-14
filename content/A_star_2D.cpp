#include "A_star_2D.h"

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

A_star_2D::A_star_2D(string map_file)
{
	vector<vector<double>> read_data;

	ifstream file;
	file.open(map_file);

	if (file.is_open())
	{
		while (not file.eof())
		{
			string line;
			vector <double> row;
			getline(file, line);

			for (char x : line)
				row.push_back((double)x - 48);

			read_data.push_back(row);
		}
	}
	map = read_data;

	neighbourhood = { {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };
}

void A_star_2D::show_map()
{
	for (double i = 0; i < map.size(); i++)
	{
		for (double j = 0; j < map[i].size(); j++)
			cout << '[' << map[i][j] << ']';
		cout << '\n';
	}
}

double A_star_2D::calculateMovement(Point2D start, Point2D current)
{
	double dist{};
	double deltaX = fabs(current.x - start.x), deltaY = fabs(current.y - start.y);

	if (start.x == current.x)
		dist = deltaY;
	else if (start.y == current.y)
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

Point2D A_star_2D::startValidation(coords point)
{
	Point2D temp(point.x, point.y);
	temp.access	= bool(map[point.y][point.x]);

	if (not(temp.access))
		cout << "\nunavailable coordinates\n";
	
	return temp;
}

unordered_map <string,Point2D> A_star_2D::getVisitedNodes()
{
	return visitedNodes;
}

double A_star_2D::calculateHeuristic(Point2D current, Point2D goal) {
    double dx = goal.x - current.x;
    double dy = goal.y - current.y;
    return sqrt(dx * dx + dy * dy);
}

double A_star_2D::calculateFullCost(Point2D start, Point2D current, Point2D goal)
{
	return calculateMovement(start, current) + calculateHeuristic(current, goal);
}

string A_star_2D::getCoordsInString(Point2D point)
{
	string temp;
	temp.push_back(char(point.x));
	temp.push_back(',');
	temp.push_back(char(point.y));
	return temp;
}

string A_star_2D::getCoordsInString(coords point)
{
	string temp;
	temp.push_back(char(point.x));
	temp.push_back(char(point.y));
	return temp;
}

coords A_star_2D::getCoords(Point2D point)
{
	coords temp;
	temp.x = point.x;
	temp.y = point.y;
	return temp;
}

void A_star_2D::setCostFactors(double movementCost, double heuristicCost) {
    this->movementCost = movementCost;
    this->heuristicCost = heuristicCost;
}

double A_star_2D::getMovementCost() {
    return movementCost;
}

double A_star_2D::getHeuristicCost() {
    return heuristicCost;
}

string A_star_2D::getOptimalNodeIndex()
{
	double minCost = DBL_MAX;
	string optimalIndex;

	for (auto it : openNodes)
	{
		if (it.second.fCost <= minCost)
		{
			minCost = it.second.fCost;
			optimalIndex = it.first;
		}
	}
	return optimalIndex;
}

deque<coords> A_star_2D::pathPlanner(coords startCoords, coords finishCoords) {
	bool findingPath = false;
	
	Point2D startPoint = startValidation(startCoords);
	string startIndex = getCoordsInString(startCoords);
	Point2D finishPoint = startValidation(finishCoords);
	string finishIndex = getCoordsInString(finishCoords);

	if (startPoint.access and finishPoint.access)
	{
		openNodes.insert({startIndex, startPoint});

		while (!findingPath)
		{
			string currentIndex = getOptimalNodeIndex();
			Point2D current = openNodes.at(currentIndex);
			openNodes.erase(currentIndex);
			visitedNodes.insert({ currentIndex, current});

			if (currentIndex == finishIndex) {
				findingPath = true;
				continue;

			}
				

			for (int i = 0; i < 8; i++) {
				double neigh_x = current.x + neighbourhood[i].x,
					neigh_y = current.y + neighbourhood[i].y;
				      
				Point2D neighbour(neigh_x, neigh_y);
				neighbour.access = bool(map[neigh_y][neigh_x]);
				if ((not neighbour.access) or visitedNodes.contains(currentIndex))
					continue;

				double neighFullCost = calculateFullCost(startPoint, neighbour, finishPoint);
				string neighIndex = getCoordsInString(neighbour);

				if (neighFullCost < neighbour.fCost 
					or openNodes.contains(neighIndex)) {
					neighbour.fCost = neighFullCost;
					neighbour.parent.x = current.x;
					neighbour.parent.y = current.y;

					if (not openNodes.contains(neighIndex))
						openNodes.insert({ neighIndex, neighbour });
				}
			}
		}
		bool findingStart = false;
		string parentResearchIndex, researchIndex = finishIndex;
		deque<coords> path;

		while (not findingStart) {
			Point2D researchPoint = visitedNodes.at(researchIndex);
			path.push_front(getCoords(researchPoint));
			parentResearchIndex = getCoordsInString(researchPoint.parent);

			researchPoint = visitedNodes.at(parentResearchIndex);
			path.push_front(getCoords(researchPoint));
			parentResearchIndex = getCoordsInString(researchPoint.parent);

			if (getCoordsInString(researchPoint) == startIndex)
				return path;
		}


	
	};
}