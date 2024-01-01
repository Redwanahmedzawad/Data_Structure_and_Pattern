
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"

template<typename T>
class BubbleSorter : public BaseSorter<T>
{
public:
    
    BubbleSorter( T* aCollection = nullptr, size_t aSize = 0 );
        
    template<typename C = std::greater<T>>
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
};
