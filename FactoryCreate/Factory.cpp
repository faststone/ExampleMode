#include "Factory.h"

Factory * Factory::m_instance = NULL;
std::map<std::string, Data * (*)()> *Factory::g_map = NULL;

Factory::Factory()
    : m_index(0)
{

}

void Factory::registerType(char *type, Data *(*func)())
{
    if(g_map == NULL){
        g_map = new std::map<std::string,Data * (*) ()>;
    }
    (*g_map).insert(std::make_pair(type,func));
}

Factory *Factory::instance()
{
    if (m_instance == NULL){
        m_instance = new Factory();
    }
    return m_instance;
}

Data *Factory::create(char * typeName)
{
    Data* p = NULL;
    std::map<std::string,Data * (*) ()>::iterator it = (*g_map).find(std::string(typeName));
    if(it != (*g_map).end()){
        p = (it->second)();
        char temp[8] = {0};
        m_data.insert(std::make_pair(std::string(typeName) + std::string(itoa(++m_index, temp, 10)), p));
        return p;
    }
    return 0;
}
