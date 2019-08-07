//
// Created by zhsy on 19-8-1.
//

#include <iostream>

class Singleton{
public:
    static Singleton& instance(){
        return singleton;
    }
    int CallFunc(){
        std::cout<<"Singleton::CallFunc"<<std::endl;
        return 0;
    }
private:
    static Singleton singleton;
    Singleton(){
        std::cout<<"Singleton::construct"<<std::endl;
    }
    ~Singleton(){
        std::cout<<"Singleton::deconstruct"<<std::endl;
    }
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

};

//类外定义
Singleton Singleton::singleton;

int main(){

    Singleton& singleton=Singleton::instance();
    singleton.CallFunc();
    return 0;
}