#include "LZWCompressor.h"
#include<iostream>
LZWCompressor::LZWCompressor(const std::string& aInput):
	fTable(),
	fW()
{
	
	fInput = aInput;
	fIndex = 0;
	fK = -1;
	fCurrentCode = 0;
	start();
}

bool LZWCompressor::readK()noexcept
{
	if (fIndex < fInput.size())
	{
		fK = fInput[fIndex++];
		return true;
	}
	fK = -1;
	return false;
}

void LZWCompressor::start()
{
	fTable.initialize();
	readK();
	fW = fTable.lookupStart(fK);
	
	//fW.setCode(fK);
	fCurrentCode = nextCode();
}

uint16_t LZWCompressor::nextCode()
{

	
	
	if(fK!=-1)
	{
		while (readK())
		{



			PrefixString lwK = fW + fK;
			if (fTable.contains(lwK))
			{
				fW = lwK;
			}
			else {
				uint16_t lResult = lwK.w();
				fTable.add(lwK);
				
				fW = fTable.lookupStart(lwK.K());
				//fW.setCode(fK);
				return lResult;
			}
			//std::cout << fCurrentCode;

			
		}
	}
	else {
		return -1;
	}
	
	 return fW.getCode();
	
	
}

const uint16_t& LZWCompressor::operator*()const noexcept
{
	return fCurrentCode;
}

LZWCompressor& LZWCompressor:: operator++()noexcept
{
	if (fK != -1)
	{
		fCurrentCode = nextCode();
	}
	else {
		fCurrentCode = -1;
	}
	
	return *this;

}

LZWCompressor LZWCompressor::operator++(int)noexcept
{
	LZWCompressor old = *this;
	++(*this);
	return old;
}

bool LZWCompressor:: operator==(const LZWCompressor& aOther)const noexcept
{
	return (fInput == aOther.fInput && fIndex == aOther.fIndex && fK == aOther.fK && fCurrentCode == aOther.fCurrentCode);
}

bool LZWCompressor:: operator!=(const LZWCompressor& aOther)const noexcept
{
	return !(*this == aOther);
}

LZWCompressor LZWCompressor::begin() const noexcept
{
	LZWCompressor Result = LZWCompressor(fInput);

	return Result;

}

LZWCompressor LZWCompressor::end()const noexcept
{
	LZWCompressor Result = *this;
	
	Result.fIndex = fInput.size();
	Result.fK = -1;
	Result.fCurrentCode = -1;
	return Result;
	

}