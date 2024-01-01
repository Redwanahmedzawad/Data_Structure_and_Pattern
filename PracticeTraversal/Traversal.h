
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
    
    DepthFirstTraversal( const Node& aBtree ):
        fRoot(aBtree.get())
    {
        if (fRoot)
        {
            pushNode(fRoot);
        }
    }
    
    const T& operator*() const noexcept
    {
        return **fStack.top().node;
    }

    Iterator& operator++()
    {
        assert(!fStack.empty());
        BTree_ptr lTop = fStack.top().node;
        fStack.pop();
        if (lTop->hasRight())
        {
            pushNode(&lTop->right());
        }
        return *this;
    }
	
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);

        return old;
    }

    bool operator==(const Iterator& aOther) const noexcept
    {
        if (fRoot == aOther.fRoot && fStack.size() == aOther.fStack.size())
        {
            if (fStack.size() > 0)
            {
                return fStack.top() == fStack.top();
            }
            return true;
        }
        return false;
    }

    bool operator!=( const Iterator& aOther ) const noexcept
    {
        return !(*this == aOther);
    }

    Iterator begin() const noexcept
    {
        Iterator copy = *this;
        std::stack<Frontier>lEmpty;

        copy.fStack.swap(lEmpty);
        copy.pushNode(fRoot);
        return copy;
    }
    Iterator end() const noexcept
    {
        Iterator copy = *this;
        std::stack<Frontier>lEmpty;
        copy.fStack.swap(lEmpty);
        return copy;
    }

private:
    BTree_ptr fRoot;
    std::stack<Frontier> fStack;
    
    void pushNode(BTree_ptr aNode) noexcept
    {
        while (aNode)
        {
            fStack.push(aNode);
            if (aNode->hasLeft()) {
                aNode = &aNode->left();
            }
            else {
                aNode = nullptr;
            }
       }
    }
};

