#ifndef WORKER_H
#define WORKER_H

#include <functional>
#include <thread>
#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>

typedef std::function<void()> fn_type;

class Worker
{
public:
    Worker();
    ~Worker();
    void append_fn(fn_type fn);
    size_t get_task_count();
    bool is_empty();

private:
    bool enabled;
    std::condition_variable cv;
    std::queue<fn_type> fqueue;
    std::mutex mutex;
    std::thread thread;

    void thread_fn();
};

#endif // WORKER_H
