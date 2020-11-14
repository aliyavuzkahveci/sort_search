
#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include "utils.h"

namespace sort_alg {
    template <typename T>
	void SelectionSort(T* array, unsigned int arraySize) {
		// no need to cover the last element since it is already checked in the inner loop!
		for (auto i = 0; i < arraySize - 1; ++i) {
			auto smallestElementIndex = i;
			for (auto j = i + 1; j < arraySize; ++j) {
				if (array[j] < array[smallestElementIndex]) {
					smallestElementIndex = j;
				}
			}
			utils::swapWithTemp(array[i], array[smallestElementIndex]);
		}
	}

}

#endif // _SELECTION_SORT_H_
