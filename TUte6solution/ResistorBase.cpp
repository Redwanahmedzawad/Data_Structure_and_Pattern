
// COS30008, Tutorial 6, 2023

#include "ResistorBase.h"

using namespace std;

void ResistorBase::setBaseValue( double aBaseValue ) noexcept
{
    fBaseValue = aBaseValue;
}

ResistorBase::ResistorBase( double aBaseValue ) noexcept
{
    setBaseValue( aBaseValue );
}

// returns base value
double ResistorBase::getBaseValue() const noexcept
{
    return fBaseValue;
}

// returns (frequency-dependent) voltage drop
double ResistorBase::getPotentialAt( double aCurrent, double aFrequency ) const noexcept
{
    // V = R * I
    
    return getReactance( aFrequency ) * aCurrent;
}

// returns (frequency-dependent) current flowing through a resistor
double ResistorBase::getCurrentAt( double aVoltage, double aFrequency ) const noexcept
{
    // I = V / R
    
    return aVoltage / getReactance( aFrequency );
}

// resistor I/O
istream& operator>>( istream& aIStream, ResistorBase& aObject )
{
    double lRawValue;
    string lRawUnit;
    
    aIStream >> lRawValue >> lRawUnit;
    
    aObject.convertUnitValueToBaseValue( lRawValue, lRawUnit );
    
    return aIStream;
}

ostream& operator<<( ostream& aOStream, const ResistorBase& aObject )
{
    double lNormalizeValue;
    string lNormalizedUnit;
    
    aObject.convertBaseValueToUnitValue( lNormalizeValue, lNormalizedUnit );
    
    aOStream << lNormalizeValue << lNormalizedUnit;
    
    return aOStream;
}
