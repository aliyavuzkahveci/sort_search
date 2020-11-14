
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <iostream>

namespace search_alg
{
    struct TreeNode
    {
        TreeNode()
        {
            m_value = 0;
            m_parent = NULL;
            m_left = NULL;
            m_right = NULL;
        }

        TreeNode(int value)
        {
            m_value = value;
            m_parent = NULL;
            m_left = NULL;
            m_right = NULL;
        }

        TreeNode(int value, TreeNode *parent)
        {
            m_value = value;
            m_parent = parent;
            m_left = NULL;
            m_right = NULL;
        }

        TreeNode(int value, TreeNode *parent, TreeNode *left, TreeNode *right)
        {
            m_value = value;
            m_parent = parent;
            m_left = left;
            m_right = right;
        }

        int m_value;
        TreeNode *m_parent;
        TreeNode *m_left;
        TreeNode *m_right;
    };

    class BinarySearchTree
    {
    public:
        BinarySearchTree() = default;

        virtual ~BinarySearchTree() = default;

        void print() noexcept; // print the tree in a SORTED manner

        int *getAsSortedList() noexcept; // may return NULL if empty!

        unsigned int size() noexcept; // return the # of elements in the tree

        unsigned int depth() noexcept; // return the depth of the tree

        bool empty() noexcept;

        void add(int value) noexcept;

        void remove(int value); // may throw value not found exception!!!

        TreeNode *find(int value) noexcept; // may return NULL if not found OR throw NOT_FOUND exception

        int minimum(); // may throw empty list exception!!!

        int maximum(); // may throw empty list exception!!!

    private:
        TreeNode *m_root = NULL;
        unsigned int m_treeSize = 0;
        unsigned int m_depth = 0;

        TreeNode *getMinNode();

        TreeNode *getMaxNode();

        void printSubTree(TreeNode *node) noexcept;

        void addNodeValueToArray(TreeNode *node, int *valueArray, unsigned int &index) noexcept;

        unsigned int subTreeSize(TreeNode *node) noexcept;

        unsigned int subTreeDepth(TreeNode *node) noexcept;

        TreeNode *findNode(TreeNode *subRoot, int value) noexcept;

        bool isLeaf(TreeNode *node) noexcept;

        void detachFromParent(TreeNode *node) noexcept;
    };
} // namespace search_alg

#endif // _BINARY_SEARCH_TREE_H_
