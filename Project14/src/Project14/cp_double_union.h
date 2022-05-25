#ifndef CP_DOUBLE_UNION_H
#define CP_DOUBLE_UNION_H
union double_and_int
{
	double decimal;
	unsigned long long int equal_decimal;
};
class cp_double_union
{
public:
	double_and_int num;
	cp_double_union() {num.equal_decimal = 0; }
	~cp_double_union(){}
	bool input_double();
	void main_section();
	void get_binary(int mode);
	void get_binary();
	void regain_double(bool binary[]);
};
#endif