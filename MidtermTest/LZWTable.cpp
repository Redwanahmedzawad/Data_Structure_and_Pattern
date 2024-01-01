#include "LZWTable.h"

LZWTable::LZWTable(uint16_t aInitialCharacter)
{
	fInitialCharacters = aInitialCharacter;
	fIndex = 0;
	initialize();
}

void LZWTable::initialize()
{
	while (fIndex < 128)
	{
		fEntries[fIndex] = PrefixString(fIndex);
		fEntries[fIndex].setCode(fIndex);
		
		fIndex+=1;
	}

}

const PrefixString& LZWTable::lookupStart(char aK) const noexcept
{
	return fEntries[aK];
}

bool LZWTable::contains(PrefixString& aWK) const noexcept
{
	
	if (aWK.w() != -1)
	{
		
		for (uint16_t i = fIndex; i >= aWK.w(); i--)
		{
			if (fEntries[i] == aWK)
			{
				aWK = fEntries[i];
				return true;
			}

		}
	}
	return false;

}

void LZWTable::add(PrefixString& aWK)noexcept
{
	
	if (aWK.w() != -1)
	{
		
		aWK.setCode(fIndex);
		fEntries[fIndex++] = aWK;
		
		
		

	}

}