
// COS30008, Tutorial 6, 2023

#pragma once

#include "ResistorBase.h"

class PassiveResistor : public ResistorBase
{
protected:

    // auxiliary methods
    // aValue >= 1000.0
    bool mustScale( double aValue ) const noexcept override;
    // 1.0/1000.0
    const double getMultiplier() const noexcept override;
    // "Ohm"
    const std::string getMajorUnit() const noexcept override;
    // "OkM", the first letter means "no minor unit"
    const std::string getMinorUnits() const noexcept override;

public:

    // constructor with a default value
    PassiveResistor( double aBaseValue = 0.0 ) noexcept;

    // returns (frequency-independent) passive resistance value
    double getReactance( double aFrequency = 0.0 ) const noexcept override;
};

