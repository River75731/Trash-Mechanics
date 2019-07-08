#pragma once
#include <vector>
#include <string.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

const double pi = 3.1415926;
const double NearDist = 5.0;
const double eps = 0.01;
const double INF = (double)1.0e100;

static bool inPoint = false;
static bool inEdge = false;


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
	Vec();
	Vec(const double &x, const double &y);
	Vec operator +(const Vec &x) const;
	Vec operator -(const Vec &x) const;
	Vec& operator +=(const Vec &x);
	Vec& operator -=(const Vec &x);
	Vec& operator =(const Vec &x);
	bool setX(const double &x);
	bool setY(const double &y);
	double getX() const;
	double getY() const;
	bool setXY(const double &x, const double &y);
	double getAngle() const;
	double getMagnitude() const;
	void show() const;
	virtual ~Vec();
};

class Segment
{
private:
	Vec m_Vertex1;
	Vec m_Vertex2;
public:
	Segment() : m_Vertex1(), m_Vertex2() {};
	Segment(const Vec &v1, const Vec &v2) : m_Vertex1(v1), m_Vertex2(v2) {}
	bool setV1(const Vec &v) { m_Vertex1 = v;  return true; }
	bool setV2(const Vec &v) { m_Vertex2 = v; return true; }
	Vec getV1() const { return m_Vertex1; } 
	Vec getV2() const { return m_Vertex2; } 
	virtual ~Segment() {}
};

class Poly
{
private:
	Vec m_CenterPosition;
	std::vector<Vec> m_Point; /* All the points must be arranged in an anti-clockwise order*/
	int m_PointNum;
	//string m_Image;
public:
	Poly(): m_CenterPosition() { m_PointNum = 0; }
	Poly(const Vec &center, const std::vector<Vec> &P) : m_CenterPosition(center), m_Point(P), m_PointNum(P.size()) {}
	bool setPoly(const Vec &center, const std::vector<Vec> &P);
	//bool isIntersected(const Segment &s) const;
	bool inPoly(const Vec &v) const;
	virtual ~Poly() {}
};

double VecToVecDist(const Vec &v1, const Vec &v2);
double VecToSegmentDist(const Vec &v, const Segment &s);
double VecAngle(const Vec &v, const Vec &v1, const Vec &v2);
