#include "A_star_2D.h"

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

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
