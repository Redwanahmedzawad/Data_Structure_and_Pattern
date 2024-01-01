
// COS30008, Final Exam, 2023

#pragma once

#include <memory>
#include <cassert>
#include <algorithm>

template<typename T>
class TernaryTree
{
public:
    
    using Node = std::unique_ptr<TernaryTree>;

public:

    TernaryTree( const T& aKey = T{} ) noexcept:
        fKey(aKey)
    {
    }
    TernaryTree(T&& aKey) noexcept :
        fKey(std::move(aKey))
    {

    }

    template<typename... Args>
    static Node makeNode(Args&&... args)
    {
        return std::make_unique<TernaryTree>(std::forward<Args>(args)...);
    }

    const T& operator*() const noexcept
    {
        return fKey;
    }

    TernaryTree& operator[](size_t aIndex) const
    {
        assert(aIndex < 3 && fNodes[aIndex]);
        return *fNodes[aIndex];
    }

    void add(size_t aIndex, Node& aNode)
    {
        assert(aIndex < 3&& !fNodes[aIndex]);
        fNodes[aIndex] = std::move(aNode);
    }
    Node remove(size_t aIndex)
    {
        assert(aIndex < 3 &&fNodes[aIndex]);

        return std::move(fNodes[aIndex]);
    }

    bool leaf() const noexcept
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (fNodes[i])
            {
                return false;
            }
        }
        return true;
    }
    size_t height() const noexcept
    {
        
        size_t Result = 0;
        if (!leaf()) {
            for (size_t i = 0; i < 3; i++)
            {
                if (fNodes[i])
                {
                    Result = std::max(Result, fNodes[i]->height() + 1);
                }
            }
        }
        return Result;
    }

private:

    T fKey;
    Node fNodes[3];
};

