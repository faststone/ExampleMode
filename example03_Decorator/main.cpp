#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Tank
{
public:
    virtual void shot() = 0;
    virtual void run()  = 0;
public:
    virtual ~Tank(){
        cout<<"in the destructor of Tank"<<endl;
    }
};

class T50 :public Tank
{
public:
    void shot()
    {
        cout<<"Tank T50 shot()"<<endl;
    }
    void run()
    {
        cout<<"Tank T50 run()"<<endl;
    }
public:
    virtual ~T50()
    {
        cout<<"In the destructor of T50"<<endl;
    }
};

class T75 : public Tank
{
public:
    void shot()
    {
        cout<<"Tank T75 shot()"<<endl;
    }
    void run()
    {
        cout<<"Tank T75 run()"<<endl;
    }
public:
    virtual ~T75()
    {
        cout<<"In the destructor of T75"<<endl;
    }
};

//Decorator
class Decorator : public Tank
{
protected:
    Tank* tank;
public:
    Decorator(Tank* tank):tank(tank)
    {

    }
    virtual ~Decorator()
    {
      cout<<"In the destructor of Decorator"<<endl;
    }
private:
    void shot()
    {
        tank->shot();
    }
    void run()
    {
        tank->run();
    }
};

class InfraredDecorator : public Decorator
{
public:
    InfraredDecorator(Tank* tank): Decorator(tank)
    {

    }
    virtual ~InfraredDecorator()
    {
        cout<<"in the destructor of InfraredDecorator"<<endl;
    }
public:
    void setInfrared(const string& infrared)
    {
        m_infrared = infrared;
    }
    string getInfrared() const
    {
        return m_infrared;
    }
    void run()
    {
        tank->run();
        setInfrared("+Infrared");
        cout<<getInfrared()<<endl;
    }
    void shot()
    {
        tank->shot();
    }
private:
    string m_infrared;//这就是所谓的添加属性
};

class AmphibianDecorator:public Decorator
{
public:
    AmphibianDecorator(Tank* tank):Decorator(tank) {}
    ~AmphibianDecorator()
    {
        cout<<"in the destructor of AmphibianDecorator"<<endl;
    }
public:
    void setAmphibian(const string &hibian)
    {
        this->m_amphibian=hibian;
    }
    string getAmphibian() const
    {
        return m_amphibian;
    }
public:
    void run()
    {
        tank->run();
        setAmphibian("+amphibian");
        cout<<getAmphibian()<<endl;
    }
    void shot()
    {
        tank->shot();
    }
private:
    string m_amphibian;
};

int main()
{
    Tank* tank1 = new T50();
    tank1->run();
    tank1->shot();
    Tank* tank2 = new InfraredDecorator(tank1);
    tank2->run();
    tank2->shot();
    Tank* tank3 = new AmphibianDecorator(tank2);
    tank3->run();
    tank3->shot();
    return 0;
}
