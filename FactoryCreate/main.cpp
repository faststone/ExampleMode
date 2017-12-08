#include <iostream>
#include "Factory.h"
using namespace std;

int main(int argc, char *argv[])
{
    Factory * factory = Factory::instance();
    Data * p1 = factory->create("Data1");
    p1->test();

    Data * p2 = factory->create("Data2");
    p2->test();
    cout << "Hello World!" << endl;
    return 0;
}
