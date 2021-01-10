
#include "binarysearchtree.h"
#include "searchalgorithms.h"

#include "mergesort.h"
#include "selectionsort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "bubblesort.h"

using namespace search_alg;
using namespace sort_alg;
using namespace utils;

void bst_oeprations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting BinarySearchTree operations..." << std::endl;

    BinarySearchTree bst;

    bst.print();

    bst.add(13);
    bst.add(34);
    bst.add(55);
    bst.add(21);
    bst.add(5);
    bst.add(8);
    bst.add(3);
    bst.add(144);
    bst.add(89);
    bst.add(233);
    bst.add(1);
    bst.add(2);
    bst.add(0);

    bst.print();

    std::cout << "Maximum: " << bst.minimum() << " -- Minimum: " << bst.maximum() << std::endl;

    TreeNode *foundNode = bst.find(233);
    if (foundNode != NULL)
    {
        std::cout << foundNode->m_value << " found in the list" << std::endl;
    }

    foundNode = bst.find(88);
    if (foundNode != NULL)
    {
        std::cout << foundNode->m_value << " found in the list" << std::endl;
    }
    else
    {
        std::cout << "88 not found in the list" << std::endl;
    }

    unsigned int treeDepth = bst.depth();
    std::cout << "depth of the tree is " << treeDepth << std::endl;

    /*****************************************************************/
    int *valueArray = bst.getAsSortedList();
    unsigned int arraySize = bst.size();
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << valueArray[i] << ", ";
    }
    std::cout << std::endl;
    /*****************************************************************/

    /*****************************************************************/
    std::cout << std::endl;
    bst.remove(3);
    valueArray = bst.getAsSortedList();
    arraySize = bst.size();
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << valueArray[i] << ", ";
    }
    std::cout << std::endl;
    /*****************************************************************/

    /*****************************************************************/
    std::cout << std::endl;
    bst.remove(13);
    valueArray = bst.getAsSortedList();
    arraySize = bst.size();
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << valueArray[i] << ", ";
    }
    std::cout << std::endl;
    /*****************************************************************/

    /*****************************************************************/
    std::cout << std::endl;
    bst.remove(89);
    valueArray = bst.getAsSortedList();
    arraySize = bst.size();
    for (unsigned int i = 0; i < arraySize; i++)
    {
        std::cout << valueArray[i] << ", ";
    }
    std::cout << std::endl;
    /*****************************************************************/

    treeDepth = bst.depth();
    std::cout << "depth of the tree is " << treeDepth << std::endl;

    std::cout << "Ending BinarySearchTree operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void mergesort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Merge Sort operations..." << std::endl;

    char charArray[] = {'M', 'E', 'R', 'G', 'E', 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    unsigned int arraySize = 16;

    printArray<char>(charArray, arraySize);

    std::cout << "===Before MergeSort===" << std::endl;
    std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray, 0, 15) << std::endl;

    MergeSort<char>(charArray, 16);

    std::cout << "===After MergeSort===" << std::endl;
    std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray, 0, 15) << std::endl;

    printArray<char>(charArray, arraySize);

    std::cout << "Ending Merge Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void selectionsort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Selection Sort operations..." << std::endl;

    int intArray2[] = {34, 17, 23, 35, 45, 9, 1};
    size_t arraySize = 7;

    printArray<int>(intArray2, arraySize);

    std::cout << "===Before SelectionSort===" << std::endl;
    std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray2, 0, 6) << std::endl;

    SelectionSort<int>(intArray2, arraySize);

    std::cout << "===After SelectionSort===" << std::endl;
    std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray2, 0, 6) << std::endl;

    printArray<int>(intArray2, arraySize);

    std::cout << "Ending Selection Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void quicksort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Quick Sort operations..." << std::endl;

    char charArray2[] = { 'Q','U','I','C','K','S','O','R','T','E','X','A','M','P','L','E' };
	size_t arraySize = 16;

	printArray<char>(charArray2, arraySize);

	std::cout << "===Before QuickSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray2, 0, 15) << std::endl;

	QuickSort<char>(charArray2, arraySize);

	std::cout << "===After QuickSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray2, 0, 15) << std::endl;

	printArray<char>(charArray2, arraySize);

    std::cout << "Ending Quick Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void insertionsort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Insertion Sort operations..." << std::endl;

    int intArray[] = { 24, 13, 9, 64, 7, 23, 34, 47 };
	size_t arraySize = 8;

	printArray<int>(intArray, arraySize);

	std::cout << "===Before InsertionSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray, 0, 7) << std::endl;

	InsertionSort<int>(intArray, arraySize);

	std::cout << "===After InsertionSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray, 0, 7) << std::endl;

	printArray<int>(intArray, arraySize);

    std::cout << "Ending Insertion Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void shellsort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Shell Sort operations..." << std::endl;

    int intArray[] = { 24, 13, 9, 64, 7, 23, 34, 47 };
	size_t arraySize = 8;

	printArray<int>(intArray, arraySize);

	std::cout << "===Before ShellSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray, 0, 7) << std::endl;

	ShellSort<int>(intArray, arraySize);

	std::cout << "===After ShellSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<int>(intArray, 0, 7) << std::endl;

	printArray<int>(intArray, arraySize);

    std::cout << "Ending Shell Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void bubblesort_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Bubble Sort operations..." << std::endl;

    char charArray3[] = { 'B','U','B','B','L', 'E', 'S','O','R','T','E','X','A','M','P','L','E' };
	size_t arraySize = 17;

	printArray<char>(charArray3, arraySize);

	std::cout << "===Before BubbleSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray3, 0, 16) << std::endl;

	BubbleSort<char>(charArray3, arraySize);

	std::cout << "===After BubbleSort===" << std::endl;
	std::cout << "isSorted=" << std::boolalpha << isSorted<char>(charArray3, 0, 16) << std::endl;

	printArray<char>(charArray3, arraySize);

    std::cout << "Ending Bubble Sort operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void binarysearch_operations() {
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Binary Search operations..." << std::endl;

    char charArray3[] = { 'B','U','B','B','L', 'E', 'S','O','R','T','E','X','A','M','P','L','E' };
	size_t arraySize = 17;

	int arry[] = {5, 2, 7, 9, 47, 123, 1456, 7853, 34356, 785647, 12312, 4, 798};
	arraySize = 13;
	std::sort(arry, arry + arraySize); // sort before search!
	try
	{
		int value = 4;
		unsigned int index = findInArray(value, arry, arraySize);
		std::cout << "Searched value " << value << " found in the array position " << index << std::endl;

		value = 12312;
		index = findInArray(value, arry, arraySize);
		std::cout << "Searched value " << value << " found in the array position " << index << std::endl;

		value = 234;
		index = findInArray(value, arry, arraySize);
		std::cout << "Searched value " << value << " found in the array position " << index << std::endl;

	}
	catch (std::exception & ex)
	{
		std::cout << "Exception occurred: " << ex.what() << std::endl;
	}

    std::cout << "Ending Binary Search operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

void quickselect_operations()
{
    std::cout << std::endl << "=======================================" << std::endl;
    std::cout << "Starting Quick Select operations..." << std::endl;

    char charArray[] = { 'Q','U','I','C','K','S','O','R','T','E','X','A','M','P','L','E' };
	size_t arraySize = 16;

	printArray<char>(charArray, arraySize);

    auto kth = 3;
	auto element = QuickSelect<char>(charArray, arraySize, kth);
    std::cout << kth << "th smallest element is: " << element << std::endl;

    QuickSort<char>(charArray, arraySize);
    printArray<char>(charArray, arraySize);

    std::cout << "Ending Quick Select operations..." << std::endl;
    std::cout << "=======================================" << std::endl;
}

int main()
{
    bst_oeprations();

    mergesort_operations();

    selectionsort_operations();

    quicksort_operations();

    insertionsort_operations();

    shellsort_operations();

    bubblesort_operations();

    binarysearch_operations();

    quickselect_operations();

    return 0;
}
