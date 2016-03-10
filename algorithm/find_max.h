#ifndef FIND_MAX
#define FIND_MAX

#include <iostream>

template <class Iterator, class U = typename std::iterator_traits<Iterator>::value_type>
static Iterator find_max_core(Iterator const &begin, Iterator const &end)
{
    int it_mean = (end - begin)/2;

    U mean = *(begin + it_mean);
    U left_mean = *(begin + it_mean - 1);
    U righ_mean = *(begin + it_mean + 1);

    try{
        if (mean >= left_mean && mean >= righ_mean){
            return (begin + it_mean);
        }

        else if (mean > left_mean){
            find_max_core(begin + it_mean, end);
        }

        else if (mean > righ_mean){
            find_max_core(begin, end - it_mean);
        }

        else throw;
    }

    catch(...){
        std::cerr << "Warning: Position of max element not found" << std::endl;
        return begin;
    }

}


template <class Iterator, class U = typename std::iterator_traits<Iterator>::value_type>
U find_max(Iterator const &begin, Iterator const &end)
{
    Iterator it_max_number;
    it_max_number = find_max_core(begin, end);
    return it_max_number - begin;
}

#endif // FIND_MAX

