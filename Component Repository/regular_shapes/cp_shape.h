#ifndef CP_SHAPE_H
#define CP_SHAPE_H
class cp_shape
{
public:
	double area;
	double length;
public:
	cp_shape():area(0),length(0){}
	virtual ~cp_shape(){}
};
#endif