
// COS30008, Midterm 2023

#pragma once

#include <string>
#include <cstdint>

#include "PrefixString.h"
#include "LZWTable.h"

class LZWCompressor
{
private:
	LZWTable fTable;
	PrefixString fW;
	std::string fInput;
	size_t fIndex;
	char fK;
	uint16_t fCurrentCode;

	bool readK() noexcept;
	void start();
	uint16_t nextCode();

public:

	LZWCompressor( const std::string& aInput );

	const uint16_t& operator*() const noexcept;

	LZWCompressor& operator++() noexcept;
	LZWCompressor operator++(int) noexcept;

	bool operator==( const LZWCompressor& aOther ) const noexcept;
	bool operator!=( const LZWCompressor& aOther ) const noexcept;

	LZWCompressor begin() const noexcept;
	LZWCompressor end() const noexcept;
};
