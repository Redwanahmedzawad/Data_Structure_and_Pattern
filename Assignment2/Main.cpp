
// COS30008, Problem Set 2, 2023

#include <iostream>

#define P1
#define P2
#define P3

#ifdef P1

#include "CharacterMap.h"

void testP1()
{
    CharacterMap lMapA;
    CharacterMap lMapB;

    std::cout << "Test CharacterMap" << std::endl;
    
    std::cout
        << "Initial: " << static_cast<int>(lMapA.character())
        << " - " << lMapA.frequency() << std::endl;
    
    lMapA.setCharacter( 'S' );
    lMapA.increment();
    lMapA.increment();
    
    std::cout
        << "After updates: " << lMapA.character()
        << " - " << lMapA.frequency() << std::endl;

    std::cout << "lMapA < lMapB: " << (lMapA < lMapB ? "true" : "false") << std::endl;

    std::cout << "Test CharacterMap complete." << std::endl;
}

#endif

#ifdef P2

#include <fstream>

#include "CharacterCounter.h"

void testP2( std::istream& aInput )
{
    CharacterCounter lCounter;
    unsigned char lChar;

    std::cout << "Test CharacterCounter" << std::endl;

    while ( aInput >> lChar )
    {
        lCounter.count( lChar );
    }

    std::cout << "The frequencies: " << std::endl;

    for ( size_t i = 0; i < 256; i++ )
    {
        const CharacterMap& lMap = lCounter[static_cast<unsigned char>(i)];
        
        if ( lMap.frequency() != 0 )
        {
            std::cout << lMap.character() << ": " << lMap.frequency() << std::endl;
        }
    }
    
    std::cout << "Test CharacterCounter complete." << std::endl;
}

#endif

#ifdef P3

#include <fstream>

#include "CharacterCounter.h"
#include "CharacterFrequencyIterator.h"

void testP3( std::istream& aInput )
{
    CharacterCounter lCounter;
    unsigned char lChar;
    
    std::cout << "Test CharacterCounterIterator" << std::endl;

    while ( aInput >> lChar )
    {
        lCounter.count( lChar );
    }

    std::cout << "The frequencies: " << std::endl;

    for ( const auto& item : CharacterFrequencyIterator( &lCounter ) )
    {
        std::cout << item.character() << ": " << item.frequency() << std::endl;
    }

    std::cout << "Test CharacterCounterIterator complete." << std::endl;
}

#endif

int main( int argc, char* argv[] )
{

#ifdef P1
    
    testP1();
    
#endif

#ifdef P2
        
    if ( argc < 2 )
    {
        std::cerr << "Argumens missing" << std::endl;
        std::cerr << "Usage: PS2 <infile>" << std::endl;
            
        return 1;
    }
        
    std::ifstream lInputA( argv[1], std::ifstream::in );
        
    if ( !lInputA )
    {
        std::cerr << "Cannot open input file: " << argv[1] << std::endl;
            
        return 2;
    }
        
    testP2( lInputA );

#endif

#ifdef P3
    
    if ( argc < 2 )
    {
        std::cerr << "Argumens missing" << std::endl;
        std::cerr << "Usage: PS2 <infile>" << std::endl;
        
        return 1;
    }
    
    std::ifstream lInputB( argv[1], std::ifstream::in );
    
    if ( !lInputB )
    {
        std::cerr << "Cannot open input file: " << argv[1] << std::endl;
        
        return 2;
    }
    
    testP3( lInputB );

#endif
    
    return 0;
}
