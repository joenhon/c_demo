//
// Created by xuniji on 2023/6/26.
//

#include "../hpp/method_pointer.h"



 bool  method_pointer::def(int i, bool (*def2)(int)) {
    return i < 20 && def2(i);
}



bool  method_pointer::def2(int i){
    return i <= 11;
}

std::string method_pointer::str(std::string star, std::string end, bool (*param)(int ,bool (*)(int )), bool (*param2)(int )){
    std::string result = "";
    for (int i = star.size(); i < end.size(); i++) {
        if (param(i,param2)){
            result += "1 ";
        }
    }
    return result;
}

method_pointer::method_pointer() = default;

method_pointer::~method_pointer() = default;
