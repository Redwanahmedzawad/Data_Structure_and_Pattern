
// COS30008, Problem Set 2, 2023

#pragma once

#include <cstddef>

class CharacterMap
{
private:
    unsigned char fCharacter;
    size_t fFrequency;
    
public:

    // constructor with default arguments, it becomes a default constructor
    CharacterMap( unsigned char aCharacter = '\0', int aFrequency = 0 ) noexcept;

    void increment() noexcept;
    void setCharacter( unsigned char aCharacter ) noexcept;

    bool operator<( const CharacterMap& aOther ) const noexcept;
        
    unsigned char character() const noexcept;
    size_t frequency() const noexcept;
};
