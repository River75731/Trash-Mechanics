#include "CommonBase.h"

Vec originPoint(0, 0);
Vec gravity(0, 9.8);
Segment emptySegment(originPoint, originPoint);
int RigidBody::IdCount = -7; // There are 6 rigidbodys as map bound
int RigidBody::getIdCount()
{
	return IdCount;
}

Vec::Vec()
{
	m_X = m_Y = 0;
}

Vec::Vec(const double &x, const double &y)
{
	m_X = x;
	m_Y = y;
}

Vec::Vec(const Vec & v)
{
	this->m_X = v.getX();
	this->m_Y = v.getY();
}

Vec Vec::operator +(const Vec &x) const
{
	Vec t(this->m_X + x.m_X, this->m_Y + x.m_Y);
	return t;
}

Vec Vec::operator -(const Vec &x) const
{
	Vec t(this->m_X - x.m_X, this->m_Y - x.m_Y);
	return t;
}

Vec Vec::operator *(const double &x) const
{
	Vec t(x * this->getX(), x * this->getY());
	return t;
}

Vec Vec::operator/(const double & x) const
{
	Vec t(this->getX() / x, this->getY() / x);
	return t;
}

double Vec::operator %(const Vec & x) const
{
	return (this->getX() * x.getY() - x.getX() * this->getY());
}

double Vec::operator ^(const Vec & x) const
{
	return (this->getX() * x.getX() + this->getY() * x.getY());
}


Vec& Vec::operator +=(const Vec & x)
{
	this->m_X += x.m_X;
	this->m_Y += x.m_Y;
	return (*this);
}

Vec& Vec::operator -=(const Vec & x)
{
	this->m_X -= x.m_X;
	this->m_Y -= x.m_Y;
	return (*this);
}

Vec & Vec::operator *=(const double & x)
{
	(*this) = (*this) * x;
	return (*this);
}

Vec & Vec::operator/=(const double & x)
{
	(*this) = (*this) / x;
	return (*this);
}

Vec& Vec::operator =(const Vec &x)
{
	if (this == &x)
		return (*this);
	this->m_X = x.m_X;
	this->m_Y = x.m_Y;
	return (*this);
}

bool Vec::setX(const double &x)
{
	this->m_X = x;
	return true;
}

bool Vec::setY(const double &y)
{
	this->m_Y = y;
	return true;
}

double Vec::getX() const
{
	return this->m_X;
}

double Vec::getY() const
{
	return this->m_Y;
}

double Vec::getAngle() const
{
	return (std::atan2(m_Y, m_X));
}

double Vec::getMagnitude() const
{
	return (sqrt(m_X * m_X + m_Y * m_Y));
}

void Vec::show() const
{
	std::cout << "X " << m_X << " Y " << m_Y << std::endl;
}

void Vec::rotate(const Vec & center, const double &angle)
{
	Vec diff = (*this) - center;
	double r = diff.getMagnitude(), tAngle = diff.getAngle() + angle;
	this->setXY(center.getX() + r * cos(tAngle), center.getY() + r * sin(tAngle));
}

void Vec::rotate(const double & angle)
{
	this->Vec::rotate(originPoint, angle);
}

Vec::~Vec()
{
	return;
}

bool Vec::setXY(const double &x, const double &y)
{
	this->m_X = x;
	this->m_Y = y;
	return true;
}

Vec getTriangleCenter(const Vec &v1, const Vec &v2, const Vec &v3)
{
	return Vec((v1 + v2 + v3) / 3);
}

void Poly::clacCenterPointAndArea()
{
	Vec v(*(m_Point.begin()));
	m_CenterPoint.setXY(0, 0);
	m_area = 0.0;
	for (std::vector<Vec>::iterator i = (m_Point.begin() + 1); i != (m_Point.end() - 1); i++)
	{
		Vec v1(*i), v2(*(i + 1));
		double area = getTriangleArea(v, v1, v2);
		m_CenterPoint += getTriangleCenter(v, v1, v2) * area;
		m_area += area;
	}
	m_CenterPoint /= m_area;
}

