
// COS30008, Tutorial 12, 2023

#pragma once

#include "BTree.h"

#include <stack>
#include <memory>

template<typename T>
class DepthFirstTraversal
{
public:
    using BTree_ptr = const BTree<T>*;
    using Iterator = DepthFirstTraversal<T>;
    using Node = typename BTree<T>::Node;

    struct Frontier
    {
        bool mustExploreRight;
        BTree_ptr node;
        
        Frontier( BTree_ptr aNode = nullptr ) :
            mustExploreRight(true),
            node(aNode)
        {}
        
        bool operator==( const Frontier& aOther ) const noexcept
        {
            return
                mustExploreRight == aOther.mustExploreRight &&
                node == aOther.node;
        }
    };
    
    DepthFirstTraversal(const Node& aBtree):
        fRoot(aBtree)
    {
        pushNode(fRoot);
    }
    
    const T& operator*() const noexcept
    {
        return fStack.top();
    }

    Iterator& operator++();
	
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);

        return old;
    }

    bool operator==( const Iterator& aOther ) const noexcept;

    bool operator!=( const Iterator& aOther ) const noexcept
    {
        return !(*this == aOther);
    }

    Iterator begin() const noexcept;
    Iterator end() const noexcept;

private:
    BTree_ptr fRoot;
    std::stack<Frontier> fStack;
    
    void pushNode(BTree_ptr aNode) noexcept
    {
        while (aNode)
        {
            fStack.push(aNode);
            if (aNode->hasLeft())
            {
                aNode = &aNode->left();
            }
            else
            {
                fStack.top().mustExploreRight = false;
                if (aNode->hasRight())
                {
                    aNode = &aNode->right();
                    continue;
                }
                
            }
            aNode = nulllptr;
        }
    }
};

