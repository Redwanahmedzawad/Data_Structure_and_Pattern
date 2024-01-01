
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"

template<typename T>
class BubbleSorter : public BaseSorter<T>
{
public:
    
    BubbleSorter( T* aCollection = nullptr, size_t aSize = 0 ) :
        BaseSorter<T>( aCollection, aSize )
    {}
        
    template<typename C = std::greater<T>>
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
    {
        size_t t = this->size() - 1;
        
        while ( t > 0 )
        {
            size_t BOUND = t;
            
            t = 0;
            
            for ( size_t j = 0; j < BOUND; j++ )
            {
                if ( aIsOutOfOrder( (*this)[j], (*this)[j+1] ) )
                {
                    this->swap( j, j + 1 );
                    t = j;
                }
            }
            
            if ( aPrintStage )
            {
                this->printStage( 2 );
            }
        }
    }
};
