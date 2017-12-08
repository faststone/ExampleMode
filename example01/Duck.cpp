#include "Duck.h"

Duck::Duck(FlyBehavior *fb)
    : m_fb(fb)
{

}

void Duck::setFlyBehavior(FlyBehavior *fb)
{
    m_fb = fb;
}

void Duck::performFly()
{
    m_fb->fly();
}

RedDuck::RedDuck(FlyBehavior *fb)
    : Duck(fb)
{

}

GreenDuck::GreenDuck(FlyBehavior *fb)
    : Duck(fb)
{

}

BlueDuck::BlueDuck(FlyBehavior *fb)
    : Duck(fb)
{

}

