//
// Created by zhsy on 19-8-26.
//
#include <iostream>

/**
 * 外观模式
 * 将子系统进行进一步封装，以统一接口展现给用户，隐藏系统的复杂性
 *
 * 优点：
 * 1. 使客户端代码变得简单
 * 2. 便于升级，不需要修改客户端
 * 3. 降低编译依赖性
 *
 * 缺点：
 * 1. 增加新的子系统要修改外观类，不满足开闭原则
 *
 * 使用场景：
 * 1. 为复杂的模块或子系统提供外界访问的接口
 * 2. 子系统相对独立
 *
 * 应用实例
 * 自动化流水线，工人只需要操控按钮提供需求，剩下的所有工作交给系统
 */

#include <外观模式/SystemA.h>
#include <外观模式/SystemB.h>
#include <外观模式/SystemC.h>

class Facade{
public:
    Facade(){
        systemA=new SystemA();
        systemB=new SystemB();
        systemC=new SystemC();
    }
    virtual ~Facade(){
        delete systemA;
        delete systemB;
        delete systemC;
    }
    void wrapOperation(){
        systemA->operationA();
        systemB->operationB();
        systemC->operationC();
    }
private:
    SystemA *systemA;
    SystemB *systemB;
    SystemC *systemC;
};


int main(){
    Facade fa;
    fa.wrapOperation();
    return 0;
}

