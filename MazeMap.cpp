/*
名字：MazeMap.cpp
作者：罗九恒
作用：绘制地图
日期：2016/7/13
*/
#include <iostream>
#include "MazeMap.h"
using namespace std;

char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenHeight][screenWidth];
/*
构造函数默认初始化迷宫
*/
MazeMap::MazeMap() :mazeWall('#')
{
	mazeWidth = 60;
	mazeHeight = 20;
}
/*
构造初始化迷宫的宽和高，墙壁和通路
*/
MazeMap::MazeMap(int *mazeMap, int row, int column) :mazeWall('#')
{
	mazeHeight = row;
	mazeWidth = column;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}
/*
功能：重置迷宫的地图
*/
void MazeMap::setMazeMap(int *mazeMap, int row, int column)
{
	mazeHeight = row;
	mazeWidth = column;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}
/*
功能：设置路的字符
*/
void MazeMap::setMazeRoad(char road)
{
	mazeRoad = road;
}
/*
功能:设置墙的字符
*/
void MazeMap::setMazeWall(char wall)
{
	mazeWall = wall;
}
/*
功能:定义默认地图
*/
void MazeMap::defaultMode()
{
	int mazeMap[6][6] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, WALL, WALL, WALL, ROAD, ROAD },
		{ WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL }
	};
	setMazeMap(&mazeMap[0][0], 6, 6);
}
/*
功能：绘制地图
*/
void MazeMap::drawMap() const
{
	for (int i = 0; i < mazeHeight; i++)
	{
		for (int j = 0; j < mazeWidth; j++)
		{
			if (mazeMapArray[i][j] == 1)
			{
				cout << mazeWall;
			}
			else
			{
				cout << mazeRoad;
			}
		}
		cout << endl;
	}
}
/*
* 函数名称：getRoadChar
* 函数功能：获取表示通路的字符
* 返回内容：表示通路的字符
*/
char MazeMap::getRoadChar()
{
	return mazeRoad;
}

/*
* 函数名称：checkWallOrNot
* 函数功能：静态方法，检查该位置上是否是墙壁
* 返回内容：true:是  false:不是
*/
bool MazeMap::checkWallOrNot(int mazeX, int mazeY)
{
	if (mazeMapArray[mazeY][mazeX] == WALL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
功能：检查是否为出口
*/
bool MazeMap::checkMazeDoor(int mazeX, int mazeY)
{
	//检查迷宫左右两侧
	if (mazeX == 0 || mazeX == (mazeWidth - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	//检查迷宫上下两侧
	if (mazeY == 0 || mazeY == (mazeHeight - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	return false;
}