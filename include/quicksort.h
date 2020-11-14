
#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "utils.h"

namespace sort_alg
{
    template <typename T>
    unsigned int partition(T *array, int start, int end)
    {
        int i = start;
        int j = end + 1; // will be decremented BEFORE starting comparison!

        while (true)
        {

            // move cursor i to the right as long as it is less than the selected element
            while (array[++i] < array[start])
            {
                if (i == end)
                { // moving to the right reached to the end of the array
                    break;
                }
            }

            // move cursor j to the left as long as it is greater than the selected element
            while (array[start] < array[--j])
            {
                if (j == start)
                { // moving to the right reached to the end of the array
                    break;
                }
            }

            if (j <= i)
            { // completed partitioning operation
                break;
            }

            utils::swapWithTemp(array[i], array[j]); // swap values for correct sorting
        }

        utils::swapWithTemp(array[start], array[j]); // swap the partitioning item

        return j;
    }

    template <typename T>
    void sort(T *array, int start, int end)
    {
        if (end <= start)
        { // termination criteria, simply exit when indexes are the same
            return;
        }
        auto partitioningItemIndex = partition(array, start, end);
        sort(array, 0, partitioningItemIndex - 1);
        sort(array, partitioningItemIndex + 1, end);
    }

    template <typename T>
    void QuickSort(T *array, unsigned int arraySize)
    {
        // first shuffle to make sure performance guarantee
        utils::shuffle(array, arraySize);

        // start sorting using QuickSort algorithm
        sort(array, 0, arraySize - 1);
    }
} // namespace sort_alg

#endif // _QUICK_SORT_H_