
#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include <iostream>

namespace search_alg
{
    // return the index of value if found! throw exception otherwise!
    template <typename T>
    unsigned int binarySearch(T value, T *arry, unsigned int min, unsigned int max)
    {
        unsigned int pos = (max + min) / 2;
        if (arry[pos] > value) // keep search in the second half
        {
            max = pos;
        }
        else if (arry[pos] < value) // keep search in the first half
        {
            min = pos + 1;
        }
        else if (arry[pos] == value) // match found
        {
            return pos;
        }

        if (min >= max)
        {
            throw std::out_of_range("value not found in the array!");
        }

        // keep search!
        return binarySearch(value, arry, min, max);
    }

    template <typename T>
    int findInArray(T value, T *arry, unsigned int arrySize)
    {
        return binarySearch(value, arry, 0, arrySize - 1);
    }
} // namespace search_alg

#endif // _BINARY_SEARCH_H_