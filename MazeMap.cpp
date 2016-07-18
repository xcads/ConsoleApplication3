/*
���֣�MazeMap.cpp
���ߣ��޾ź�
���ã����Ƶ�ͼ
���ڣ�2016/7/13
*/
#include <iostream>
#include "MazeMap.h"
using namespace std;

char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenHeight][screenWidth];
/*
���캯��Ĭ�ϳ�ʼ���Թ�
*/
MazeMap::MazeMap() :mazeWall('#')
{
	mazeWidth = 60;
	mazeHeight = 20;
}
/*
�����ʼ���Թ��Ŀ�͸ߣ�ǽ�ں�ͨ·
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
���ܣ������Թ��ĵ�ͼ
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
���ܣ�����·���ַ�
*/
void MazeMap::setMazeRoad(char road)
{
	mazeRoad = road;
}
/*
����:����ǽ���ַ�
*/
void MazeMap::setMazeWall(char wall)
{
	mazeWall = wall;
}
/*
����:����Ĭ�ϵ�ͼ
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
���ܣ����Ƶ�ͼ
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
* �������ƣ�getRoadChar
* �������ܣ���ȡ��ʾͨ·���ַ�
* �������ݣ���ʾͨ·���ַ�
*/
char MazeMap::getRoadChar()
{
	return mazeRoad;
}

/*
* �������ƣ�checkWallOrNot
* �������ܣ���̬����������λ�����Ƿ���ǽ��
* �������ݣ�true:��  false:����
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
���ܣ�����Ƿ�Ϊ����
*/
bool MazeMap::checkMazeDoor(int mazeX, int mazeY)
{
	//����Թ���������
	if (mazeX == 0 || mazeX == (mazeWidth - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	//����Թ���������
	if (mazeY == 0 || mazeY == (mazeHeight - 1))
	{
		if (mazeMapArray[mazeY][mazeX] == ROAD)
		{
			return true;
		}
	}
	return false;
}