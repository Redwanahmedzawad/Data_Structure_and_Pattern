
// COS30008, Tutorial 6, 2023

#pragma once

#include <iostream>
#include <string>

class ResistorBase
{
private:
 
    // converts base value to unit value (object remains unchanged)
    // Example: the value of a register 56000.0 in unitless form becomes 56.0kOhm
    void convertBaseValueToUnitValue( double& aNormalizedValue,
                                      std::string& aUnit ) const noexcept;
    
    // converts unit value to base value (updates object)
    // Example: the value of a register 56.0kOhm becomes 56000.0 in unitless form
    void convertUnitValueToBaseValue( const double& aRawValue, const std::string& aRawUnit );

    // base value of a resistor component
    double fBaseValue;
    
protected:

    // auxiliary methods
    virtual bool mustScale( double aValue ) const noexcept = 0;
    virtual const double getMultiplier() const noexcept = 0;

    virtual const std::string getMajorUnit() const noexcept = 0;
    virtual const std::string getMinorUnits() const noexcept = 0;
    
    void setBaseValue( double aBaseValue ) noexcept;
    
public:
    
    // constructor with a default value
    ResistorBase( double aBaseValue = 0.0 ) noexcept;

    // required virtual destructor (implementation)
    virtual ~ResistorBase() {}

    // returns base value
    double getBaseValue() const noexcept;
    
    // returns (frequency-dependent) passive resistance value
    virtual double getReactance( double aFrequency = 0.0 ) const noexcept = 0;

    // returns (frequency-dependent) voltage drop
    double getPotentialAt( double aCurrent,
                           double aFrequency = 0.0 ) const noexcept;

    // returns (frequency-dependent) current flowing through a resistor
    double getCurrentAt( double aVoltage,
                         double aFrequency = 0.0 ) const noexcept;

    // resistor I/O
    friend std::istream& operator>>( std::istream& aIStream,
                                     ResistorBase& aObject );

    friend std::ostream& operator<<( std::ostream& aOStream,
                                     const ResistorBase& aObject );
};
