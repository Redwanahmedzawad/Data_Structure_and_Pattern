#include"CharacterCounter.h"

CharacterCounter::CharacterCounter()noexcept
{
	size_t i = 0;
	while (i < 256)
	{
		fCharacterCounts[i].setCharacter(static_cast<unsigned char>(i));
		i++;
	}
	fTotalNumberOfCharacters = 0;

}

void CharacterCounter::count(unsigned char aCharacter) noexcept
{
	
	fCharacterCounts[aCharacter].increment();
	fTotalNumberOfCharacters++;
	
		
}

const CharacterMap& CharacterCounter:: operator[](unsigned char aCharacter) const noexcept
{
	return fCharacterCounts[aCharacter];
}