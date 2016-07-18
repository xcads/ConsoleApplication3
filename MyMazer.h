#ifndef MyMazer_H_
#define MyMazer_H_
#include "Public.H"

class MazePerson;                     //声明迷宫中人的类
class MyMazer
{
public:
	MyMazer();										                       //声明人的类的构造方法，默认初始化人的位置
	MyMazer(int currentX, int currentY);								   //声明人的类的构造方法，设定人的初始化位置
	MyMazer(int currentX, int currentY, objectiveDirections myForward);    //声明人的类的构造方法，设定人的初始化位置和方向，方向使用设置值:SOUTH,NORTH,WEST,EAST
	~MyMazer();															   //声明人的类的析构方法
	MyMazer &setPersonPosition(int coordinateX, int coordinateY);          //声明设定人的位置的方法
	MyMazer &setPersonChar(char personChar);                               //声明设定人的表示的方法
	MyMazer &setPersonForward(objectiveDirections myForward);              //声明设定人的方向的方法，方向使用设置值:SOUTH,NORTH,WEST,EAST 
	void setPersonPos(int coordX, int coordY);							   //声明设定人的表示的方法
	void setPersonPic(char personChar);									   //声明设定人的表示的方法
	void setPersonForwardDirection(objectiveDirections myForward);		   //声明设定人的方向的方法
	void setPersonSpeed(long speed);                                       //声明设置人当前速度的方法，直接使用数字
	void setPersonSpeed(int speed);                                        //声明设置人当前速度的方法，使用设定的值:FAST,MIDD,SLOW
	void start();                                                          //声明人开始运动的方法

private:
	MazePerson *mazePerson;												   //声明人的类的指针
};

#endif //MyMazer_H_
