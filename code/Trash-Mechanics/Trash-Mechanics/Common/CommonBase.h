#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <memory>
#include <string>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define Power pow
#define Sqrt sqrt
#define K_Resilence 1
#define DEBUG_COMMON 0

const double pi = 3.141592653589793;
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
	Vec(const Vec &v);
	Vec operator +(const Vec &x) const;
	Vec operator -(const Vec &x) const;
	Vec operator *(const double &x) const; // multiplied by scaler
	Vec operator /(const double &x) const; // divided by scaler
	double operator ^(const Vec &x) const; // dot product
	double operator %(const Vec &x) const; // X product
	Vec& operator +=(const Vec &x);
	Vec& operator -=(const Vec &x);
	Vec& operator *=(const double &x); // multiplied by scaler
	Vec& operator /=(const double &x); // divided by scaler
	Vec& operator =(const Vec &x);
	bool setX(const double &x);
	bool setY(const double &y);
	double getX() const;
	double getY() const;
	bool setXY(const double &x, const double &y);
	double getAngle() const;
	double getMagnitude() const;
	void show() const;
	void rotate(const Vec &center, const double &angle);
	void rotate(const double &angle);
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
	Segment(const Segment &s):m_Vertex1(s.getV1()), m_Vertex2(s.getV2()){}
	Segment& operator =(const Segment &s) { m_Vertex1 = s.getV1(); m_Vertex2 = s.getV2(); }
	bool setV1(const Vec &v) { m_Vertex1 = v;  return true; }
	bool setV2(const Vec &v) { m_Vertex2 = v; return true; }
	bool set(const Vec &v1, const Vec &v2) { m_Vertex1 = v1;  m_Vertex2 = v2; return true; }
	Vec getV1() const { return m_Vertex1; } 
	Vec getV2() const { return m_Vertex2; } 

	virtual ~Segment() {}
};

class Poly
{
private:
	Vec m_CenterPoint;
	std::vector<Vec> m_Point; /* All the points must be arranged in an anti-clockwise order*/
	int m_PointNum;
	//string m_Image;
public:
	Poly(): m_CenterPoint() { m_PointNum = 0; }
	Poly(const Vec &center, const std::vector<Vec> &P) : m_CenterPoint(center), m_Point(P), m_PointNum(P.size()) {}
	Poly(const Poly &poly);
	Poly& operator =(const Poly &poly);
	bool setPoly(const Poly &poly);
	bool setPoly(const Vec &center, const std::vector<Vec> &P);
	Vec getCenterPoint() const { return m_CenterPoint; }
	int getPointNum() const { return m_PointNum; }
	std::vector<Vec> getPoint() const { return m_Point; }
	//bool isIntersected(const Segment &s) const;
	bool inPoly_Vec(const Vec &v) const;
	bool inPoly_PolyVec(const Poly &pol) const;
	Vec getInterPoint(const Poly &pol) const; //return the intersection point of this and pol polygons; if none, return originPoint
	Segment getInterSegment(const Poly &pol) const; //return the intersection segment of this and pol polygons; if none, return emptySegment
	bool move(const Vec &v);
	bool rotate(const double &angle, const Vec &center);
	bool rotate(const double &angle); // center is the mass center

	virtual ~Poly() {}
};

class RigidBody {
private:
	Poly m_Shape;
	Vec m_Force;
	Vec m_Velocity;
	double m_Mass;
	double m_InertiaConstant;
	double m_AngularVelocity;
	static int IdCount;
	int m_Id;
	int m_IdLastCollision;
public:
	RigidBody(const Poly &InputShape, const double &InputMass, const double &InputInertiaConstant, const Vec &InputVelocity, const double &InputAngularVelocity);
	RigidBody(const RigidBody &RB);
	RigidBody& operator = (const RigidBody &RB);
	double m() const; /* Mass */
	Vec v() const; /* Velocity */
	double vAbs() const; /* Magnitude of velocity */
	double i() const; /* Inertia constant */
	double w() const; /* Angular velocity */
	void applyForce(const Vec &NewForce);
	void removeForce();
	void move(const double &dt);
	void accelerate(const double &dt);
	void rotate(const double &dt);
	bool collide(RigidBody &Tag);/* Will modify this rigidbody and tag rigidbody!!! */
	Poly getShape() const;
	void cmdPrint() const;
	int getId() const;
};

double VecToVecDist(const Vec &v1, const Vec &v2);
double VecToSegmentDist(const Vec &v, const Segment &s);
double VecAngle(const Vec &v, const Vec &v1, const Vec &v2);

extern Vec originPoint;
extern Vec gravity;
extern Segment emptySegment;