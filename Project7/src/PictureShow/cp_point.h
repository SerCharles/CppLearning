#ifndef CP_POINT_H
#define CP_POINT_H
class cp_point
{
public:
	double x, y;
public:
	cp_point():x(0),y(0){}
	~cp_point() {}
	void set(double a,double b);
	
};
#endif