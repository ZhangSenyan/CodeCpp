//
// Created by zhsy on 19-8-6.
//


/*************************************************************************************
 * 策略模式
 *
 * 以负载均衡为例，定义一个类LoadBalance专门完成负载均衡的工作，
 * 但是Dispatch的方式有很多中，以后还可能会研究出新的方法，所以为了满足扩展性
 * 我们定义一个Dispatch策略的抽象接口，然后我们在LoadBalance直接调用抽象的接口
 * 以后如果有了新的策略，我们按照接口标准制作，然后安装到LoadBalance中即可
 *
 *************************************************************************************/
#include <iostream>

class DispatchPolicy{
public:
    DispatchPolicy(){}
    virtual ~DispatchPolicy(){}
    virtual void dispatch()=0;
};

class LoadBalance{
public:
    LoadBalance(DispatchPolicy* dispatchPolicy):_dispatchPolicy(dispatchPolicy){}

    void loadDispatch(){
        _dispatchPolicy->dispatch();
    }

private:
    DispatchPolicy* _dispatchPolicy;
};

class RandomDispatch:public DispatchPolicy{
public:
    RandomDispatch(){}
    virtual ~RandomDispatch(){}
    virtual void dispatch(){
        std::cout<<"RandomDispatch"<<std::endl;
    }
};

class RoundRobin:public DispatchPolicy{
public:
    RoundRobin(){}
    virtual ~RoundRobin(){}
    virtual void dispatch(){
        std::cout<<"RoundRobin"<<std::endl;
    }
};

int main(){

    DispatchPolicy * dispatchPolicy=new RoundRobin();
    LoadBalance loadBalance(dispatchPolicy);
    
    loadBalance.loadDispatch();
    
}









