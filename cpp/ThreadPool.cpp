//
// Created by xuniji on 2023/7/10.
//

#include "ThreadPool.h"

namespace ThreadPoolTool_Joen {

    ThreadPool_::ThreadPool_(int maxCore_) : maxCore(maxCore_) {

    }

//    template<class F, class... Args>
//    Thread_ ThreadPool_::add( F&& f, Args&& ...args)

//    Thread_::Thread_(ThreadPool_ *pool) :
//            pool(pool){
//
//    }

//    template<class Method, class... Args>
//    void Thread_::init(Method &&method ,Args &&... args){
//        this->args = forward<Args...>(args...);
//        this->method = method;
//    }

    template<class Method, class ... Args>
    thread Thread_::start() {
        if (pool->running->try_lock()) {

            thread t1(method, forward<Args>(&args)...);
            this->th = forward<thread *>(&t1);
            if (join_) {
                t1.join();
            }
            if (detach_) {
                t1.detach();
            }
            //释放锁
            pool->running->unlock();
        }
    }

    void Thread_::join() {
        if (detach_) {
            printf("线程已经进行分离了，不能在进行等待");
        } else {
            join_ = true;
            if (th != nullptr) {
                th->join();
            }
        }
    }

    void Thread_::detach() {
        if (join_) {
            printf("线程已经进行等待了，不能在进行分离");
        } else {
            detach_ = true;
            if (th != nullptr) {
                th->detach();
            }
        }
    }


}



