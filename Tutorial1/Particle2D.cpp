
// COS30008, 2023

#include "Particle2D.h"

using namespace std;

Particle2D::Particle2D( float aMass,
                        float aRadius,
                        const Vector2D& aPosition,
                        const Vector2D& aVelocity,
                        const Vector2D& aAcceleration ) noexcept :
    fMass(aMass),
    fRadius(aRadius),
    fPosition(aPosition),
    fVelocity(aVelocity),
    fAcceleration(aAcceleration)
{}

void Particle2D::applyAcceleration( const Vector2D& aAcceleration ) noexcept
{
    fAcceleration = fAcceleration + aAcceleration;
}

float Particle2D::direction() const noexcept
{
    return fVelocity.direction();
}

void Particle2D::align( float aAngleInDegrees ) noexcept
{
    fVelocity = fVelocity.align( aAngleInDegrees );
}

float Particle2D::speed() const noexcept
{
    return fVelocity.length();
}

void Particle2D::update() noexcept
{
    fVelocity = fVelocity + fAcceleration;
    fPosition = fPosition + fVelocity;
}

ostream& operator<<( ostream& aOStream, const Particle2D& aParticle )
{
    return
        aOStream
        << "Speed: " << aParticle.speed() << "\n"
        << "Direction: " << aParticle.direction() << "\n"
        << "Position: " << aParticle.position() << "\n";
}

