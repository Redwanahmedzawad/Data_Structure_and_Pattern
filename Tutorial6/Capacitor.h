
// COS30008, Tutorial 6, 2023

#pragma once

#include "ResistorBase.h"

class Capacitor : public ResistorBase
{
protected:

    // auxiliary methods
    // aValue < 1.0
    bool mustScale( double aValue ) const noexcept override;
    // 1000.0
    const double getMultiplier() const noexcept override;
    // "F"
    const std::string getMajorUnit() const noexcept override;
    // minor units: "Fmunp", the first letter means "no major unit"
    const std::string getMinorUnits() const noexcept override;

public:

    // constructor with a default value
    Capacitor( double aBaseValue = 0.0 ) noexcept;

    // returns (frequency-dependent) passive resistance value
    double getReactance( double aFrequency = 0.0 ) const noexcept override;
};

