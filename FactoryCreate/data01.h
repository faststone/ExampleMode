#ifndef DATA01_H
#define DATA01_H
#include "data.h"
#include "Factory.h"

class Data01 : public Data
{
    DYN_CREATE_DECL(Data01)
public:
    Data01();
    ~Data01();
    virtual void test(){
        std::cout << "Data1" << std::endl;
    }
};

#endif // DATA01_H
