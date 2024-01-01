#include"Polygon.h"
#include"Matrix3x3.h"
#include"Vector3D.h"

float Polygon::getSignedArea()const noexcept
{
	float lSum = 0.0f;
	
	for (size_t i = 0; i < getNumberOfVertices()-1; i++)
	{
		lSum+= .5f*(getVertex(i).y()+getVertex(i+1).y()) * (getVertex(i).x()-getVertex(i+1).x());
		
	}
	lSum += .5f*(getVertex(getNumberOfVertices()-1).y() + getVertex(0).y()) * (getVertex(getNumberOfVertices()-1).x() - getVertex(0).x());
	
	return lSum;
}

Polygon Polygon::transform(const Matrix3x3& aMatrix)const noexcept
{
	Polygon Result = *this;
	Vector3D lTrans;
	for (size_t i = 0; i < getNumberOfVertices(); i++)
	{
		lTrans = Vector3D(getVertex(i));
		lTrans = aMatrix * (lTrans);
		Result.fVertices[i] = lTrans.operator Vector2D();
	}
	return Result;
}