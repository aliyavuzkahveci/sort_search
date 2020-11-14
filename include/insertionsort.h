
#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "utils.h"

namespace sort_alg
{
    template <typename T>
    void InsertionSort(T *array, unsigned int arraySize)
    {
        // first element is already considered as sorted since there is no element to compare!
        for (auto i = 1; i < arraySize; ++i)
        {
            for (auto j = i - 1; j >= 0; --j)
            {
                if (array[j] > array[j + 1])
                {
                    utils::swapWithTemp(array[j], array[j + 1]);
                }
            }
        }
    }
} // namespace sort_alg

#endif // _INSERTION_SORT_H_