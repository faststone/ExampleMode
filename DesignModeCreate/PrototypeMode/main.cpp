/*************
***原型模式****
*************/

#include <iostream>

using namespace std;

class Prototype
{
public:
    Prototype(string strName){ m_strName = strName; }
    Prototype() { m_strName = " "; }
    void Show()
    {
        cout<<m_strName<<endl;
    }
    virtual Prototype* Clone() = 0;
private:
    string m_strName;
};

class ConcretePrototype1 : public Prototype
{
public:

    ConcretePrototype1(string strName) : Prototype(strName){}
    ConcretePrototype1(){}
    virtual Prototype* Clone()
    {
        ConcretePrototype1 *p = new ConcretePrototype1() ;
        *p = *this ;                         //复制对象
        return p ;
    }
};

class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2(string strName) : Prototype(strName){}
    ConcretePrototype2(){}

    virtual Prototype* Clone()
    {
        ConcretePrototype2 *p = new ConcretePrototype2() ;
        *p = *this ; //复制对象
        return p ;
    }
} ;

int main(int argc, char *argv[])
{
    ConcretePrototype1* test = new ConcretePrototype1("hello");
    ConcretePrototype2* test2 = (ConcretePrototype2*)test->Clone();
    test->Show();
    test2->Show();
    return 0;
}
