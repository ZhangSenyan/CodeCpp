//
// Created by zhsy on 19-8-9.
//
#include <iostream>
using namespace std;
/*
 * 抽象工厂模式：
 *
 * 现在需要做一款跨平台的游戏，需要兼容Android，Ios，Wp三个移动操作系统，该游戏针对每个系统都设计了一套操作控制器
 * （OperationController）和界面控制器（UIController），下面通过抽闲工厂方式完成这款游戏的架构设计。
 *
 * 由题可知，游戏里边的各个平台的UIController和OperationController应该是我们最终生产的具体产品。
 * 所以新建两个抽象产品接口。
 */


// 抽象操作控制器
class OperationController {
public:
    virtual void control()=0;
};

// 抽象界面控制器
class UIController {
public:
    virtual void display()=0;
};

// 然后完成各个系统平台的具体操作控制器和界面控制器
// Android
class AndroidOperationController: public OperationController {
public:
    void control(){
        cout<<"AndroidOperationController"<<endl;
    }
};
class AndroidUIController: public UIController {
public:
    void display(){
        cout<<"AndroidInterfaceController"<<endl;
    }
};

// IOS
class IOSOperationController: public OperationController {
public:
    void control(){
        cout<<"IOSOperationController"<<endl;
    }
};
class IOSUIController: public UIController {
public:
    void display(){
        cout<<"IOSInterfaceController"<<endl;
    }
};



//Wp
class WpOperationController: public OperationController {
public:
    void control(){
        cout<<"WpOperationController"<<endl;
    }
};
class WpUIController: public UIController {
public:
    void display(){
        cout<<"WpInterfaceController"<<endl;
    }
};



//下面定义一个抽闲工厂，该工厂需要可以创建OperationController和UIController

class SystemFactory{
public:
    virtual OperationController* createOperationController()=0;
    virtual UIController* createInterfaceController()=0;
};

//在各平台具体的工厂类中完成操作控制器和界面控制器的创建过程
// Android
class AndroidFactory: public SystemFactory{
public:
    OperationController* createOperationController(){
        return new AndroidOperationController();
    }
    UIController* createInterfaceController(){
        return new AndroidUIController();
    }
};

// IOS
class IOSFactory: public SystemFactory{
public:
    OperationController* createOperationController(){
        return new IOSOperationController();
    }
    UIController* createInterfaceController(){
        return new IOSUIController();
    }
};

// Wp
class WpFactory: public SystemFactory{
public:
    OperationController* createOperationController(){
        return new WpOperationController();
    }
    UIController* createInterfaceController(){
        return new WpUIController();
    }
};

//客户端调用
int main(){
    SystemFactory *systemFactory;
    UIController *uiController;
    OperationController *operationController;

    systemFactory=new AndroidFactory();

    //systemFactory=new IOSFactory();
    //systemFactory=new WpFactory();

    uiController=systemFactory->createInterfaceController();
    operationController=systemFactory->createOperationController();
    uiController->display();
    operationController->control();
}





















