
// COS30008, Midterm 2023

#include <iostream>

#define P1
#define P2
#define P3

#ifdef P1

#include "PrefixString.h"

void runP1()
{
	std::cout << "Test PrefixString:\n" << std::endl;

	PrefixString lString0;
	PrefixString lStringA( 'a' );
	PrefixString lStringB( 'b' );
	PrefixString lStringAB( 97, 'b' );
	PrefixString lStringBA( 98, 'a' );

	lStringA.setCode( 97 );
	lStringB.setCode( 98 );
	lStringAB.setCode( 127 );
	lStringBA.setCode( 128 );

	std::cout 
		<< "0 string ::= "
		<< "code= " << lString0.getCode()
		<< ", w = " << lString0.w()
		<< ", K = " << lString0.K() << std::endl;

	std::cout
		<< "A string ::= "
		<< "code= " << lStringA.getCode()
		<< ", w = " << lStringA.w()
		<< ", K = " << lStringA.K() << std::endl;

	std::cout
		<< "BA string ::= "
		<< "code= " << lStringBA.getCode()
		<< ", w = " << lStringBA.w()
		<< ", K = " << lStringBA.K() << std::endl;

	PrefixString lW = lStringB + 'a';

	std::cout << "lW == lStringBA? ";
	std::cout << (lW == lStringBA ? "true" : "false") << std::endl;

	if ( lW == lStringBA )
	{
		lW.setCode( lStringBA.getCode() );
	}
	else
	{
		lW.setCode( 129 );
	}

	std::cout << "All strings:" << std::endl;
	std::cout << "lString0 = " << lString0 << std::endl;
	std::cout << "lStringA = " << lStringA << std::endl;
	std::cout << "lStringB = " << lStringB << std::endl;
	std::cout << "lStringAB = " << lStringAB << std::endl;
	std::cout << "lStringBA = " << lStringBA << std::endl;
	std::cout << "lW = " << lW << std::endl;

	std::cout << "\nPrefixString test complete." << std::endl;
}

#endif

#ifdef P2

#include "LZWTable.h"

void runP2()
{
	std::cout << "Test LZW Table:\n" << std::endl;

	LZWTable lTable ( 456 );

	lTable.initialize();

	std::cout << "LZW Table contains 128 entries." << std::endl;
	std::cout << "Next available index is 128." << std::endl;

	PrefixString lA = lTable.lookupStart( 'a' );
	
	std::cout << "lA = " << lA << std::endl;

	PrefixString lW_1 = lA + 'b';

	std::cout << "Is lW_1 = " << lW_1 << " in LZW table? ";

	if ( lTable.contains( lW_1 ) )
	{
		std::cout << "Yes." << std::endl;
		std::cout << "lW_1 = " << lW_1 << std::endl;
	}
	else
	{
		std::cout << "No." << std::endl;
		lTable.add( lW_1 );
		std::cout << "lW_1 = " << lW_1 << std::endl;
	}

	PrefixString lW_2 = lA + 'b';

	std::cout << "Is lW_2 = " << lW_2 << " in LZW table? ";

	if ( lTable.contains( lW_2 ) )
	{
		std::cout << "Yes." << std::endl;
		std::cout << "lW_2 = " << lW_2 << std::endl;
	}
	else
	{
		std::cout << "No." << std::endl;
		lTable.add( lW_2 );
		std::cout << "lW_2 = " << lW_2 << std::endl;
	}

	std::cout << "\nLZWTable test complete." << std::endl;
}

#endif

#ifdef P3

#include "LZWCompressor.h"

void runP3()
{
	std::string lInput = "ababcbababaaaaaaa";
	size_t lCount = 0;

	// Output: 97 98 128 99 129 132 97 134 135 97

	std::cout << "Test LZW Compression:\n" << std::endl;
	std::cout << "Input String:" << lInput << std::endl;
	std::cout << "LZW Codes:" << std::endl;

	for ( const auto& item : LZWCompressor( lInput ) )
	{
		std::cout << item << std::endl;

		lCount++;
	}

	float lUncompressedSize = 8.0f * lInput.size();
	float lCompressedSize = 10.0f * lCount;
	float lOverhead = static_cast<float>((10 * lCount) % 8);
	float lCompressionRatio = lUncompressedSize / lCompressedSize;
	float lSaving = (1.0f - ((lCompressedSize + lOverhead) / lUncompressedSize)) * 100.0f;

	std::cout << "\nCompression Ratio: " << lCompressionRatio << "/1" << std::endl;
	std::cout << "Overhead in Bits: " << lOverhead << std::endl;
	std::cout << "Space Saving: " << lSaving << "%" << std::endl;
	std::cout << "\nLZW Compression test complete." << std::endl;
}

#endif

int main( int argc, const char* argv[] )
{

#ifdef P1

	runP1();

#endif

#ifdef P2

	runP2();

#endif

#ifdef P3

	runP3();

#endif
    
#ifndef P1
    #ifndef P2
        #ifndef P3
    
    std::cout << "No Test enabled."  << std::endl;
    
        #endif
    #endif
#endif

	return 0;
}
