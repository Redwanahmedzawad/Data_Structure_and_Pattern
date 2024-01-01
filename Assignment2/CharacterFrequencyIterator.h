
// COS30008, Problem Set 2, 2023

#pragma once

#include "CharacterCounter.h"

class CharacterFrequencyIterator
{
private:
    const CharacterCounter* fCollection;
    size_t fIndex;
    unsigned char fMappedIndices[256];
    
    void mapIndices() noexcept;

public:
    
    CharacterFrequencyIterator( const CharacterCounter* aCollection ) noexcept;
    
    const CharacterMap& operator*() const noexcept;
    
    CharacterFrequencyIterator& operator++() noexcept;
    CharacterFrequencyIterator operator++( int ) noexcept;
    
    bool operator==( const CharacterFrequencyIterator& aOther ) const noexcept;
    bool operator!=( const CharacterFrequencyIterator& aOther ) const noexcept;
    
    CharacterFrequencyIterator begin() const noexcept;
    CharacterFrequencyIterator end() const noexcept;
};
