//
// Created by zhsy on 19-8-1.
//

#include <folly/AtomicHashMap.h>
#include <thread>
#include <vector>

int main(){
    folly::AtomicHashMap<int64_t ,int64_t > ahm(100);

    ahm.insert(0,0);
    int threadNums=10;

    std::vector<std::thread*> threadPool;
    for(int i=0;i<threadNums;i++){
        threadPool.push_back(new std::thread([&ahm](){
            auto ret=ahm.find(0);
        }));
    }

}