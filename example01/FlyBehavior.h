#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H


class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior{
    virtual void fly() override;
};

class FlyNoWay : public FlyBehavior{
    virtual void fly() override;
};

class FlyWithRocket : public FlyBehavior{
    virtual void fly() override;
};
#endif // FLYBEHAVIOR_H
