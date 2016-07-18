/*
文件名：MazeMap.h
作用：定义Map类，生成地图
作者：罗九恒
版本：v1.0
日期：2016/7/13
*/

#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#define screenWidth 80     //屏幕宽度
#define screenHeight 25    //屏幕高度

#include "Public.h"

class MazeMap
{
public:
	MazeMap();//构造地图的函数
	//*MazeMap是地图二维数组的首址，row是地图数组中的行数，colume是地图数组中的列数
	MazeMap(int *mazeMap, int row, int column);
	void setMazeWall(char wall);//设置墙的字符
	void setMazeRoad(char road);//设置路的字符
	void defaultMode();         //设置默认地图
	void setMazeMap(int *mazeMap, int row , int colume);//重新设置地图
	void drawMap() const;//声明绘制地图的函数
	static char getRoadChar();//或许表示通路的字符
	static bool checkWallOrNot(int mazeX, int mazeY);//声明检查是否遇到迷宫墙壁
	static bool checkMazeDoor(int mazeX, int mazeY);//声明检查是否到达出口

private:

	char mazeWall;                     //声明迷宫表示墙壁的字符
	static char mazeRoad;              //声明迷宫表示通路的字符
	static int mazeWidth;              //声明迷宫的宽度
	static int mazeHeight;             //声明迷宫的高度
	static int mazeMapArray[screenHeight][screenWidth];//声明迷宫的地图数组

};
#endif 
