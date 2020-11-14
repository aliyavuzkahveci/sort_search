
#include "binarymaxheap.h"
#include <iostream>

namespace sort_alg
{
    BinaryMaxHeap::BinaryMaxHeap(unsigned int heapSize)
    {
        m_maxSize = heapSize;
        m_size = 0;
        m_heap = new int[m_maxSize];
    }

    BinaryMaxHeap::~BinaryMaxHeap()
    {
        delete m_heap;
    }

    unsigned int BinaryMaxHeap::parentIndex(unsigned int index)
    {
        auto parentIndex = index / 2;

        if (parentIndex == 0)
        {
            throw std::out_of_range("IndexOutIOfRange exception! Indexing starts at 1!");
        }

        return parentIndex;
    }

    unsigned int BinaryMaxHeap::leftChildIndex(unsigned int index)
    {
        auto leftIndex = index * 2;

        if (leftIndex >= m_maxSize)
        {
            throw std::out_of_range("IndexOutOfRange exception! Index cannot exceed max size!");
        }

        return leftIndex;
    }

    unsigned int BinaryMaxHeap::rightChildIndex(unsigned int index)
    {
        auto rightIndex = (index * 2) + 1;

        if (rightIndex >= m_maxSize)
        {
            throw std::out_of_range("IndexOutOfRange exception! Index cannot exceed max size!");
        }

        return rightIndex;
    }

    void BinaryMaxHeap::swapValues(unsigned int index1, unsigned int index2) noexcept
    {
        auto temp = m_heap[index1];
        m_heap[index1] = m_heap[index2];
        m_heap[index2] = temp;
    }

    void BinaryMaxHeap::siftUp(unsigned int index) noexcept
    {
        while (index > 1)
        {
            auto parentIndx = parentIndex(index);
            if (m_heap[parentIndx - 1] < m_heap[index - 1])
            {
                swapValues(parentIndx - 1, index - 1);
                index = parentIndx;
            }
            else
            {
                break;
            }
        }
    }

    void BinaryMaxHeap::siftDown(unsigned int index) noexcept
    {
        auto leftIndex = leftChildIndex(index);
        auto rightIndex = rightChildIndex(index);
        auto maxIndex = index;

        if (leftIndex <= m_size && m_heap[index - 1] > m_heap[leftIndex - 1])
        {
            maxIndex = leftIndex;
        }

        if (rightIndex <= m_size && m_heap[index - 1] > m_heap[rightIndex - 1])
        {
            maxIndex = rightIndex;
        }

        if (index != maxIndex)
        {
            swapValues(index - 1, maxIndex - 1);
            siftDown(maxIndex);
        }
    }

    bool BinaryMaxHeap::IsEmpty() noexcept
    {
        return m_size == 0;
    }

    unsigned int BinaryMaxHeap::GetSize() noexcept
    {
        return m_size;
    }

    void BinaryMaxHeap::Insert(int value)
    {
        if (m_size == m_maxSize)
        {
            throw std::overflow_error("MAX SIZE reached!");
        }

        m_heap[m_size] = value;
        ++m_size;

        // re-arrange the position of value
        siftUp(m_size);
    }

    int BinaryMaxHeap::ExtractMax()
    {
        if (IsEmpty())
        {
            throw std::underflow_error("Empty heap!");
        }
        int returnValue = m_heap[0];
        m_heap[0] = m_heap[m_size - 1];
        --m_size;

        // re-arrange the position of the last element
        siftDown(1);

        return returnValue;
    }

    void BinaryMaxHeap::Remove(unsigned int index)
    {
        int maxValue = m_heap[0];

        // re-set its priority to be maximum
        m_heap[index - 1] = maxValue + 1;

        // re-arrange its position in the heap
        siftUp(index);

        // remove from the heap
        ExtractMax();
    }

    void BinaryMaxHeap::ChangePriority(unsigned int index, int newValue)
    {
        if (index > m_size)
        {
            throw std::out_of_range("IndexOutOfArray exception!");
        }

        int oldValue = m_heap[index - 1];
        m_heap[index - 1] = newValue;

        if (newValue > oldValue)
        {
            siftUp(index);
        }
        else
        {
            siftDown(index);
        }
    }

    void BinaryMaxHeap::BuildHeap(int *valueArray, unsigned int size)
    {
        if (size > m_maxSize)
        {
            throw std::overflow_error("Max Size over reached!");
        }

        // copy values of valueArray into our heap
        for (unsigned int i = 0; i < size; ++i)
        {
            m_heap[i] = valueArray[i];
        }
        m_size = size;

        for (unsigned int i = (m_size / 2); i > 0; --i)
        {
            siftDown(i);
        }
    }

    int *BinaryMaxHeap::HeapSort(int *valueArray, unsigned int size)
    {
        // generate a heap from an array
        BuildHeap(valueArray, size);

        for (unsigned int i = 0; i < (size - 1); ++i)
        {
            // swap last and first element in the heap
            swapValues(0, m_size - 1);

            // decrease the size of heap, forget about the last element!
            --m_size;

            siftDown(1);
        }

        return m_heap;
    }
} // namespace sort_alg
