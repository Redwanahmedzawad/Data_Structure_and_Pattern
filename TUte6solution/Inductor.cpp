
// COS30008, Tutorial 6, 2023

#define _USE_MATH_DEFINES     // must be defined before any #include

#include "Inductor.h"

#include <cmath>

using namespace std;

bool Inductor::mustScale( double aValue ) const noexcept
{
	return aValue < 1.0;
}

const double Inductor::getMultiplier() const noexcept
{
	return 1000.0;
}

const std::string Inductor::getMajorUnit() const noexcept
{
	return "H";
}

const std::string Inductor::getMinorUnits() const noexcept
{
	return "Hmunp";
}

Inductor::Inductor( double aBaseValue ) noexcept:
	ResistorBase( aBaseValue )
{}

double Inductor::getReactance( double aFrequency ) const noexcept
{
	// PI = 4.0 * atan( 1.0 )
	// w = 2PIf
	// wL
	return (2 * M_PI * aFrequency) * getBaseValue();
}
