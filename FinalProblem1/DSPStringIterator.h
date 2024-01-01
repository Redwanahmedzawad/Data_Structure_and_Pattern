
// COS30008, Final Exam, 2023

#pragma once

#include <memory>

#include "DSPString.h"

class DSPStringIterator
{
private:
	std::shared_ptr<DSPString> fCollection;
	int fIndex;

public:

	DSPStringIterator( const DSPString& aCollection );

	char operator*() const noexcept;

	DSPStringIterator& operator++() noexcept;
	DSPStringIterator operator++(int) noexcept;

	DSPStringIterator& operator--() noexcept;
	DSPStringIterator operator--( int ) noexcept;

	bool operator==( const DSPStringIterator& aOther ) const noexcept;
	bool operator!=( const DSPStringIterator& aOther ) const noexcept;

	DSPStringIterator begin() const noexcept;
	DSPStringIterator end() const noexcept;
	DSPStringIterator rbegin() const noexcept;
	DSPStringIterator rend() const noexcept;
};

