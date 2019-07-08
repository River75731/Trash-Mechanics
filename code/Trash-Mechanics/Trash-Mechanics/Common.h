#pragma once
#include <vector>
#include <string.h>
typedef enum
{
	PractiseMode = 0,
	RealityMode
} ModeType;

typedef enum
{
	Easy = 0,
	Medium,
	Hard,
	Nightmare,
	Custom
} DiffcultyType;

typedef enum
{
	Harzardous = 0, //harmful
	Recyclable,
	Residnal, //dry
	Household //wet
} TrashType;

class Vec
{
private:
	double m_X;
	double m_Y;
public:
	bool setX(double x);
	bool setY(double y);
	double getX();
	double getY();
	bool setXY(double x, double y);
	double getAngle();
	double getMagnitude();
};

class Line
{
private:
	Vec m_Vertex1;
	Vec m_Vertex2;
public:
};

class Polygon
{
private:
	Vec m_CenterPosition;
	std::vector<Vec> m_Position;
	//string mImage;
public:
	bool intersection(Line l);
	bool inPolygon(Vec vec);
};
