//
// Created by zhsy on 19-8-1.
//
#include <string>
#include <iostream>
//统一的接口
class Image{
public:
    Image(std::string path):_path(path){

    }
    virtual void show(){}
    virtual ~Image(){}

protected:
    std::string _path;
};

//代理工厂
class ImageShow: public Image{
public:
    ImageShow(std::string path):Image(path){};
    void show() override {
        std::cout<<"ImageShow: path="<<_path<<std::endl;
    }
    ~ImageShow(){};
};

//雇主
class ImageProxy:public Image{
private:
    ImageShow* imageShow;
public:
    ImageProxy(std::string path):Image(path),imageShow(nullptr){

    }
    ~ImageProxy(){
        if(imageShow)
            delete imageShow;
    }
    void show() override {
        if(imageShow==nullptr){
            imageShow=new ImageShow(_path);
        }
        imageShow->show();
    }
};
int main(){
    //Image* image = new ImageProxy("local image path");
    //image->show();
    ImageProxy imageProxy("local image path");
    imageProxy.show();
    return 0;
}