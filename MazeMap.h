/*
�ļ�����MazeMap.h
���ã�����Map�࣬���ɵ�ͼ
���ߣ��޾ź�
�汾��v1.0
���ڣ�2016/7/13
*/

#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#define screenWidth 80     //��Ļ���
#define screenHeight 25    //��Ļ�߶�

#include "Public.h"

class MazeMap
{
public:
	MazeMap();//�����ͼ�ĺ���
	//*MazeMap�ǵ�ͼ��ά�������ַ��row�ǵ�ͼ�����е�������colume�ǵ�ͼ�����е�����
	MazeMap(int *mazeMap, int row, int column);
	void setMazeWall(char wall);//����ǽ���ַ�
	void setMazeRoad(char road);//����·���ַ�
	void defaultMode();         //����Ĭ�ϵ�ͼ
	void setMazeMap(int *mazeMap, int row , int colume);//�������õ�ͼ
	void drawMap() const;//�������Ƶ�ͼ�ĺ���
	static char getRoadChar();//�����ʾͨ·���ַ�
	static bool checkWallOrNot(int mazeX, int mazeY);//��������Ƿ������Թ�ǽ��
	static bool checkMazeDoor(int mazeX, int mazeY);//��������Ƿ񵽴����

private:

	char mazeWall;                     //�����Թ���ʾǽ�ڵ��ַ�
	static char mazeRoad;              //�����Թ���ʾͨ·���ַ�
	static int mazeWidth;              //�����Թ��Ŀ��
	static int mazeHeight;             //�����Թ��ĸ߶�
	static int mazeMapArray[screenHeight][screenWidth];//�����Թ��ĵ�ͼ����

};
#endif 
