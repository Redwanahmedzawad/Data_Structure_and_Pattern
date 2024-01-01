
// COS30008, Tutorial 11, 2023

#include <iostream>

#include "BTree.h"

void testBTree()
{
    using BSTree = BTree<size_t>;
    using BSTreeNode = typename BSTree::Node;

    BSTreeNode n25 = BSTree::makeNode(25);
    BSTreeNode n10 = BSTree::makeNode(10);
    BSTreeNode n15 = BSTree::makeNode(15);
    BSTreeNode n37 = BSTree::makeNode(37);
    BSTreeNode n30 = BSTree::makeNode(30);
    BSTreeNode n65 = BSTree::makeNode(65);

    std::cout << "Constructed nodes:" << std::endl;
    
    std::cout << "n25:\t" << **n25 << std::endl;
    std::cout << "n10:\t" << **n10 << std::endl;
    std::cout << "n15:\t" << **n15 << std::endl;
    std::cout << "n37:\t" << **n37 << std::endl;
    std::cout << "n30:\t" << **n30 << std::endl;
    std::cout << "n65:\t" << **n65 << std::endl;

    n25->attachLeft(n10);
    n25->attachRight(n37);

    n25->left().attachRight(n15);
    n25->right().attachLeft(n30);
    n25->right().attachRight(n65);

    std::cout << "Node integrity (unique_ptr):" << std::endl;
    
    if ( !n10 )
    {
        std::cout << "n10 ok" << std::endl;
    }
    else
    {
        std::cout << "n10 broken" << std::endl;
    }

    if ( !n37 )
    {
        std::cout << "n37 ok" << std::endl;
    }
    else
    {
        std::cout << "n37 broken" << std::endl;
    }

    if ( !n15 )
    {
        std::cout << "n15 ok" << std::endl;
    }
    else
    {
        std::cout << "n15 broken" << std::endl;
    }

    if ( !n30 )
    {
        std::cout << "n30 ok" << std::endl;
    }
    else
    {
        std::cout << "n30 broken" << std::endl;
    }
    
    if ( !n65 )
    {
        std::cout << "n65 ok" << std::endl;
    }
    else
    {
        std::cout << "n65 broken" << std::endl;
    }

    std::cout << "Service functions:" << std::endl;
    
    const BSTreeNode& aBTree = n25;

    std::cout << "Height of aBTree: " << aBTree->height() << std::endl;
    std::cout << "Left max of 25: " << aBTree->left().findMax() << std::endl;
    std::cout << "Right min of 25: " << aBTree->right().findMin() << std::endl;

    std::cout << "Node hierarchy:" << std::endl;
    
    BSTreeNode copy = BSTree::makeNode( *aBTree );

    std::cout << "c25:\t" << **copy << std::endl;
    std::cout << "n10:\t" << *(copy->left()) << std::endl;
    std::cout << "n15:\t" << *(copy->left().right()) << std::endl;
    std::cout << "n37:\t" << *(copy->right()) << std::endl;
    std::cout << "n30:\t" << *(copy->right().left()) << std::endl;
    std::cout << "n65:\t" << *(copy->right().right()) << std::endl;

    n10 = aBTree->detachLeft();
    n37 = aBTree->detachRight();
    n15 = n10->detachRight();
    n30 = n37->detachLeft();
    n65 = n37->detachRight();

    std::cout << "Detached nodes:" << std::endl;
    
    std::cout << "n25:\t" << **n25 << std::endl;
    std::cout << "n10:\t" << **n10 << std::endl;
    std::cout << "n15:\t" << **n15 << std::endl;
    std::cout << "n37:\t" << **n37 << std::endl;
    std::cout << "n30:\t" << **n30 << std::endl;
    std::cout << "n65:\t" << **n65 << std::endl;

    BSTreeNode move = BSTree::makeNode( std::move(*copy) );
    
    std::cout << "BTree test complete." << std::endl;
}

int main()
{
    testBTree();
    
    return 0;
}
