
// COS30008, Midterm 2023

#pragma once

#include <cstdint>
#include <ostream>

class PrefixString
{
private:
	uint16_t fCode;
	uint16_t fPrefix;
	char fExtension;

public:
	PrefixString( char aExtension = '\0' ) noexcept;
	PrefixString( uint16_t aPrefix, char aExtension ) noexcept;

	uint16_t getCode() const noexcept;
	void setCode( uint16_t aCode ) noexcept;

	uint16_t w() const noexcept {return fPrefix;};
	char K() const noexcept { return fExtension; };

	PrefixString operator+( char aExtension ) const noexcept;
	bool operator==( const PrefixString& aOther ) const noexcept;

	friend std::ostream& operator<<( std::ostream& aOStream, const PrefixString& aObject );
};
