
#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include "utils.h"

namespace sort_alg {

    template<typename T>
    void ShellSort(T* array, unsigned int arraySize) {
        // h-sorting for decreasing sequence of values of h
        // Knuth proposition => h = 3x+1

        // first find the highest possible value of h
        auto h = 1;
        while(h < arraySize/3) { // 1, 4, 13, 40, ...
            h = 3*h + 1;
        }

        for(; h >= 1; h /= 3) {
            // the rest is just insertion sort
            for(auto i = h; i < arraySize; ++i) {
                auto temp = array[i]; // keep it in temp to open position for exchanges.
                // shift earlier elements to the location until correct location for array[i] is found
                auto j = i;
                for(; j >= h && array[j-h] > temp; j -= h) {
                    array[j] = array[j-h];
                }

                // put the temp (orijinal array[i]) to its correct location!
                array[j] = temp;
            }
        }
    }

} // namespace sort_alg

#endif // _SHELL_SORT_H_
