#include <iostream>
#include <thread>
#include "hpp/method_pointer.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace pointer;

int main() {
    method_pointer pointer;
    auto def1 = [](int i,bool (*)(int )) -> bool {return i == 10 && def2(i);};
    std::cout << "Hello, World!" << pointer.str("0","12222220", def1,def2) <<std::endl;
    int sss[] = {1,2,3,4,5,6,7,8,9,10,11};
    printf("测试：%d\n", pointer.test<int>(sss,def1,def2));

    auto in = [](int i) -> int {
        return i * 20;
    };

    auto in2 = [](int i) -> int {
        return i * 30;
    };

    auto tm1 = [](int i) -> int {
        sleep_for(milliseconds (5000));
        printf("线程打印%d---\n",i);
        sleep_for(milliseconds (1000));
        return 0;
    };

    thread t1(tm1,2);

    int (*ss[])(int i){in,in2};

    for (int (*s1)(int i):ss){
        printf("方法数组测试：%d\n",(*s1)(12));
    }

    t1.join();

    return 0;
}





