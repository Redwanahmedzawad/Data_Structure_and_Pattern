
// COS30008, Midterm 2023

#pragma once

#include <cstdint>

#include "PrefixString.h"

class LZWTable
{
private:
	PrefixString fEntries[1024];
	uint16_t fIndex;
	uint16_t fInitialCharacters;

public:
	
	LZWTable( uint16_t aInitialCharacters = 128 );

	void initialize();

	const PrefixString& lookupStart( char aK ) const noexcept;

	bool contains( PrefixString& aWK ) const noexcept;
	void add( PrefixString& aWK ) noexcept;
};

