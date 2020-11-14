
#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "utils.h"

namespace sort_alg
{
    template <typename T>
    void merge(T *array, T *auxiliary, unsigned int start, unsigned int mid, unsigned int end)
    {
        if (!utils::isSorted<T>(array, start, mid) || !utils::isSorted<T>(array, mid + 1, end))
        {
            throw std::range_error("at least one of the sub-arrays are NOT sorted!");
        }

        for (unsigned int i = start; i <= end; ++i)
        {
            auxiliary[i] = array[i];
        }

        unsigned int firstHead = start;
        unsigned int secondHead = mid + 1;
        for (unsigned int counter = start; counter <= end; counter++)
        {
            if (firstHead > mid)
            { // first half completed merging
                array[counter] = auxiliary[secondHead];
                secondHead++;
            }
            else if (secondHead > end)
            { // second half completed merging
                array[counter] = auxiliary[firstHead];
                firstHead++;
            }
            else if (auxiliary[secondHead] < auxiliary[firstHead])
            { // element in 2nd part is smaller!
                array[counter] = auxiliary[secondHead];
                secondHead++;
            }
            else // element in the 1st half is smaller
            {
                array[counter] = auxiliary[firstHead];
                firstHead++;
            }
        }
    }

    template <typename T>
    void sort(T *array, T *auxiliary, unsigned int start, unsigned int end)
    {
        if (end <= start)
        {
            return; // empty or 1-sized array is already sorted!
        }

        // divide the array into 2 halves
        unsigned int mid = start + ((end - start) / 2);
        sort<T>(array, auxiliary, start, mid);
        sort<T>(array, auxiliary, mid + 1, end);
        merge<T>(array, auxiliary, start, mid, end);
    }

    template <typename T>
    void MergeSort(T *arrayPtr, unsigned int arraySize) noexcept
    {
        // also covers empty array and array with 1 element!
        if (utils::isSorted<T>(arrayPtr, 0, arraySize - 1))
        {
            return;
        }

        auto auxiliary = new T[arraySize];
        sort(arrayPtr, auxiliary, 0, arraySize - 1);
    }
} // namespace sort_alg

#endif // _MERGE_SORT_H_
