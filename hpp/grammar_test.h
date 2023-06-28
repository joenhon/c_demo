//
// Created by xuniji on 2023/6/28.
//

#ifndef UNTITLED3_GRAMMAR_TEST_H
#define UNTITLED3_GRAMMAR_TEST_H
#include <iostream>
#include <thread>
#include <sstream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

namespace grammar{
    //线程测试 （C++11标准库）
    static thread thread_test(){
        auto tm1 = [](int i) -> int {
            sleep_for(milliseconds (1000));
            printf("线程打印%d---\n",i);
            sleep_for(milliseconds (1000));
            return 0;
        };
        thread t1(tm1,2);
        return t1;
    }

    //String转任意类型
    template<typename T> T stringToVoid(const char *str){
        T result;
        istringstream is(str);
        is >> result;
        return result;
    }

    //任意类型转String
    template<typename T> string voidToString(T void_){
        ostringstream os;
        os<<void_;
        return os.str();
    }
}

#endif //UNTITLED3_GRAMMAR_TEST_H