Poly::Poly(const std::vector<Vec>& P) : m_Point(P), m_PointNum(P.size())
{
	clacCenterPointAndArea();
}

Poly::Poly(const Poly & poly)
{
	m_CenterPoint = poly.m_CenterPoint;
	m_Point = poly.m_Point;
	m_PointNum = poly.m_PointNum;
	m_area = poly.getArea();
}

Poly & Poly::operator=(const Poly & poly)
{
	m_CenterPoint = poly.m_CenterPoint;
	m_Point = poly.m_Point;
	m_PointNum = poly.m_PointNum;
	m_area = poly.getArea();
	return *this;
}

bool Poly::setPoly(const Poly & poly)
{
	m_CenterPoint = poly.m_CenterPoint;
	m_Point = poly.m_Point;
	m_PointNum = poly.m_PointNum;
	m_area = poly.getArea();
	return true;
}

bool Poly::setPoly(const Vec &center, const std::vector<Vec> &P)
{
	m_CenterPoint = center;
	m_Point = P;
	m_PointNum = P.size(); 
	clacCenterPointAndArea();
	return false;
}

void Poly::show() const
{
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		i->show();
	}
}

bool Poly::inPoly_Vec(const Vec &v) const
{
	if (this->m_PointNum == 1)
		return false;
	inPoint = false;
	inEdge = false;
	double angleSum = 0.0;
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		Vec v1(*i), v2;
		if (i == m_Point.end() - 1) v2 = *(m_Point.begin());
		else v2 = *(i + 1);
		angleSum += VecAngle(v, v1, v2);
		if (inPoint || inEdge) return true;
	}
	if (fabs(angleSum - 2 * pi) < eps)
		return true;
	return false;
}

bool Poly::inPoly_PolyVec(const Poly &pol) const
{
	std::vector<Vec> myvec = pol.getPoint();

	for (std::vector<Vec>::iterator i = myvec.begin(); i != myvec.end(); i++)
	{
		if (this->inPoly_Vec(*i)) {
			return true;
		}

	}
	return false;
}

Vec Poly::getInterPoint(const Poly & pol) const
{
	std::vector<Vec> myvec = pol.getPoint();
	Vec ret = originPoint;
	int interpointnum = 0;
	for (std::vector<Vec>::const_iterator i = myvec.begin(); i != myvec.end(); i++)
	{
		if (this->inPoly_Vec(*i)) {
			ret+= *i;
			return ret;
			interpointnum++;
		}
			
	}
	return ret / interpointnum;
}

Segment Poly::getInterSegment(const Poly & pol) const
{
	if (inPoly_PolyVec(pol) == false)
		return emptySegment;
	double m = INF;
	Segment ms;
	Vec v(getInterPoint(pol));
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		Vec v1(*i), v2;
		if (i == (m_Point.end() - 1)) v2 = *(m_Point.begin());
		else v2 = *(i + 1);
		Segment s(v1, v2);
		if (m > VecToSegmentDist(v, s))
		{
			m = VecToSegmentDist(v, s);
			ms.set(v1, v2);
		}
	}
	return ms;
}

Vec Poly::getNearestPoint(const Vec & v) const
{
	double m = INF, r;
	Vec mv(originPoint);
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		if (m > (r = VecToVecDist(*i, v)))
		{
			mv = *i;
			m = r;
		}
	}
	return mv;
}

bool Poly::move(const Vec & v)
{
	for (std::vector<Vec>::iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		(*i) += v;
	}
	m_CenterPoint += v;
	return false;
}

bool Poly::rotate(const double & angle, const Vec & center)
{
	for (std::vector<Vec>::iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		i->rotate(center, angle);
	}
	return true;
}

bool Poly::rotate(const double & angle)
{
	this->rotate(angle, this->m_CenterPoint);
	return true;
}

double VecToVecDist(const Vec &v1, const Vec &v2)
{
	return ((v1 - v2).getMagnitude());
}

