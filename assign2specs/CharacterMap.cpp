#include"CharacterMap.h"

CharacterMap::CharacterMap(unsigned char aCharacter , int aFrequency ) noexcept:
	
	fFrequency(aFrequency),
	fCharacter(aCharacter)
{
	
}

void CharacterMap::increment()noexcept
{
	fFrequency++;
}

void CharacterMap::setCharacter(unsigned char aCharacter) noexcept
{
	fCharacter = aCharacter;
}
unsigned char CharacterMap:: character() const noexcept
{
	return fCharacter;
}
size_t CharacterMap::frequency() const noexcept
{
	return fFrequency;
}

bool CharacterMap:: operator<(const CharacterMap& aOther) const noexcept
{
	return fFrequency < aOther.fFrequency;
}