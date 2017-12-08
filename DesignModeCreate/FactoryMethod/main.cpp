/*************
**多态工厂模式**
*************/
#include <iostream>

using namespace std;

class Factory{
public :
    virtual void product(){
        cout<<"class Factory"<<endl;
    }
};

class FactoryA : public Factory{
public :
    virtual void product(){
        cout<<"class FactoryA"<<endl;
    }

};
class FactoryB : public Factory{
public :
    virtual void product(){
        cout<<"class FactoryB"<<endl;
    }
};

//基类
class CreativeFactory {
public:
    virtual Factory* CreateFactory(){
        return new Factory();
    }
};

class StudentA :public CreativeFactory{
public:
    virtual Factory* CreateFactory(){
        return new FactoryA();
    }
};

class StudentB :public CreativeFactory{
public:
    virtual Factory* CreateFactory(){
        return new FactoryB();
    }
};

int main(int argc, char *argv[])
{
    CreativeFactory* cf = new StudentB();
    Factory *fc = cf->CreateFactory();
    fc->product();
    cout << "Hello World!" << endl;
    return 0;
}
