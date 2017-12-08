#include <stdio.h>

class Base{
public:
    Base(){
    }
    virtual ~Base(){
    }
    virtual void DoSomething() {
        printf("Do something in class ClxDerived!\n");
    }
};

class someThing01 : public Base{
public:
    someThing01(){}
    ~someThing01(){
        printf(" ~someThing01() Undo something in class ClxDerived!\n");
    }
    void DoSomething() {
        printf("Do something in class ClxDerived! \n");
    }
};

int main(){
    Base * be = new someThing01();
    be->DoSomething();
    delete be;
    return 0;
}
