//
// Created by xuniji on 2023/6/26.
//

#ifndef UNTITLED3_METHOD_POINTER_H

#define UNTITLED3_METHOD_POINTER_H

#include <iostream>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class method_pointer{
public:
    method_pointer();
    ~method_pointer();

    template<typename T> T test(T *star, bool (*param)(int, bool (*)(int)), bool (*param2)(int)) {
        int i = 0;
        for (; *star; star++) {
            printf("第%d次运算\n", ++i);
            if (param(*star,param2)){
                return *star;
            }
            if (!param2(i)){
                return 0;
            }
        }
        return 0;
    }

    bool def(int i, bool def2(int));

    static bool def2(int i);

    std::string str(std::string star, std::string end, bool (*param)(int, bool (*)(int)), bool (*param2)(int));
};

namespace pointer{
    static bool def2(int i);
    //方法指针测试
    static int method_pointer_test(){
        method_pointer pointer;
        auto def1 = [](int i,bool (*)(int )) -> bool {return i == 10 && def2(i);};
        std::cout << "Hello, World!" << pointer.str("0","12222220", def1,def2) <<std::endl;
        int sss[] = {1,2,3,4,5,6,7,8,9,10,11};
        printf("测试：%d\n", pointer.test<int>(sss,def1,def2));
        return 0;
    }
    //函数指针测试
    static int auto_test(){

        auto in = [](int i) -> int {
            return i * 20;
        };

        auto in2 = [](int i) -> int {
            return i * 30;
        };
        int (*ss[])(int i){in,in2};

        for (int (*s1)(int i):ss){
            printf("方法数组测试：%d\n",(*s1)(12));
        }

        return 0;
    }
}
bool  pointer::def2(int i){
    return i <= 11;
}

#endif //UNTITLED3_METHOD_POINTER_H
