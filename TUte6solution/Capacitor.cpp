
// COS30008, Tutorial 6, 2023

#define _USE_MATH_DEFINES     // must be defined before any #include

#include "Capacitor.h"
#include <cmath>

using namespace std;

// auxiliary methods
// aValue >= 1000.0
bool Capacitor::mustScale( double aValue ) const noexcept
{
    return aValue < 1.0;
}

// 1.0/1000.0
const double Capacitor::getMultiplier() const noexcept
{
    return 1000.0;
}

// "Ohm"
const string Capacitor::getMajorUnit() const noexcept
{
    return "F";
}

// "OkM", the first letter means "no minor unit"
const string Capacitor::getMinorUnits() const noexcept
{
    return "Fmunp";
}

// constructor with a default value
Capacitor::Capacitor( double aBaseValue ) noexcept :
    ResistorBase( aBaseValue )
{}

// returns (frequency-independent) passive resistance value
double Capacitor::getReactance( double aFrequency ) const noexcept
{
    return 1.0 /(2.0 * M_PI * aFrequency * getBaseValue());
}
