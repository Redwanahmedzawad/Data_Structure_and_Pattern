#include"Polygon.h"
#include <cassert>

Polygon::Polygon()noexcept :
	fNumberOfVertices(0)
{}
size_t Polygon::getNumberOfVertices()const noexcept
{
	return fNumberOfVertices;
}
const Vector2d& Polygon::getVertex(size_t aIndex)const
{
	assert(aIndex < fNumberOfVertices);
	return fVertices[aIndex];
}
void Polygon::readData(std::istream& aIstream) 
{
	while (aIstream >> fVertices[fNumberOfVertices]) {
		fNumberOfVertices++;
	}
}
float Polygon::getPerimeter()const noexcept
{
	float segment = 0.0f;
	if (fNumberOfVertices > 2) 
	{
		for (int i = 0; i < fNumberOfVertices - 1; i++)
		{

			segment += fVertices[i + 1].length() - fVertices[i].length();

		}
		segment += (fVertices[0] - fVertices[fNumberOfVertices - 1]).length();
	}
	return segment;

}
Polygon Polygon::scale(float aScalar)const noexcept
{
	Polygon Result = *this;
	for (size_t i = 0; i < fNumberOfVertices; i++)
	{
		Result.fVertices[i] = fVertices[i].operator*(aScalar);

	}
	return Result;
}