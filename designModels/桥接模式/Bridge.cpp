//
// Created by zhsy on 19-8-26.
//
#include <iostream>
#include <string>
using namespace std;
/**
 * 桥接模式
 * 两个维度或多个维度，将多个维度抽象串接起来
 *
 * 看一个例子：
 * 假设饭店评价和两个维度相关：饭店类型+城市类型
 * 那么我们可以像下面这样设计
 *
 *
 * 参考：
 * blog.csdn.net/u013256816/article/details/51000327
 */

class Restaurant{
public:
    Restaurant(){}
    virtual ~Restaurant(){}
    virtual string taste()=0;
};

class XiaoNanGuo:public Restaurant{
public:
    XiaoNanGuo(){};
    virtual ~XiaoNanGuo(){};
    virtual string taste(){
        return "小南国-口味普遍很好";
    }
};
class WaiPoJia:public Restaurant{
public:
    WaiPoJia(){}
    virtual ~WaiPoJia(){}
    virtual string taste(){
        return "外婆家-口味一般";
    }
};

class City{
public:
    City(Restaurant* restaurant):_restaurant(restaurant){

    }
    virtual ~City(){}
    virtual string commentTaste()=0;

protected:
    Restaurant *_restaurant;
};

class QingDao:public City{
public:
    QingDao(Restaurant* restaurant):City(restaurant){

    }
    virtual ~QingDao(){

    }
    virtual string commentTaste(){
        cout<<"青岛的"+_restaurant->taste()<<endl;
    }
};

class JiNan:public City{
public:
    JiNan(Restaurant* restaurant):City(restaurant){

    }
    virtual ~JiNan(){

    }
    virtual string commentTaste(){
        cout<<"济南的"+_restaurant->taste()<<endl;
    }
};


int main(){
    Restaurant* waipojia=new WaiPoJia();
    City *jinan=new JiNan(waipojia);
    jinan->commentTaste();
}