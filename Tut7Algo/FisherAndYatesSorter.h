
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"

#include <cstdlib>
#include <ctime>

template<typename T>
class FisherAndYatesSorter : public BaseSorter<T>
{
private:
    
    void shuffle() noexcept;
	
    template<typename C>
    bool isSorted( C aIsOutOfOrder ) const noexcept;
    
public:
    
    FisherAndYatesSorter( T* aCollection = nullptr, size_t aSize = 0 );
        
    template<typename C = std::greater<T>>
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
};
