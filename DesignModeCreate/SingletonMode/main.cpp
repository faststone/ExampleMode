/*************
***单例模式****
*************/

#include <iostream>

using namespace std;


class Singleton
{
private :
    Singleton(){}
    static Singleton* m_instance;
public:
    static Singleton* instance(){
        if(m_instance = NULL){
            m_instance = new Singleton();
        }
        return m_instance;
    }
};

Singleton* Singleton::m_instance = NULL;

int main(int argc, char *argv[])
{
    Singleton *s1 = Singleton::instance();
    Singleton *s2 = Singleton::instance();
    return 0;
}
