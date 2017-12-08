/*策略模式*/

#include <stdio.h>
#include "FlyBehavior.h"
#include "Duck.h"

int main(){
    FlyBehavior *pfWings = new FlyWithWings;
    FlyBehavior *pfNo = new FlyNoWay;
    FlyBehavior *pfRocket = new FlyWithRocket;

    Duck *pDuck = new RedDuck(pfWings);
    pDuck->performFly();

    pDuck->setFlyBehavior(pfNo);
    pDuck->performFly();

    pDuck->setFlyBehavior(pfRocket);
    pDuck->performFly();
    return 0;
}
