#include <iostream>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

template <typename T> T test(T *star, bool (*param)(int,bool (*)(int )) ,bool (*param2)(int)) {
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

bool def(int i,bool def2(int )){
    return i < 20 && def2(i);
}

bool def2(int i){
    return i <= 11;
}

std::string str(std::string star, std::string end, bool (*param)(int ,bool (*)(int )), bool (*param2)(int )){
    std::string result = "";
    for (int i = star.size(); i < end.size(); i++) {
        if (param(i,param2)){
            result += "1 ";
        }
    }
    return result;
}

int main() {
    auto deff = [](int i,bool (*)(int )) -> bool {return i == 10 && def2(i);};
    std::cout << "Hello, World!" << str("0","12222220", deff,def2) <<std::endl;
    int sss[] = {1,2,3,4,5,6,7,8,9,10,11};
    printf("测试：%d\n", test<int>(sss,deff,def2));

    auto in = [](int i) -> int {
        return i * 20;
    };

    auto in2 = [](int i) -> int {
        return i * 30;
    };

    auto tm1 = [](int i) -> int {
        sleep_for(milliseconds (5000));
        printf("线程打印%d---",i);
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





