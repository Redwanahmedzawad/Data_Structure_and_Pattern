#include "PrefixString.h"
PrefixString::PrefixString(char aExtension) noexcept
{
	fCode = static_cast<uint16_t>(-1);
	fExtension = aExtension;
	fPrefix = static_cast<uint16_t>(-1);
}

PrefixString::PrefixString(uint16_t aPrefix, char aExtension) noexcept
{
	fCode = static_cast<uint16_t>(-1);
	fExtension = aExtension;
	fPrefix = aPrefix;
}

uint16_t PrefixString::getCode() const noexcept
{
	return fCode;
}

void PrefixString::setCode(uint16_t aCode)noexcept
{
	fCode = aCode;
}

PrefixString PrefixString:: operator+(char aExtension) const noexcept
{
	PrefixString lPrefix;
	if(fCode!=-1)
	{
		lPrefix.fPrefix = fCode;
		lPrefix.fCode = -1;
		lPrefix.fExtension = aExtension;
	}
	return lPrefix;
}

bool PrefixString:: operator==(const PrefixString& aOther) const noexcept
{
	if (fPrefix == aOther.fPrefix && fExtension == aOther.fExtension) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& aOStream, const PrefixString& aObject)
{
	return aOStream << "(" << aObject.fCode << "," << aObject.fPrefix << "," << aObject.fExtension << ")";
}