//
// Created by xuniji on 2023/6/28.
//

#ifndef UNTITLED3_LOCALITY_POINTER_H
#define UNTITLED3_LOCALITY_POINTER_H

#include <cstdlib>

namespace pointer {
    //为指定类型申请内存空间
    template<typename T> T *f3(){
        return (T*) malloc(sizeof (T));
    }
    int *f1(){
        //需要使用malloc分配一个内存地址 并返回他的引用指针
//        int *i = (int *)malloc(sizeof (int ));
        int *i = f3<int>();
        *i = 10;
        return i;
    }

    char* *f2(){
        char **c = f3<char*>();
        *c = "1";
        return c;
    }

//无法过编译
//    int *f2(){
//        int x = 10;
//        return &x;
//    }
}
#endif //UNTITLED3_LOCALITY_POINTER_H
