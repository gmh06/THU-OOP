#pragma once
#include <iostream>

class Vehicle
{
    int max_wheel_num;
    int max_wing_num;
    int wheel_n = 0;
    int wing_n = 0;

    public:
        void set_max_wheel_num(int n) { max_wheel_num = n; }
        void set_max_wing_num(int n) { max_wing_num = n; }
        // 对于单个个体，有可能超装，此时超装对于finished()的判定就是 '>=' 逻辑
        // as the number of wheels and wings can be more than the maximum, the finished() function should use '>=' logic to determine if the vehicle is finished.
        bool finished() { return wheel_n >= max_wheel_num && wing_n >= max_wing_num; }
        void add_wheel() { wheel_n ++; }
        void add_wing() { wing_n ++; }
        void run() { std::cout << "I am running" << std::endl; }
};