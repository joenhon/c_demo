//
// Created by xuniji on 2023/7/10.
//

#ifndef UNTITLED3_THREADPOOL_H
#define UNTITLED3_THREADPOOL_H

#include <thread>
#include <queue>
#include <mutex>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


namespace ThreadPoolTool_Joen {
    class ThreadPool_;

    class Thread_ {
    public:
        template<class... Args>
        Thread_(ThreadPool_ *pool,Args &&... args) :pool(pool), args(forward<Args>(args)...){

        };

        template<class Method, class... Args>
        void init(Method &&method, Args &&... args) {
//            this->args = (forward<Args...>(args)...);
            this->method = (void *)method;
        }

//    Thread_(const Thread_& other) = delete;
//    Thread_& operator = (const Thread_& other) = delete;

        template<class Method, class ...Args>
        thread start();

        void join();

        void detach();

        long long get_id() const noexcept { return id; }

        bool joinable() const noexcept { return !join_ && !detach_; }

    private:
        void *method;
        void *args;
        long long id;
        bool join_ = false;
        bool detach_ = false;
        ThreadPool_ *pool;
        thread *th;
    };


    class ThreadPool_ {
    public:
        ThreadPool_(int maxCore);

        ThreadPool_(const ThreadPool_ &other) = delete;

        ThreadPool_ &operator=(const ThreadPool_ &other) = delete;

        //运行锁
        mutex *running = (new mutex());

        template<class F, class... Args>
        Thread_ add(F &&f, Args &&...args) {
            auto core = [](ThreadPool_ *pool, queue<Thread_ *> threadPool) -> void {
                while (1) {
                    this_thread::sleep_for(nanoseconds(1000));
                    if (!threadPool.empty() && pool->runningCount < pool->maxCore) {
                        Thread_ *th = threadPool.front();
                        th->start<F, Args...>();
                    }
                }
            };

//            static thread t_core(core);
            auto *th = new Thread_(this,forward<Args>(args)...);
            th->init(f, forward<Args>(args)...);
            threadPool.push(th);
            return *th;
        };

    private:
        //当前运行线程数
        int runningCount = 0;
        //最大核心数
        int maxCore = 4;
        //池队列
        queue<Thread_ *> threadPool = *new queue<Thread_ *>();
    };


};


#endif //UNTITLED3_THREADPOOL_H
