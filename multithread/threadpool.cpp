#include "multithread/threadpool.h"

#include <limits>

ThreadPool::ThreadPool(size_t threads)
{
    if (threads == 0)
        threads = 1;

    for (size_t i=0; i<threads; i++){
        worker_ptr pWorker(new Worker);
        this->_workers.push_back(pWorker);
    }
}

worker_ptr ThreadPool::get_free_worker()
{
    worker_ptr pWorker;
    size_t minTasks = std::numeric_limits<long>::max();
    for (auto &it : this->_workers)
    {
        if (it->is_empty())
        {
            return it;
        }
        else if(minTasks > it->get_task_count()){
            minTasks = it->get_task_count();
            pWorker = it;
        }
    }
    return pWorker;
}
