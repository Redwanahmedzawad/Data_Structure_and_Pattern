
// COS30008, Tutorial 6, 2023

#include "PassiveResistor.h"

using namespace std;

// auxiliary methods
// aValue >= 1000.0
bool PassiveResistor::mustScale( double aValue ) const noexcept
{
    return aValue >= 1000.0;
}

// 1.0/1000.0
const double PassiveResistor::getMultiplier() const noexcept
{
    return 1.0/1000.0; // 0.001
}

// "Ohm"
const string PassiveResistor::getMajorUnit() const noexcept
{
    return "Ohm";
}

// "OkM", the first letter means "no minor unit"
const string PassiveResistor::getMinorUnits() const noexcept
{
    return "OkM";
}

// constructor with a default value
PassiveResistor::PassiveResistor( double aBaseValue ) noexcept :
    ResistorBase( aBaseValue )
{}

// returns (frequency-independent) passive resistance value
double PassiveResistor::getReactance( double aFrequency ) const noexcept
{
    return getBaseValue();
}

