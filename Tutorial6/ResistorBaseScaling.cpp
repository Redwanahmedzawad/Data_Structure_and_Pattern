
// COS30008, Tutorial 6, 2023

#include "ResistorBase.h"

#include <stdexcept>

void ResistorBase::convertBaseValueToUnitValue( double& aNormalizedValue,
                                                std::string& aUnit ) const noexcept
{
    aNormalizedValue = getBaseValue();
    std::string lPrefixes = getMinorUnits();
    
    for ( size_t i = 0; i < lPrefixes.size(); i++ )
    {
        // stop scaling at maximum unit
        if ( mustScale( aNormalizedValue ) && (i < lPrefixes.size() - 1) )
        {
            aNormalizedValue *= getMultiplier();
        }
        else
        {
            if ( i > 0 )
            {
                aUnit += lPrefixes[i];
            }
            aUnit += getMajorUnit();
            break;
        }
    }
}

void ResistorBase::convertUnitValueToBaseValue( const double& aRawValue,
                                                const std::string& aRawUnit )
{
    std::string lMajorUnit = getMajorUnit();
    std::string lMinorUnits = getMinorUnits();

    // error handling
    // test basic features (raw unit too long and not containing major unit)
    if ( (aRawUnit.size() > lMajorUnit.size() + 1) ||
         (aRawUnit.find( getMajorUnit() ) == std::string::npos) )
    {
        throw std::invalid_argument( "Invalid unit specification" );
    }

    // test scale features, aRawUnit[0] must be contained in minor units
    if ( (aRawUnit.size() == lMajorUnit.size() + 1) &&
         lMinorUnits.find( aRawUnit[0] ) == std::string::npos )
    {
        throw std::invalid_argument( "Invalid unit scale specification" );
    }

    // adjust base value
    double lMultiplier = 1.0;
    
    size_t i = lMinorUnits.find( aRawUnit[0] );
    double lRawValue = aRawValue;

    // scale raw value first
    for ( ; i > 0 ; i-- )
    {
        if ( mustScale( lRawValue ) )
        {
            lRawValue /= getMultiplier();
        }
        else
        {
            break;
        }
    }

    // adjust multiplier
    for ( ; i > 0; i-- )
    {
        lMultiplier *= 1.0/getMultiplier();
    }

    setBaseValue( lRawValue * lMultiplier );
}
