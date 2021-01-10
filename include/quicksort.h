
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

    // returns the kth smallest element in the array!
    template<typename T>
    T QuickSelect(T* array, unsigned int arraySize, unsigned int kth)
    {
        if(kth > arraySize)
        {
            throw std::out_of_range("value not found in the array!");
        }
        utils::shuffle(array, arraySize);
        auto start = 0;
        auto end = arraySize-1;

        while(start < end) {
            auto j = partition(array, start, end);

            if(j < kth) // kth smallest element stays in the second half!
            {
                start = j + 1; // next round, check the SECOND half
            }
            else if (j > kth) // kth smallest element stays in the first half!
            {
                end = j - 1; // next round, check the FIRST half
            }
            else
            {
                return array[j]; // partition element is the kth smallest one!
            }
            
        }

        return array[kth];
    }
} // namespace sort_alg

#endif // _QUICK_SORT_H_