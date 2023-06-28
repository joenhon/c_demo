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
    free(i);

    return 0;
}





