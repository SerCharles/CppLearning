#ifndef NUMBER_H
#define NUMBER_H

class numbers
{
    public:
    int num_a,num_b;
    int min_multiply,max_divide;
    public:
  numbers(){num_a=1;num_b=1;}
  ~numbers(){}
    public:
    int get_max_divide();
    int get_min_multiply();
    
};



#endif
