cmake_minimum_required(VERSION 3.14)
project(CodeCpp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(单例模式)
add_subdirectory(代理模式)
add_executable(Strategy 策略模式/Strategy.cpp)
add_executable(AbstractFactor 抽象工厂模式/AbstractFactory.cpp)