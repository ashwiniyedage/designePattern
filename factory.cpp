#include<iostream>
using namespace std;

class Car{
    public:
    virtual void getDescription()=0;
    virtual ~Car()
    {
        cout<<"Destroyed"<<endl;
    }
};
class BMW : public Car{
    public:
    void getDescription()
    {
        cout<<"This is BMW"<<endl;
    }
};
class SUV : public Car{
    public:
    void getDescription()
    {
        cout<<"This is SUV"<<endl;
    }
};
class Sports : public Car{
    public:
    void getDescription()
    {
        cout<<"This is Sports"<<endl;
    }
};
class Carfactory
{
    public:
    static Car* createCar(const string& carType)
    {
        if(carType == "bmw")
        {
            return new BMW();
        }
        else if(carType == "suv")
        {
            return new SUV();
        }
        else if(carType == "sports")
        {
            return new Sports();
        }
        else{
            cout<<"Invalid cartyepe"<<endl;
            return nullptr;
        }
    }
};
int main()
{
    string cartype;
    cin>>cartype;

    Car *car = Carfactory::createCar(cartype);
    if(car)
    {
        car->getDescription();
        delete car;
    }
}