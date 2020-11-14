
#ifndef _BINARY_MAX_HEAP_H_
#define _BINARY_MAX_HEAP_H_

namespace sort_alg
{
    class BinaryMaxHeap
    {
    public:
        BinaryMaxHeap(unsigned int heapSize = 57);

        virtual ~BinaryMaxHeap();

        bool IsEmpty() noexcept;

        unsigned int GetSize() noexcept;

        void Insert(int value);

        int ExtractMax();

        void Remove(unsigned int index);

        void ChangePriority(unsigned int index, int newValue);

        void BuildHeap(int *valueArray, unsigned int size);

        int *HeapSort(int *valueArray, unsigned int size);

    private:
        // indexing starts at 1!

        unsigned int parentIndex(unsigned int index);

        unsigned int leftChildIndex(unsigned int index);

        unsigned int rightChildIndex(unsigned int index);

        void swapValues(unsigned int index1, unsigned int index2) noexcept;

        void siftUp(unsigned int index) noexcept;

        void siftDown(unsigned int index) noexcept;

        int *m_heap;
        unsigned int m_size;
        unsigned int m_maxSize;
    };
} // namespace sort_alg

#endif // _BINARY_MAX_HEAP_H_
