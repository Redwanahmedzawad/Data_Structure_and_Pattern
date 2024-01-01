
// COS30008, Tutorial 12, 2023

#include <iostream>

#include "BTree.h"
#include "Traversal.h"

void testInOrder()
{
    using BSTree = BTree<size_t>;
    using BSTreeNode = typename BSTree::Node;

    BSTreeNode n25 = BSTree::makeNode(25);
    BSTreeNode n10 = BSTree::makeNode(10);
    BSTreeNode n15 = BSTree::makeNode(15);
    BSTreeNode n37 = BSTree::makeNode(37);
    BSTreeNode n30 = BSTree::makeNode(30);
    BSTreeNode n65 = BSTree::makeNode(65);

    n37->attachLeft(n30);
    n37->attachRight(n65);
    n10->attachRight(n15);
    n25->attachLeft(n10);
    n25->attachRight(n37);

    const BSTreeNode& aBTree = n25;
    
    std::cout << "In-Order Traversal:";
    
    for ( auto& s : DepthFirstTraversal<size_t>(aBTree) )
    {
        std::cout << ' ' << s;
    }

    std::cout << std::endl;
}

int main()
{
    testInOrder();
    
    return 0;
}
