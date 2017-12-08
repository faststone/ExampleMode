/*************
**简单工厂模式**
*************/
#include <iostream>

using namespace std;

class COperation
{
public:
    virtual double GetResult() = 0;
    void setFirst(int nFirst){
        m_nFirst = nFirst;
    }
    void setSecond(int nSecond){
        m_nSecond = nSecond;
    }
    int getFirst(){
        return m_nFirst;
    }
    int getSecond(){
        return m_nSecond;
    }
private:
    int m_nFirst;
    int m_nSecond;
};

//加法
class AddOperation : public COperation
{
public:
    double GetResult()
    {
        return getFirst() + getSecond();
    }
};

//减法
class SubOperation : public COperation
{
public:
    double GetResult()
    {
        return getFirst() - getSecond();
    }
};

class CCalculatorFactory : public COperation
{
public:
    static COperation* create(char cOperate);
    double GetResult(){}
};

COperation* CCalculatorFactory::create(char cOperate)
{
    COperation* operate;
    switch(cOperate){
        case '+' :
            operate = new AddOperation();
            break;
        case '-':
            operate = new SubOperation();
             break;
        default:
            operate = NULL;
    }
    return operate;
}
int main(int argc, char *argv[])
{
    int a = 10 , b = 20;
    COperation * op = CCalculatorFactory::create('-');
    op->setFirst(a);
    op->setSecond(b);
    cout << "GetResult = "<< op->GetResult();
    return 0;
}
