#include <iostream>
#include <thread>
#include "hpp/method_pointer.h"
#include "hpp/grammar_test.h"
#include "hpp/locality_pointer.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace pointer;
using namespace grammar;

int main() {
    //方法指针传递测试
    method_pointer_test();

    thread t1 = thread_test();

    auto_test();

    t1.join();

    int *i = f1();
    printf("f1:%d\n",*i);
    printf("f1:%s\n",*f2());
    free(i);

    int *i2 = f3<int>();
    *i2 = 1234314213;
    string str = voidToString<int>(*i2);
    printf("int转String:%s;\n",str.c_str());

    int i3 = stringToVoid<int>("2321431");
    printf("string转int:%d\n",i3);

    bool b1 = stringToVoid<bool>("false");
    printf("string转bool:%s\n",b1?"真":"假");

    auto d1 = stringToVoid<double>("3.1415962");
    printf("string转double:%e\n",d1);

    return 0;
}





