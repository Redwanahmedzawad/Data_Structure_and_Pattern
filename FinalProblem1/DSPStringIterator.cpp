
// COS30008, Final Exam, 2023

#include "DSPStringIterator.h"

DSPStringIterator::DSPStringIterator( const DSPString& aCollection ) :
	fCollection( std::make_shared<DSPString>( aCollection ) ),
	fIndex( 0 )
{}

char DSPStringIterator::operator*() const noexcept
{
	// 4A
	return (*fCollection)[fIndex];
}

DSPStringIterator& DSPStringIterator::operator++() noexcept
{
	// 4B
	
		fIndex++;
	
	return *this;
}

DSPStringIterator DSPStringIterator::operator++( int ) noexcept
{
	DSPStringIterator old = *this;

	++(*this);

	return old;
}

DSPStringIterator& DSPStringIterator::operator--() noexcept
{
	// 4C
	
		--fIndex;
	
	return *this;
}

DSPStringIterator DSPStringIterator::operator--( int ) noexcept
{
	DSPStringIterator old = *this;

	--(*this);

	return old;
}

bool DSPStringIterator::operator==( const DSPStringIterator& aOther ) const noexcept
{
	// 4D
	
	return (fCollection == aOther.fCollection && fIndex == aOther.fIndex);
}

bool DSPStringIterator::operator!=( const DSPStringIterator& aOther ) const noexcept
{
	return !(*this == aOther);
}

DSPStringIterator  DSPStringIterator::begin() const noexcept
{
	// 4E
	return DSPStringIterator(*fCollection);
}

DSPStringIterator DSPStringIterator::end() const noexcept
{
	// 4F
	DSPStringIterator temp(*fCollection);
	temp.fIndex = fCollection->size();
	return temp;
}

DSPStringIterator DSPStringIterator::rbegin() const noexcept
{
	// 4G
	DSPStringIterator temp(*fCollection);
	temp.fIndex = fCollection->size() - 1;
	return temp;
}

DSPStringIterator DSPStringIterator::rend() const noexcept
{
	// 4H
	DSPStringIterator temp(*fCollection);
	temp.fIndex = -1;
	return temp;
}