double VecToSegmentDist(const Vec &v, const Segment &s)
{
	Vec v1 = s.getV1();
	Vec v2 = s.getV2();
	double d1 = VecToVecDist(v, v1);
	double d2 = VecToVecDist(v, v2);
	double A = v1.getY() - v2.getY();
	double B = v2.getX() - v1.getX();
	double C = v1.getX() * v2.getY() - v2.getX() * v1.getY();
	double d3 = fabs(A * v.getX() + B * v.getY() + C) / sqrt(A * A + B * B);
	if (((v - v1) ^ (v2 - v1)) >= 0 && ((v - v2) ^ (v1 - v2)) >= 0)
		return d3;
	return min(d1, d2);
}

double VecAngle(const Vec &v, const Vec &v1, const Vec &v2)
{
	double a = VecToVecDist(v, v1);
	double b = VecToVecDist(v, v2);
	double c = VecToVecDist(v1, v2);
	if (fabs(a) < eps || fabs(b) < eps)
	{
		inPoint = true;
		return 0.0;
	}
	if (VecToSegmentDist(v, Segment(v1, v2)) < eps)
	{
		inEdge = true;
		return 0;
	}
	long double x = (a * a + b * b - c * c) / (2 * a * b);
	//std::cout << x << std::endl;
	return acos(x);
}

double getTriangleArea(const Vec & v, const Vec & v1, const Vec & v2)
{
	return ((v1 - v) % (v2 - v)) * 0.5;
}

double getTriangleInertiaConstant(const Vec & v1, const Vec & v2, const Vec & v3)
{
	double a = (v1 - v2).getMagnitude();
	double b = (v2 - v3).getMagnitude();
	double c = (v1 - v3).getMagnitude();
	return (a * a + b * b + c * c) / 36;
}

void RigidBody::clacInertiaConstant()
{

	m_InertiaConstant = 0.0;
	double rou = m_Mass / m_Shape.getArea();
	std::cout << "rou = " << rou << " mass = " << m_Mass << " area = " << m_Shape.getArea();
	Vec v(*(m_Shape.getPoint().begin()));
	Vec vc(m_Shape.getCenterPoint());
	//std::cout << '?';	
	std::vector<Vec> point(m_Shape.getPoint());
	std::cout << point.size();
	for (std::vector<Vec>::iterator i = (point.begin() + 1); i != (point.end() - 1); i++)
	{
		Vec v1(*i), v2(*(i + 1));
		double dS = getTriangleArea(v, v1, v2);
		double dm = rou * dS;
		double ICaxis = getTriangleInertiaConstant(v, v1, v2) * dm;
		double ICreal = ICaxis + dm * ((v - vc).getMagnitude() * (v - vc).getMagnitude());
		m_InertiaConstant += ICreal;
	}
	std::cout << " Inertia Constant = "<<m_InertiaConstant << std::endl;

}

RigidBody::RigidBody(const Poly &InputShape, const double &InputMass, const Vec &InputVelocity, const double &InputAngularVelocity) {
	m_Shape = InputShape;
	m_Mass = InputMass;
	m_Velocity = InputVelocity;
	m_AngularVelocity = InputAngularVelocity;
	m_IdLastCollision = NULL;
	m_CoolDown = NULL;
	m_Id = ++IdCount;
	clacInertiaConstant();
}

RigidBody::RigidBody(const RigidBody & RB) {
	m_Shape = RB.m_Shape;
	m_Force = RB.m_Force;
	m_Velocity = RB.m_Velocity;
	m_InertiaConstant = RB.m_InertiaConstant;
	m_AngularVelocity = RB.m_AngularVelocity;
	m_IdLastCollision = RB.m_IdLastCollision;
	m_Mass = RB.m_Mass;
	m_CoolDown = RB.m_CoolDown;
	m_Id = RB.m_Id;
}

