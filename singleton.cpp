#include <iostream>
#include<mutex>
using namespace std;

//mutex m;
class Singleton{
    private:
    static Singleton* ptr;
    //static mutex m;

    Singleton(){}
    Singleton(const Singleton& obj)=delete;
    Singleton& operator=(const Singleton& obj)=delete;

    public:
    static Singleton* getInstance()
    {
        if(ptr == nullptr)
        {
            //lock_guard<std::mutex> lock(m);
            if(ptr == nullptr)
            {
                ptr = new Singleton();
            }
        }
        return ptr;
    }
    ~Singleton()
    {
        delete ptr;
        cout<<"Destructor"<<endl;
    }

};
Singleton* Singleton :: ptr = nullptr;
//mutex Singleton::m;

int main()
{
    Singleton* ptr1 = Singleton::getInstance();
    cout<<"ptr1 : "<<ptr1<<endl;

    Singleton* ptr2 = Singleton::getInstance();
    cout<<"ptr2 : "<<ptr2<<endl;
}

