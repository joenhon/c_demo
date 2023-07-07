#include <iostream>
#include <thread>
#include <fstream>
#include "method_pointer.h"
#include "grammar_test.h"
#include "locality_pointer.h"
#include "file_test.h"
#include "net_test.h"

#ifdef  WIN32
#pragma comment(lib,"wsock32.lib")
#endif

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace pointer;
using namespace grammar;
using namespace file;
using namespace net;

int main() {
#ifdef  WIN32
    system("chcp 65001");
#endif

//    //方法指针传递测试
//    method_pointer_test();
//
//    thread t1 = thread_test();
//
//    auto_test();
//
//    t1.join();
//
//    int *i = f1();
//    printf("f1:%d\n",*i);
//    printf("f2:%s\n",*f2());
//    free(i);
//
//    int *i2 = f3<int>();
//    *i2 = 1234314213;
//    string str = voidToString<int>(*i2);
//    printf("int转String:%s;\n",str.c_str());
//
//    int i3 = stringToVoid<int>("2321431");
//    printf("string转int:%d\n",i3);
//
//    bool b1 = stringToVoid<bool>("false");
//    printf("string转bool:%s\n",b1?"真":"假");
//
//    auto d1 = stringToVoid<double>("3.1415962");
//    printf("string转double:%e\n",d1);

//    printf("文件：%s\n",readFile("C:/test.log"));

//    write("E:/test.txt","2");
//    string str;
//    readFile("/root/test.txt",str);
//    printf("文件：%s\n",str.c_str());

//    char in[2];
//    scanf("%s",in);
//    cout << in <<endl;
//    thread_test().join();

    socket_test();
//    socket_send_test();
//    auto t1 = create_thread([](int i1,int i2) {
//        printf("%d", i1*i2);
//    }, 23,32);
//    t1.join();

    printf("线程启动完成");

#ifdef  WIN32
    system ("pause");
#endif
#ifdef linux
    pause();
#endif
    return 0;
}





