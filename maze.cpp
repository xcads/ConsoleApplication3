#include <iostream>
#include <stdlib.h>
#include "MyMazeMap.H"
#include "MyMazer.h"
using namespace std;
const int SUCCESS = 0;
int main()
{

	int map[8][9] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, ROAD, WALL, WALL, ROAD, WALL },
		{ WALL, WALL, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, WALL, ROAD, WALL, WALL, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, ROAD, WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
	};
	MyMazeMap maze;
	maze.setMazeMap(&map[0][0], 8, 9);
	maze.setMazeWall('*');
	maze.drawMap();
	MyMazer mazer;
	mazer.setPersonPosition(1, 7);
	mazer.setPersonSpeed(FAST);
	mazer.setPersonChar('»À');
	mazer.start();

	system("pause");
	return SUCCESS;
	}
