#include "binarysearchtree.h"

namespace search_alg
{
    TreeNode *BinarySearchTree::getMinNode()
    {
        if (m_root == NULL)
        {
            throw std::underflow_error("Tree is empty!");
        }
        else
        {
            TreeNode *minNode = m_root;

            while (minNode->m_left != NULL)
            {
                minNode = minNode->m_left;
            }

            return minNode;
        }
    }

    TreeNode *BinarySearchTree::getMaxNode()
    {
        if (m_root == NULL)
        {
            throw std::underflow_error("Tree is empty!");
        }
        else
        {
            TreeNode *maxNode = m_root;

            while (maxNode->m_right != NULL)
            {
                maxNode = maxNode->m_right;
            }

            return maxNode;
        }
    }

    void BinarySearchTree::printSubTree(TreeNode *node) noexcept
    {
        if (node->m_left != NULL)
        {
            printSubTree(node->m_left);
        }
        std::cout << node->m_value << ", ";
        if (node->m_right != NULL)
        {
            printSubTree(node->m_right);
        }
    }

    void BinarySearchTree::print() noexcept
    {
        if (empty())
        {
            std::cout << "Empty Tree...";
        }
        else
        {
            printSubTree(m_root);
        }
        std::cout << std::endl;
    }

    void BinarySearchTree::addNodeValueToArray(TreeNode *node, int *valueArray, unsigned int &index) noexcept
    {
        if (node->m_left != NULL)
        {
            addNodeValueToArray(node->m_left, valueArray, index);
        }

        valueArray[index] = node->m_value;
        index++;

        if (node->m_right != NULL)
        {
            addNodeValueToArray(node->m_right, valueArray, index);
        }
    }

    int *BinarySearchTree::getAsSortedList() noexcept
    {
        if (empty())
        {
            return NULL;
        }
        else
        {
            unsigned int arraySize = size();
            unsigned int index = 0;
            int *valueArray = new int[arraySize];

            addNodeValueToArray(m_root, valueArray, index);

            return valueArray;
        }
    }

    unsigned int BinarySearchTree::subTreeSize(TreeNode *node) noexcept
    {
        unsigned int numOfNodes = 0;

        if (node->m_left != NULL)
        {
            numOfNodes += subTreeSize(node->m_left);
        }

        numOfNodes++; // node itself!

        if (node->m_right != NULL)
        {
            numOfNodes += subTreeSize(node->m_right);
        }

        return numOfNodes;
    }

    unsigned int BinarySearchTree::subTreeDepth(TreeNode *node) noexcept
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            unsigned int leftSubTreeDepth = subTreeDepth(node->m_left);
            unsigned int rightSubTreeDepth = subTreeDepth(node->m_right);
            unsigned int returnValue = (leftSubTreeDepth > rightSubTreeDepth) ? leftSubTreeDepth : rightSubTreeDepth;
            returnValue++; // itself
            return returnValue;
        }
    }

    unsigned int BinarySearchTree::size() noexcept
    {
        if (empty())
        {
            return 0;
        }
        else
        {
            return subTreeSize(m_root);
        }
    }

    unsigned int BinarySearchTree::depth() noexcept
    {
        unsigned int treeDepth = subTreeDepth(m_root);

        return treeDepth;
    }

    bool BinarySearchTree::empty() noexcept
    {
        return m_root == NULL;
    }

    int BinarySearchTree::minimum()
    {
        TreeNode *minNode = getMinNode();

        return minNode->m_value;
    }

    int BinarySearchTree::maximum()
    {
        TreeNode *maxNode = getMaxNode();

        return maxNode->m_value;
    }

    TreeNode *BinarySearchTree::findNode(TreeNode *subRoot, int value) noexcept
    {
        if (subRoot == NULL)
        {
            return NULL;
        }
        else if (subRoot->m_value == value)
        {
            return subRoot;
        }
        else if (subRoot->m_value < value)
        {
            return findNode(subRoot->m_right, value);
        }
        else //if(subRoot->m_value > value)
        {
            return findNode(subRoot->m_left, value);
        }
    }

    TreeNode *BinarySearchTree::find(int value) noexcept
    {
        return findNode(m_root, value);
    }

    bool BinarySearchTree::isLeaf(TreeNode *node) noexcept
    {
        if (node != NULL && node->m_left == NULL && node->m_right == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void BinarySearchTree::add(int value) noexcept
    {
        if (empty()) // setting the root node
        {
            m_root = new TreeNode(value);
        }
        else
        {
            TreeNode *traverser = m_root;

            while (traverser != NULL)
            {
                if (traverser->m_value < value)
                {
                    if (traverser->m_right == NULL)
                    {
                        TreeNode *newNode = new TreeNode(value, traverser);
                        traverser->m_right = newNode;
                        break;
                    }
                    else
                    {
                        traverser = traverser->m_right;
                    }
                }
                else if (traverser->m_value > value)
                {
                    if (traverser->m_left == NULL)
                    {
                        TreeNode *newNode = new TreeNode(value, traverser);
                        traverser->m_left = newNode;
                        break;
                    }
                    else
                    {
                        traverser = traverser->m_left;
                    }
                }
                else
                {
                    throw std::domain_error("Element is already in the list!");
                }
            }
        }
    }

    void BinarySearchTree::remove(int value)
    {
        TreeNode *node = find(value);

        if (node == NULL)
        {
            throw std::out_of_range("value not found in the tree");
        }
        else if (node->m_left == NULL || node->m_right == NULL)
        {
            detachFromParent(node);
        }
        else
        {
            int *nodeArray = getAsSortedList();
            unsigned int arraySize = size();
            int nextBiggerValue = 0;
            for (unsigned int i = 0; i < arraySize; i++)
            {
                if (nodeArray[i] == node->m_value)
                {
                    nextBiggerValue = nodeArray[i + 1];
                    break;
                }
                else
                {
                    continue;
                }
            }

            TreeNode *replacementNode = find(nextBiggerValue);

            // detaach the replacement node from its parent
            detachFromParent(replacementNode);

            // relocate the replacement node in the deleted node position
            replacementNode->m_parent = node->m_parent;
            replacementNode->m_left = node->m_left;
            replacementNode->m_right = node->m_right;

            // reset the root node!
            if (replacementNode->m_parent == NULL)
            {
                m_root = replacementNode;
            }
        }

        delete node;
    }

    void BinarySearchTree::detachFromParent(TreeNode *node) noexcept
    {
        if (node->m_value < node->m_parent->m_value)
        { // node is on the left side of its parent
            node->m_parent->m_left = node->m_left;
        }
        else
        { // node is on the right side of its parent
            node->m_parent->m_right = node->m_right;
        }
    }

} // namespace search_alg