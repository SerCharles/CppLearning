#ifndef CP_COMPLEX_H
#define CP_COMPLEX_H

class cp_complex
{
private:
	double real, imaginary;

public:
	cp_complex() :real(0), imaginary(0) {}
	virtual ~cp_complex() {}
	
	cp_complex operator ++ (); //前++
	cp_complex operator -- (); //后++
	cp_complex operator ++ (int); //后++
	cp_complex operator -- (int);//后--
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