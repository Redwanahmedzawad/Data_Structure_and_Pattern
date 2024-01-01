
// COS30008, Problem Set 2, 2023

#pragma once

#include "CharacterMap.h"

class CharacterCounter
{
private:
    size_t fTotalNumberOfCharacters;
    CharacterMap fCharacterCounts[256];

public:
    
    CharacterCounter() noexcept;

    void count( unsigned char aCharacter ) noexcept;

    const CharacterMap& operator[]( unsigned char aCharacter ) const noexcept;
};
