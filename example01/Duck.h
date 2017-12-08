#ifndef DUCK_H
#define DUCK_H
#include "FlyBehavior.h"
#include<iostream>
#include <QPointer>
class Duck
{
public:
    Duck(FlyBehavior* fb);
    void performFly();
    void setFlyBehavior(FlyBehavior *fb);
    FlyBehavior* m_fb;
private:

};

class RedDuck : public Duck{

public:
    RedDuck(FlyBehavior *fb);
};

class GreenDuck  : public Duck{

public:
    GreenDuck(FlyBehavior *fb);
    void run();
};

class BlueDuck  : public Duck{

public:
    BlueDuck(FlyBehavior *fb);
    void run();
};

#endif // DUCK_H
