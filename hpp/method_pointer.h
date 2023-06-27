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

namespace pointer{
    static bool def2(int i);
}
bool  pointer::def2(int i){
    return i <= 11;
}

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


#endif //UNTITLED3_METHOD_POINTER_H
