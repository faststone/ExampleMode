#include <iostream>

using namespace std;

class Factory{
public :
    virtual void product() = 0;
};

class FactoryA : public Factory{
    void product(){}

};
class FactoryB : public Factory{
    void product(){}
};

class CreativeFactory : public Factory{
public:
    void product(){}
};

class StudentA :public CreativeFactory{
public:

};

class StudentB :public CreativeFactory{
public:

};



int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
