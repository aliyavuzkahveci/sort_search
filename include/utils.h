
#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

namespace utils
{
    template <typename T>
    void printArray(T *arrayPtr, unsigned int arraySize) noexcept
    {
        for (unsigned int i = 0; i < arraySize - 1; ++i)
        {
            std::cout << arrayPtr[i] << ", ";
        }
        std::cout << arrayPtr[arraySize - 1] << std::endl;
    }

    template <typename T>
    bool isSorted(T *arrayPtr, unsigned int start, unsigned int end) noexcept
    {
        for (unsigned int i = start + 1; i <= end; ++i)
        {
            if (arrayPtr[i - 1] > arrayPtr[i])
            {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    void swapXOR(T &value1, T &value2) noexcept
    {
        //std::cout << "--Before SWAP--" << std::endl;
        //std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;

        value1 = value1 ^ value2;
        value2 = value2 ^ value1;
        value1 = value1 ^ value2;

        //std::cout << "--After SWAP--" << std::endl;
        //std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;
    }

    template <typename T>
    void swapWithTemp(T &value1, T &value2)
    {
        //std::cout << "--Before SWAP--" << std::endl;
        //std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;

        auto tempVal = value1;
        value1 = value2;
        value2 = tempVal;

        //std::cout << "--Before SWAP--" << std::endl;
        //std::cout << "value1: " << value1 << " value2: " << value2 << std::endl;
    }

    template <typename T>
    void shuffle(T *arrayPtr, unsigned int arraySize) noexcept
    {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::shuffle(arrayPtr, arrayPtr + arraySize, std::default_random_engine(seed));
    }

    template <typename T>
    void shuffleKnuth(T* arrayPtr, unsigned int arraySize) noexcept
    {
        // initialize random function with a seed
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::srand(seed);

        // start from position 1 since no meaning to swap an item with itself
        for(size_t i = 1; i < arraySize; ++i)
        {
            auto swapIndex = std::rand() % i;
            //std::cout << "swapping indices: " << swapIndex << " & " << i << std::endl;
            swapWithTemp(arrayPtr[swapIndex], arrayPtr[i]);
        }
    }

} // namespace utils

#endif // _UTILS_H_
