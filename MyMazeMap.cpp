/*
作者：罗九恒
时间：2016/7/14
*/

#include"MazeMap.h"
#include"MyMazeMap.H"

MyMazeMap::MyMazeMap()
{
	mazeMap = new MazeMap;
}
/*
迷宫
*/
MyMazeMap::MyMazeMap(int *myMazeMap, int row, int column) //: mazeMap(new MazeMap(myMazeMap, row, column))
{
	mazeMap = new MazeMap(myMazeMap, row, column);
}

/*
* 函数名称：defaultMode
* 函数功能：代理使用默认地图
*/
void MyMazeMap::defaultMode()
{
	mazeMap->defaultMode();
}

/*
* 函数名称：drawMap
* 函数功能：代理使用绘制迷宫地图
*/
void MyMazeMap::drawMap() const
{
	mazeMap->drawMap();
}

/*
* 函数名称：setMazeMap
* 函数功能：代理使用设置加载迷宫地图
*/
void MyMazeMap::setMazeMap(int *myMazeMap, int row, int column)
{
	mazeMap->setMazeMap(myMazeMap, row, column);
}

/*
* 函数名称：setMazeRoad
* 函数功能：代理使用设置绘制迷宫的通路字符
*/
void MyMazeMap::setMazeRoad(char road)
{
	mazeMap->setMazeRoad(road);
}

/*
* 函数名称：setMazeWall
* 函数功能：代理使用设置绘制迷宫的墙壁字符
*/
void MyMazeMap::setMazeWall(char wall)
{
	mazeMap->setMazeWall(wall);
}

/*
* 函数名称：~MyMazeMap
* 函数功能：释放内存对象
*/
MyMazeMap::~MyMazeMap()
{
	delete mazeMap;
}