RigidBody & RigidBody::operator=(const RigidBody & RB) {
	m_Shape = RB.m_Shape;
	m_Force = RB.m_Force;
	m_Velocity = RB.m_Velocity;
	m_InertiaConstant = RB.m_InertiaConstant;
	m_AngularVelocity = RB.m_AngularVelocity;
	m_IdLastCollision = RB.m_IdLastCollision;
	m_Mass = RB.m_Mass;
	m_CoolDown = RB.m_CoolDown;
	m_Id = RB.m_Id;
	return *this;
}

void RigidBody::applyForce(const Vec &NewForce) {
	m_Force = NewForce;
}

void RigidBody::removeForce() {
	m_Force = originPoint;
}

double RigidBody::m() const {
	return m_Mass;
}

Vec RigidBody::v() const {
	return m_Velocity;
}

double RigidBody::vAbs() const {
	return m_Velocity.getMagnitude();
}

double RigidBody::i() const {
	return m_InertiaConstant;
}
double RigidBody::w() const {
	return m_AngularVelocity;
}

void RigidBody::move(const double &dt) {
	if (m_Mass > 0.5 * INF) return;
	if (m_CoolDown) m_CoolDown--;
	if (!m_CoolDown) m_IdLastCollision = NULL;
	/* dx=v*dt */
	m_Shape.move(m_Velocity*dt);
}

void RigidBody::accelerate(const double &dt) {
	/* F=ma */
	m_Velocity += (m_Force / m_Mass) * dt;
}

void RigidBody::rotate(const double &dt) {
	/* dtheta=omega*dt */
	m_Shape.rotate(m_AngularVelocity*dt);
}

