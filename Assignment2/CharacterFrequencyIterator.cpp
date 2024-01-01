#include "CharacterFrequencyIterator.h"
#include<algorithm>
void CharacterFrequencyIterator::mapIndices() noexcept
{
	for (size_t i = 0; i < 256; i++)
	{
		fMappedIndices[i]=static_cast<unsigned char>(i);
	}
	size_t i = 0;
	while (i < 256)
	{
		size_t j = i+1;
		while (j > 0 && (*fCollection)[fMappedIndices[j-1]] < (*fCollection)[fMappedIndices[j]])
		{
			std::swap(fMappedIndices[j - 1], fMappedIndices[j]);
			
			j--;
		}
		i++;
	}
}


CharacterFrequencyIterator::CharacterFrequencyIterator (const CharacterCounter* aCollection)noexcept:
	fCollection(aCollection),
	fIndex()
	
{
	mapIndices();
}

const CharacterMap& CharacterFrequencyIterator::operator*()const noexcept
{
	return (*fCollection)[fMappedIndices[fIndex]];
}

CharacterFrequencyIterator& CharacterFrequencyIterator::operator++()noexcept
{
	fIndex++;
	if ((*fCollection)[fMappedIndices[fIndex]].frequency()==0)
	{
		fIndex = 256;
	}
	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator:: operator++(int)noexcept
{
	CharacterFrequencyIterator old = *this;
	++(*this);
	if ((*fCollection)[fMappedIndices[fIndex]].frequency() == 0)
	{
		fIndex = 256;
	}
	return old;
}

bool CharacterFrequencyIterator:: operator==(const CharacterFrequencyIterator& aOther) const noexcept
{
	return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool CharacterFrequencyIterator:: operator !=(const CharacterFrequencyIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

CharacterFrequencyIterator CharacterFrequencyIterator::begin()const noexcept
{
	CharacterFrequencyIterator Result = *this;
	Result.fIndex = 0;
	return Result;
}

CharacterFrequencyIterator CharacterFrequencyIterator::end() const noexcept
{
	CharacterFrequencyIterator Result = *this;
	Result.fIndex = 256;
	return Result;
}