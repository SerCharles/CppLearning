#ifndef CP_COMPLEX_H
#define CP_COMPLEX_H

class cp_complex
{
private:
	double real, imaginary;

public:
	cp_complex() :real(0), imaginary(0) {}
	virtual ~cp_complex() {}
	
	cp_complex operator ++ (); //ǰ++
	cp_complex operator -- (); //��++
	cp_complex operator ++ (int); //��++
	cp_complex operator -- (int);//��--
	friend cp_complex operator + (cp_complex a, cp_complex b);
	friend cp_complex operator - (cp_complex a, cp_complex b);
	friend cp_complex operator * (cp_complex a, cp_complex b);
	friend cp_complex operator / (cp_complex a, cp_complex b);
	void set_value(double a, double b);
	void output_file();
	void output_windows(char a[]);
	void get_value(double* a, double* b);
};
extern cp_complex operator + (cp_complex a, cp_complex b);
extern cp_complex operator - (cp_complex a, cp_complex b);
extern cp_complex operator * (cp_complex a, cp_complex b);
extern cp_complex operator / (cp_complex a, cp_complex b);



#endif