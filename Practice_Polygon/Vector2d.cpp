#define _USE_MATH_DEFINES
#include "Vector2d.h"

#include<cmath>

Vector2d::Vector2d(float aX, float aY)noexcept :

	fX(aX),
	fY(aY)
{}

Vector2d Vector2d::operator+(const Vector2d& aOther) const noexcept
{
	return Vector2d(x() + aOther.x(), y() + aOther.y());
}

Vector2d Vector2d::operator-(const Vector2d& aOther)const noexcept
{
	return(x() - aOther.x(), y() - aOther.y());
}

Vector2d Vector2d::operator*(const float aScalar)const noexcept
{
	return (x() * aScalar, y() * aScalar);
}
float Vector2d::dot(const Vector2d& aOther) const noexcept
{
	return((x() * aOther.x()) + (y() * aOther.y()));
}
float Vector2d::cross(const Vector2d& aOther)const noexcept
{
	return (x() * aOther.y() - y() * aOther.x());
}
float Vector2d::length()const noexcept
{
	return sqrt(x() * x() + y() * y());
}

Vector2d Vector2d::normalize()const noexcept
{
	return *this * (1.0f/length());
}

float Vector2d::direction()const noexcept
{
	float val = std::atan2(y(), x()) * 180 / static_cast<float>(M_PI);
	return std::round(val * 100.0f) / 100.0f;

}

Vector2d Vector2d::align(float aAngleInDegrees)const noexcept
{
	float lRadians = aAngleInDegrees * static_cast<float>(M_PI)/180.0f;
	return length() * Vector2d(std::cos(lRadians), std::sin(lRadians));
}
std::istream& operator>>(std::istream& aIstream, Vector2d& aVector)
{
	return aIstream >> aVector.fX >> aVector.fY;
}

std::ostream& operator<<(std::ostream& aOStream, const Vector2d& aVector) noexcept
{
	return aOStream << "[" << round(aVector.fX) << "," << round(aVector.fY)<<"]"<<std::endl;
}
Vector2d operator*(const float aScalar, const Vector2d& aVector)noexcept
{
	return aVector * aScalar;
}