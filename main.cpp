#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <cstdlib>

//#include "patern/singleton.h"
#include "taimer.h"
//#include "algorithm/find_max.h"
//#include "virtual_inheritance.h"


#include "multithread/threadpool.h"


long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    float elapsed_seconds = 0;
    Taimer taimer(&elapsed_seconds);

    ThreadPool pool(3);

    std::cout <<"Start"<< std::endl;
    taimer.start();

    std::list<std::shared_ptr<AData<long>>> pool_weit;
    for (int i=0; i<10; i++)
    {
        int n = std::rand() % 3 + 40;
        std::cout <<n<< std::endl;
        pool_weit.push_back(pool.run_async(&fibonacci, n));
    }

//    pool_weit.push_back(pool.run_async(&fibonacci, 44));
//    pool_weit.push_back(pool.run_async(&fibonacci, 43));
//    pool_weit.push_back(pool.run_async(&fibonacci, 45));
//    pool_weit.push_back(pool.run_async(&fibonacci, 44));

    while(!pool_weit.empty()){
        for (auto it = pool_weit.begin(), end = pool_weit.end(); it!=end; ++it){
            if((*it)->ready){
                std::cout << (*it)->data << std::endl;
                pool_weit.remove(*it);
                --it; // list decreased by one item
            }
        }

        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }

    taimer.stop();
    std::cout <<"\nElapsed time: " << elapsed_seconds << "sec."<< std::endl;

    return 0;
}


/*
int main()
{

    std::vector<int> v;
    for (int i=1; i<400; ++i){
        v.push_back(i);
    }

    for (int i=400; i>20; --i){
        v.push_back(i);
    }

    float elapsed_seconds;
    Taimer * t = new Taimer(&elapsed_seconds);

    int pos_max_number = find_max(v.begin(), v.end());
    std::cout << v.at(pos_max_number) << " " << pos_max_number << std::endl;

    t->~Taimer();
    std::cout << "Elapsed time: " << elapsed_seconds << "sec." << std::endl;

    std::vector<int>::iterator begin = v.begin();

    return 0;
}*/
