#include <string>
#include <iostream>
#include <vector>
using namespace std;

class IUser{
public:
    virtual void GetUser() = 0;
    virtual void InsertUser() = 0;
};

class IDepartment{
public:
    virtual void GetDepartment() = 0;
    virtual void InsertDepartment() = 0;
};

class CAcessUser : public IUser{
public :
    virtual void GetUser()
    {
        cout<<"Access GetUser"<<endl;
    }
    virtual void InsertUser()
    {
        cout<<"Access InsertUser"<<endl;
    }
};

class CSqlUser: public IUser{
public :
    virtual void GetUser()
    {
        cout<<"Sql User"<<endl;
    }
    virtual void InsertUser()
    {
        cout<<"Sql User"<<endl;
    }
};


class CAccessDepartment : public IDepartment{
public :
    virtual void GetDepartment()
    {
        cout<<"Access GetDepartment"<<endl;
    }
    virtual void InsertDepartment()
    {
        cout<<"Access InsertDepartment"<<endl;
    }
};

class CSqlDepartment : public IDepartment{
public :
    virtual void GetDepartment()
    {
        cout<<"sql getDepartment"<<endl;
    }
    virtual void InsertDepartment()
    {
        cout<<"sql insertdepartment"<<endl;
    }
};

class IFactory{
public:
    virtual IUser*       CreateUser() = 0;
    virtual IDepartment* CreateDepartment() = 0;
};

class AcessFactory : public IFactory{
public :
    virtual IUser* CreateUser(){
        return new CAcessUser();
    }
    virtual IDepartment* CreateDepartment(){
        return new CAccessDepartment();
    }
};

class SqlFactory : public IFactory{
public :
    virtual IUser* CreateUser(){
        return new CSqlUser();
    }
    virtual IDepartment* CreateDepartment(){
        return new CSqlDepartment();
    }
};
int main(int argc, char *argv[])
{
    IFactory* factory = new SqlFactory();
    IUser* user = factory->CreateUser();
    IDepartment* depart = factory->CreateDepartment();
    user->GetUser();
    depart->GetDepartment();
    return 0;
}
