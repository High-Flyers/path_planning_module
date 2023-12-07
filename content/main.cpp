#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

#include "A_star_2D.h"
#include "Point2d.h"

using namespace std;

int main()
{
	A_star_2D object("map.txt");
	object.show_map();
	Point2D from(1, 5), to(4, 1);
	double dist = object.calculateCost(from, to);
	cout << '\n' << dist;
}