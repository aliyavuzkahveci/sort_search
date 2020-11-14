
#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include "utils.h"

namespace sort_alg
{
    template <typename T>
    void BubbleSort(T *array, unsigned int arraySize)
    {
        for (unsigned int i = 0; i < (arraySize - 1); i++)
        {
            for (unsigned int j = 0; j < (arraySize - i - 1); j++)
            {
                if (array[j] > array[j + 1])
                {
                    utils::swapWithTemp(array[j], array[j + 1]);
                }
            }
        }
    }
} // namespace sort_alg

#endif // _BUBBLE_SORT_H_