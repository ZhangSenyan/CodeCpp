//
// Created by zhsy on 19-8-26.
//

/**
 * 观察者模式 - 订阅发布模式
 * 被观察者中有一个观察者集合，一旦发生事件，便通知所有的观察者
 *
 * 优点：
 * 1. 观察者与被观察者是抽象耦合的
 *
 * 缺点：
 * 1. 观察者太多的时候，通知所有的观察者会比较耗费时间
 * 2. 观察者与被观察者之间循环依赖的问题
 *
 */
#include <string>
#include <iostream>
#include <set>
using namespace std;

//抽象观察者
class Observer {
public:
    Observer(){};
    virtual ~Observer(){};
    virtual void update(string msg)=0;
};

//抽象被观察者
class Subject{
public:
    Subject(){

    }
    virtual void attach(Observer* observer)=0;
    virtual void detach(Observer* observer)=0;
    virtual void notify(string msg)=0;
    virtual ~Subject(){};
};

//具体观察者
class WeixinUser:public Observer{
public:
    WeixinUser(string name):_name(name){

    }
    virtual ~WeixinUser(){

    }
    virtual void update(string msg){
        cout<<_name<<"+"<<msg<<endl;
    }
private:
    string _name;
};

class BroadCast:public Subject{
public:
    BroadCast(string channelName):_channelName(channelName),observers(){

    }
    virtual ~BroadCast(){}
    virtual void attach(Observer* observer){
        observers.insert(observer);
    }
    virtual void detach(Observer* observer){
        observers.erase(observer);
    }
    virtual void notify(string msg){
        for(auto & observer:observers){
            observer->update(msg+"from "+_channelName);
        }
    }
private:
    string _channelName;
    set<Observer*> observers;
};

int main(){
    Subject* mCCTV=new BroadCast("CCTV");

    Observer* user1=new WeixinUser("Wang");
    Observer* user2=new WeixinUser("Li");
    Observer* user3=new WeixinUser("Zhang");

    mCCTV->attach(user1);
    mCCTV->attach(user2);
    mCCTV->attach(user3);

    mCCTV->notify("Good Morning!");
}