bool RigidBody::collide(RigidBody &Tag) {
	if (Tag.m_Mass >= 0.5*INF ) {
		//&& Tag.m_Mass >= 0.5*INF
		return false;
	}
	if (m_Id == -2) // the virtual middle wall
		return false;
	if (m_Shape.inPoly_PolyVec(Tag.m_Shape) == false) {	
		if (Tag.m_IdLastCollision == m_Id) Tag.m_IdLastCollision = NULL;
		return false;
	}
//	if (Tag.m_IdLastCollision == m_Id) return false;
	m_IdLastCollision = Tag.m_Id;
	m_CoolDown = cooldownTurn;
	Tag.m_IdLastCollision = m_Id;
	Tag.m_CoolDown = cooldownTurn;
	/* Tag insert into this */
	double cax = Tag.getShape().getCenterPoint().getX();
	double cay = Tag.getShape().getCenterPoint().getY();
	double vax = Tag.v().getX();
	double vay = Tag.v().getY();
	double wa = Tag.w();
	double ma = Tag.m();
	double ia = Tag.i();
	double cbx = getShape().getCenterPoint().getX();
	double cby = getShape().getCenterPoint().getY();
	double vbx = v().getX();
	double vby = v().getY();
	double wb = w();
	double mb = m();
	double ib = i();
	Vec point = getShape().getInterPoint(Tag.getShape());
	Segment seg = getShape().getInterSegment(Tag.getShape());
	double ox = point.getX();
	double oy = point.getY();
	double fx;
	double fy;
	Vec dir = seg.getV2() - seg.getV1();
	Vec normal(dir.getY(), -dir.getX());
	normal = normal / normal.getMagnitude();
	/*
	if (fabs(dir.getY()) < 0.01) {
		fx = 0;
		fy = K_Resilence ;
	}
	else if (fabs(dir.getX()) < 0.01) {
		fx = K_Resilence ;
		fy = 0;
	}
	else {
		fx = K_Resilence ;
		fy = -dir.getX()*fx / dir.getY();
	}
	if (Vec(ox - cax, oy - cay) ^ Vec(fx, fy)) { fx *= -1; fy *= -1; }*/
	fx = normal.getX() * K_Resilence;
	fy = normal.getY() * K_Resilence;
	double distV2S = VecToSegmentDist(point, seg);
	Vec positionCorrection(normal * distV2S); // avoid inserted bug

	double k = 0.9;

#if DEBUG_COMMON==1 
	printf("A(before collision): m=%.2lf i=%.2lf v=(%.2lf,%.2lf) w=%.2lf\n", ma, ia, vax, vay, wa);
	printf("B(before collision): m=%.2lf i=%.2lf v=(%.2lf,%.2lf) w=%.2lf\n", mb, ib, vbx, vby, wb);
	printf("f=(%.2lf,%.2lf)\n", fx, fy);
#endif
	double deltat = (2 * (-(fx*vax) - fy * vay + fx * vbx + fy * vby - cay * fx*wa + cax * fy*wa - fy * ox*wa + fx * oy*wa + cby * fx*wb - cbx * fy*wb + fy * ox*wb - fx * oy*wb)) /
		((Power(cay, 2)*Power(fx, 2)) / ia - (2 * cax*cay*fx*fy) / ia + (Power(cax, 2)*Power(fy, 2)) / ia + (Power(cby, 2)*Power(fx, 2)) / ib - (2 * cbx*cby*fx*fy) / ib + (Power(cbx, 2)*Power(fy, 2)) / ib +
			Power(fx, 2) / ma + Power(fy, 2) / ma + Power(fx, 2) / mb + Power(fy, 2) / mb + (2 * cay*fx*fy*ox) / ia - (2 * cax*Power(fy, 2)*ox) / ia + (2 * cby*fx*fy*ox) / ib - (2 * cbx*Power(fy, 2)*ox) / ib +
			(Power(fy, 2)*Power(ox, 2)) / ia + (Power(fy, 2)*Power(ox, 2)) / ib - (2 * cay*Power(fx, 2)*oy) / ia + (2 * cax*fx*fy*oy) / ia - (2 * cby*Power(fx, 2)*oy) / ib + (2 * cbx*fx*fy*oy) / ib - (2 * fx*fy*ox*oy) / ia -
			(2 * fx*fy*ox*oy) / ib + (Power(fx, 2)*Power(oy, 2)) / ia + (Power(fx, 2)*Power(oy, 2)) / ib);
	double sln1 = (2 * fx*vax + 2 * fy*vay - 2 * fx*vbx - 2 * fy*vby + 2 * cay*fx*wa - 2 * cax*fy*wa + 2 * fy*ox*wa - 2 * fx*oy*wa - 2 * cby*fx*wb + 2 * cbx*fy*wb - 2 * fy*ox*wb + 2 * fx*oy*wb -
		Sqrt(Power(-2 * fx*vax - 2 * fy*vay + 2 * fx*vbx + 2 * fy*vby - 2 * cay*fx*wa + 2 * cax*fy*wa - 2 * fy*ox*wa + 2 * fx*oy*wa + 2 * cby*fx*wb - 2 * cbx*fy*wb + 2 * fy*ox*wb - 2 * fx*oy*wb, 2) -
			4 * (-((Power(cay, 2)*Power(fx, 2)) / ia) + (2 * cax*cay*fx*fy) / ia - (Power(cax, 2)*Power(fy, 2)) / ia - (Power(cby, 2)*Power(fx, 2)) / ib + (2 * cbx*cby*fx*fy) / ib - (Power(cbx, 2)*Power(fy, 2)) / ib -
				Power(fx, 2) / ma - Power(fy, 2) / ma - Power(fx, 2) / mb - Power(fy, 2) / mb - (2 * cay*fx*fy*ox) / ia + (2 * cax*Power(fy, 2)*ox) / ia - (2 * cby*fx*fy*ox) / ib + (2 * cbx*Power(fy, 2)*ox) / ib -
				(Power(fy, 2)*Power(ox, 2)) / ia - (Power(fy, 2)*Power(ox, 2)) / ib + (2 * cay*Power(fx, 2)*oy) / ia - (2 * cax*fx*fy*oy) / ia + (2 * cby*Power(fx, 2)*oy) / ib - (2 * cbx*fx*fy*oy) / ib + (2 * fx*fy*ox*oy) / ia +
				(2 * fx*fy*ox*oy) / ib - (Power(fx, 2)*Power(oy, 2)) / ia - (Power(fx, 2)*Power(oy, 2)) / ib)*
				(-(ma*Power(vax, 2)) + k * ma*Power(vax, 2) - ma * Power(vay, 2) + k * ma*Power(vay, 2) - mb * Power(vbx, 2) + k * mb*Power(vbx, 2) - mb * Power(vby, 2) + k * mb*Power(vby, 2) - ia * Power(wa, 2) +
					ia * k*Power(wa, 2) - ib * Power(wb, 2) + ib * k*Power(wb, 2)))) /
					(2.*(-((Power(cay, 2)*Power(fx, 2)) / ia) + (2 * cax*cay*fx*fy) / ia - (Power(cax, 2)*Power(fy, 2)) / ia - (Power(cby, 2)*Power(fx, 2)) / ib + (2 * cbx*cby*fx*fy) / ib - (Power(cbx, 2)*Power(fy, 2)) / ib -
						Power(fx, 2) / ma - Power(fy, 2) / ma - Power(fx, 2) / mb - Power(fy, 2) / mb - (2 * cay*fx*fy*ox) / ia + (2 * cax*Power(fy, 2)*ox) / ia - (2 * cby*fx*fy*ox) / ib + (2 * cbx*Power(fy, 2)*ox) / ib -
						(Power(fy, 2)*Power(ox, 2)) / ia - (Power(fy, 2)*Power(ox, 2)) / ib + (2 * cay*Power(fx, 2)*oy) / ia - (2 * cax*fx*fy*oy) / ia + (2 * cby*Power(fx, 2)*oy) / ib - (2 * cbx*fx*fy*oy) / ib + (2 * fx*fy*ox*oy) / ia +
						(2 * fx*fy*ox*oy) / ib - (Power(fx, 2)*Power(oy, 2)) / ia - (Power(fx, 2)*Power(oy, 2)) / ib));
	double sln2 = (2 * fx*vax + 2 * fy*vay - 2 * fx*vbx - 2 * fy*vby + 2 * cay*fx*wa - 2 * cax*fy*wa + 2 * fy*ox*wa - 2 * fx*oy*wa - 2 * cby*fx*wb + 2 * cbx*fy*wb - 2 * fy*ox*wb + 2 * fx*oy*wb +
		Sqrt(Power(-2 * fx*vax - 2 * fy*vay + 2 * fx*vbx + 2 * fy*vby - 2 * cay*fx*wa + 2 * cax*fy*wa - 2 * fy*ox*wa + 2 * fx*oy*wa + 2 * cby*fx*wb - 2 * cbx*fy*wb + 2 * fy*ox*wb - 2 * fx*oy*wb, 2) -
			4 * (-((Power(cay, 2)*Power(fx, 2)) / ia) + (2 * cax*cay*fx*fy) / ia - (Power(cax, 2)*Power(fy, 2)) / ia - (Power(cby, 2)*Power(fx, 2)) / ib + (2 * cbx*cby*fx*fy) / ib - (Power(cbx, 2)*Power(fy, 2)) / ib -
				Power(fx, 2) / ma - Power(fy, 2) / ma - Power(fx, 2) / mb - Power(fy, 2) / mb - (2 * cay*fx*fy*ox) / ia + (2 * cax*Power(fy, 2)*ox) / ia - (2 * cby*fx*fy*ox) / ib + (2 * cbx*Power(fy, 2)*ox) / ib -
				(Power(fy, 2)*Power(ox, 2)) / ia - (Power(fy, 2)*Power(ox, 2)) / ib + (2 * cay*Power(fx, 2)*oy) / ia - (2 * cax*fx*fy*oy) / ia + (2 * cby*Power(fx, 2)*oy) / ib - (2 * cbx*fx*fy*oy) / ib + (2 * fx*fy*ox*oy) / ia +
				(2 * fx*fy*ox*oy) / ib - (Power(fx, 2)*Power(oy, 2)) / ia - (Power(fx, 2)*Power(oy, 2)) / ib)*
				(-(ma*Power(vax, 2)) + k * ma*Power(vax, 2) - ma * Power(vay, 2) + k * ma*Power(vay, 2) - mb * Power(vbx, 2) + k * mb*Power(vbx, 2) - mb * Power(vby, 2) + k * mb*Power(vby, 2) - ia * Power(wa, 2) +
					ia * k*Power(wa, 2) - ib * Power(wb, 2) + ib * k*Power(wb, 2)))) /
					(2.*(-((Power(cay, 2)*Power(fx, 2)) / ia) + (2 * cax*cay*fx*fy) / ia - (Power(cax, 2)*Power(fy, 2)) / ia - (Power(cby, 2)*Power(fx, 2)) / ib + (2 * cbx*cby*fx*fy) / ib - (Power(cbx, 2)*Power(fy, 2)) / ib -
						Power(fx, 2) / ma - Power(fy, 2) / ma - Power(fx, 2) / mb - Power(fy, 2) / mb - (2 * cay*fx*fy*ox) / ia + (2 * cax*Power(fy, 2)*ox) / ia - (2 * cby*fx*fy*ox) / ib + (2 * cbx*Power(fy, 2)*ox) / ib -
						(Power(fy, 2)*Power(ox, 2)) / ia - (Power(fy, 2)*Power(ox, 2)) / ib + (2 * cay*Power(fx, 2)*oy) / ia - (2 * cax*fx*fy*oy) / ia + (2 * cby*Power(fx, 2)*oy) / ib - (2 * cbx*fx*fy*oy) / ib + (2 * fx*fy*ox*oy) / ia +
						(2 * fx*fy*ox*oy) / ib - (Power(fx, 2)*Power(oy, 2)) / ia - (Power(fx, 2)*Power(oy, 2)) / ib));
//	printf("sln1:%lf  sln2:%lf\n", sln1, sln2);
//	if (sln1 > 0) deltat = sln1;
//		else if(sln2 > 0) deltat = sln2;
	vax += fx / ma * deltat;
	vay += fy / ma * deltat;
	wa += (-(cax - ox)*fy + (cay - oy)*fx) / ia * deltat;
	vbx -= fx / mb * deltat;
	vby -= fy / mb * deltat;
	wb -= (-(cbx - ox)*fy + (cby - oy)*fx) / ib * deltat;
	Tag.m_Velocity = Vec(vax, vay);
	Tag.m_AngularVelocity = wa;
	m_Velocity = Vec(vbx, vby);
	m_AngularVelocity = wb;
	#if DEBUG_COMMON == 1
	std::cout << "position correction = ";
	positionCorrection.show();
	#endif
	if (m_Mass >= INF * 0.5)
	{
		Tag.m_Shape.move(positionCorrection);

	}
		
	else
	{
		Tag.m_Shape.move(positionCorrection);
		//this->m_Shape.move(positionCorrection * -0.6);
	}
#if DEBUG_COMMON==1
	printf("collision time:%lf\n", deltat);
	printf("A(after collision): m=%.2lf i=%.2lf v=(%lf,%lf) w=%lf\n", ma, ia, vax, vay, wa);
	printf("B(after collision): m=%.2lf i=%.2lf v=(%lf,%lf) w=%lf\n", mb, ib, vbx, vby, wb);
#endif
	return true;
}

Poly RigidBody::getShape() const 
{
	return m_Shape;
}

void RigidBody::cmdPrint() const 
{
	printf("Rigidbody Id[%d] Address[%X]:\n", m_Id, (unsigned int)this);
	printf("	ctr: (%lf,%lf)\n", m_Shape.getCenterPoint().getX(), m_Shape.getCenterPoint().getY());
	printf("	vertices num: %d\n", m_Shape.getPoint().size());
	for (unsigned int i = 0; i < m_Shape.getPoint().size(); i++) printf("	(%lf,%lf)\n", m_Shape.getPoint()[i].getX(), m_Shape.getPoint()[i].getY());
}

int RigidBody::getId() const {
	return m_Id;
}
