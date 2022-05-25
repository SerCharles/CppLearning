#ifndef CP_INTEGER_H
#define CP_INTEGER_H

//extern int integer_input();
class cp_integer
{
  public: 
	  int num;
  public:
	  cp_integer(){ num = 0; }
      ~cp_integer(){}
  public:
	  void integer_input();
	  void integer_output();
};


#endif