#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <queue>
#include <memory>

#include "worker.h"

typedef std::shared_ptr<Worker> worker_ptr;

template<class _T>
struct AData
{
    AData():ready(false){}
    bool ready;
    _T data;
};

class ThreadPool
{
public:

    ThreadPool(size_t threads=1);
    ~ThreadPool(){}

    template<class FN, class... ARGS>
    void run_async(FN _fn, ARGS... _args)
    {
        this->get_free_worker()->append_fn(std::bind(_fn,_args...));
    }

    template<class R, class FN, class... ARGS>
    std::shared_ptr<AData<R>> run_async(FN _fn, ARGS... _args)
    {
        std::function<R()> rfn = std::bind(_fn,_args...);
        std::shared_ptr<AData<R>> pData(new AData<R>());
        fn_type fn = [=]()
        {
            pData->data = rfn();
            pData->ready = true;
        };
        this->get_free_worker()->append_fn(fn);
        return pData;
    }

    template<class _R, class... _FN_ARGS, class... _ARGS>
    std::shared_ptr<AData<_R>> run_async(_R (*_fn)(_FN_ARGS...), _ARGS... _args)
    {
        std::function<_R()> rfn = std::bind(_fn,_args...);
        std::shared_ptr<AData<_R>> pData(new AData<_R>());
        fn_type fn = [=]()
        {
            pData->data = rfn();
            pData->ready = true;
        };
        get_free_worker()->append_fn(fn);
        return pData;
    }

private:
    std::vector<worker_ptr> _workers;

    worker_ptr get_free_worker();
};


#endif // THREADPOOL_H
