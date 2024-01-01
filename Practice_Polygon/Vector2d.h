#pragma once
#include <iostream>
class Vector2d
{
private:
	float fX;
	float fY;
public:
	Vector2d(float aX = 1.0f, float aY = 0.0f)noexcept;
	Vector2d(std::istream& aIStream) :Vector2d() { aIStream>>*this; }

	float x()const noexcept { return fX; }
	float y()const noexcept { return fY; }

	Vector2d operator+(const Vector2d& aOther) const noexcept;
	Vector2d operator-(const Vector2d& aOther) const noexcept;

	Vector2d operator*(const float aScalar)const noexcept;
	float dot(const Vector2d& aOther) const noexcept;
	float cross(const Vector2d& aOther)const noexcept;
	
	float length() const noexcept;
	Vector2d normalize()const noexcept;

	float direction()const noexcept;
	Vector2d align(float aAngleInDegrees)const noexcept;

	friend std::istream& operator>>(std::istream& aIStream, Vector2d& aVector);
	friend std::ostream& operator<<(std::ostream& aOStream, const Vector2d& aVector);

};
Vector2d operator*(const float aScalar, const Vector2d& aVector)noexcept;