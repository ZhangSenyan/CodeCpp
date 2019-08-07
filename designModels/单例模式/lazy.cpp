//
// Created by zhsy on 19-8-1.
//
#include <iostream>
#include <mutex>
class Singleton{
public:
    static Singleton* Instance(){
        //双重检查模式
        if(!instance){
            std::lock_guard<std::mutex> lockGuard(_mutex);
            if(!instance){
                instance=new Singleton();
            }
        }
        return instance;
    }
    int CallFunc(){
        std::cout<<"Singleton::CallFunc"<<std::endl;
        return 0;
    }
private:
    static Singleton* instance;
    static std::mutex _mutex;
    Singleton(){
        std::cout<<"Singleton::construct"<<std::endl;
    }
    ~Singleton(){
        std::cout<<"Singleton::deconstruct"<<std::endl;
    }
    Singleton(Singleton const&)= delete;
    Singleton& operator=(Singleton const &)= delete;
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::_mutex;

int main(){
    Singleton* singleton=Singleton::Instance();
    singleton->CallFunc();
    return 0;
}