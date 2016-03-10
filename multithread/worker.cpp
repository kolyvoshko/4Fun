#include "multithread/worker.h"

Worker::Worker()
    :enabled(true), fqueue(),
      thread(&Worker::thread_fn, this)
{}


Worker::~Worker()
{
    enabled = false;
    cv.notify_one();
    thread.join();
}

void Worker::append_fn(fn_type fn)
{
    std::unique_lock<std::mutex> locker(mutex);
    fqueue.push(fn);
    cv.notify_one();
}

size_t Worker::get_task_count()
{
    std::unique_lock<std::mutex> locker(mutex);
    return fqueue.size();
}

bool Worker::is_empty()
{
    std::unique_lock<std::mutex> locker(mutex);
    return fqueue.empty();
}

void Worker::thread_fn()
{
    while (enabled) {
        std::unique_lock<std::mutex> locker(mutex);
        cv.wait(locker, [&](){ return !fqueue.empty() || !enabled; });

        while (!fqueue.empty()) {
            fn_type fn = fqueue.front();
            locker.unlock();
            fn();
            locker.lock();
            fqueue.pop();
        }
    }
}

