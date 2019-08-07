//
// Created by zhsy on 19-8-1.
//
#include <iostream>
#include <thread>
#include <mutex>

class Singleton{
public:
    static Singleton* Instance();
    int CallFunc(){
        std::cout<<"Singleton::CallFunc"<<std::endl;
        return 0;
    }

private:
    static Singleton* instance;

    Singleton(){
        std::cout<<"Singleton::construct"<<std::endl;
    }
    ~Singleton(){
        std::cout<<"Singleton::deconstruct"<<std::endl;
    }
    //Singleton(Singleton const&)= delete;
    //Singleton& operator=(Singleton const &)= delete;
};

Singleton* Singleton::instance = nullptr;


Singleton* Singleton::Instance(){
    static std::once_flag oc;
    std::call_once(oc,[&](){
        instance=new Singleton();
    });
    return instance;
}

int main(){
    Singleton* singleton=Singleton::Instance();
    singleton->CallFunc();
    return 0;
}




