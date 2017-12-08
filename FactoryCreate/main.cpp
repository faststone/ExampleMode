#include <iostream>
#include "Factory.h"
#include "data01.h"
using namespace std;


int main(int argc, char *argv[])
{
    Factory * factory = Factory::instance();
    Data * p1 = factory->create("Data01");
    p1->test();
    cout << "Hello World!" << endl;
    return 0;
}
