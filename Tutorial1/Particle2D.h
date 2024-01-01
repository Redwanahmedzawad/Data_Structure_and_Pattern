
// COS30008, 2023

#include <iostream>

#include "Vector2D.h"

class Particle2D
{
private:
    float fMass;
    float fRadius;
    Vector2D fPosition;
    Vector2D fVelocity;
    Vector2D fAcceleration;
    
public:

    explicit Particle2D( float aMass = 0.0f,
                         float aRadius = 10.0f,
                         const Vector2D& aPosition = Vector2D( 0.0f, 0.0f ),
                         const Vector2D& aVelocity = Vector2D( 0.0f, 0.0f ),
                         const Vector2D& aAcceleration = Vector2D( 0.0f, 0.0f ) ) noexcept;
    
    float mass() const noexcept { return fMass; }
    float radius() const noexcept { return fRadius; }
    const Vector2D& position() const noexcept { return fPosition; }
    const Vector2D& velocity() const noexcept { return fVelocity; }
    const Vector2D& acceleration() const noexcept { return fAcceleration; }

    void applyAcceleration( const Vector2D& aAcceleration ) noexcept;
    float direction() const noexcept;
    void align( float aAngleInDegrees ) noexcept;
    float speed() const noexcept;

    void update() noexcept;
    
    friend std::ostream& operator<<( std::ostream& aOStream, const Particle2D& aParticle );
};
