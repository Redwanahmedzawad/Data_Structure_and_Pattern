#pragma once
#include "Vector2d.h"
#define MAX_VERTICES 30
class Polygon
{
private:
	Vector2d fVertices[MAX_VERTICES];
	size_t fNumberOfVertices;
public:
	Polygon()noexcept;
	void readData(std::istream& aIStream);

	size_t getNumberOfVertices() const noexcept;
	const Vector2d& getVertex(size_t aIndex)const;
	float getPerimeter() const noexcept;

	Polygon scale(float aScalar)const noexcept;
};