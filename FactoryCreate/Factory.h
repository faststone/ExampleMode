#ifndef FACTORY_H
#define FACTORY_H
#include <map>
#include <string>
#include <iostream>
#include "data.h"

#define DYN_CREATE_DECL(TYPE)	\
public:												\
    static Data * create(){ return new TYPE(); }	\
class TYPE##REGISTER {								\
public:												\
    TYPE##REGISTER(){								\
    Factory::registerType(#TYPE, TYPE::create);		\
}													\
};
#define DYN_CREATE_IMPL(TYPE) TYPE::TYPE##REGISTER TYPE##REGISTERINSTANCE;

class Factory
{
public:
    Factory();
    static void registerType(char * type, Data * (*func)());
    static Factory* instance();
    Data* create(char * typeName);
private:
    static std::map<std::string,Data * (*) ()> g_map;
    static Factory * m_instance;
    std::map<std::string,Data*> m_data;
    int m_index;
};

#endif // FACTORY_H
