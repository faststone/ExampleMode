#include "Factory.h"

Factory * Factory::m_instance = 0;
std::map<std::string, Data * (*)()> Factory::g_map;

Factory::Factory()
    : m_index(0)
{

}

void Factory::registerType(char *type, Data *(*func)())
{
    g_map.insert(std::make_pair(type,func));
    std::cout<<"type="<<type<<std::endl;
}

Factory *Factory::instance()
{
    if (m_instance == 0){
        m_instance = new Factory();
    }
    return m_instance;
}

Data *Factory::create(char * typeName)
{
    std::cout<<"typeName="<<typeName<<std::endl;
    Data* p = NULL;
    std::map<std::string,Data * (*) ()>::iterator it = g_map.find(std::string(typeName));
    if(it != g_map.end()){
        p = (it->second)();
        char temp[8] = {0};
        m_data.insert(std::make_pair(std::string(typeName) + std::string(itoa(++m_index, temp, 10)), p));
        return p;
    }
    return 0;
}
