#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

#include "A_star_2D.h"

using namespace std;

int main()
{
	A_star_2D object("map.txt");
	object.show_map();
}