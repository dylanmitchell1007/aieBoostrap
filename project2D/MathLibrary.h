#pragma once
#pragma once
#include <iostream>		
#include <Windows.h>
#include <math.h>
#include "Application2D.h"

using namespace std;

class Vector2
{
public:
	Vector2() {};
	Vector2(float xx, float yy);


	void Add(Vector2 var);
	
	void Sub(Vector2 var);

	void mult(float var);



	Vector2 operator+(const Vector2 & add) const;

	
	Vector2 operator - (const Vector2& sub)const;


	Vector2 operator * (const float& mult)const;


	bool operator == (const Vector2&equals);


	float magnitude();


	Vector2 Normalize();


	float DotProd(Vector2 thing);


	float getY();


	float getX();
	




	float vec_x;
	float vec_y;
	void Add();
};

class Vector3
{
public:
	Vector3() {};
	Vector3(float xxx, float yyy, float zzz);



	Vector3 operator + (const Vector3& add)const;

	Vector3 operator - (const Vector3& sub)const;

	Vector3 operator * (const float& mult)const;
	
	bool operator == (const Vector3&equals);


	float magnitude();

	Vector3 Normalize();

	float DotProd(Vector3 thing);


	Vector3 Cross(Vector3 cross);

private:
	float vec_x;
	float vec_y;
	float vec_z;

};

class Vector4
{
public:
	Vector4() {};
	Vector4(float xxx, float yyy, float zzz, float www);


	Vector4 operator + (const Vector4& add)const;

	Vector4 operator - (const Vector4& sub)const;

	Vector4 operator * (const float& mult)const;

	bool operator == (const Vector4&equals);


	float magnitude();


	Vector4 Normalize();
	
		

	float DotProd(Vector4 thing);




	float vec_x;
	float vec_y;
	float vec_z;
	float vec_w;


};

class Matrix2
{
public:
	Matrix2() {}
	Matrix2(float x1, float x2, float y1, float y2);
	

	Vector2 operator*(Vector2 &vec2)const;

	Matrix2 operator *(const Matrix2& mult) const;
	

private:
	float m_x1;
	float m_x2;
	float m_y1;
	float m_y2;
};

class Matrix3
{
public:
	Matrix3() {}
	Matrix3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3);

	Matrix3 operator *(const Matrix3& mult) const;
	

private:
	float m_x1;
	float m_x2;
	float m_x3;

	float m_y1;
	float m_y2;
	float m_y3;

	float m_z1;
	float m_z2;
	float m_z3;
};

class Matrix4
{
public:
	Matrix4() {}
	Matrix4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4);

	Matrix4 operator *(const Matrix4& mult) const;

private:
	float m_x1;
	float m_x2;
	float m_x3;
	float m_x4;

	float m_y1;
	float m_y2;
	float m_y3;
	float m_y4;

	float m_z1;
	float m_z2;
	float m_z3;
	float m_z4;

	float m_w1;
	float m_w2;
	float m_w3;
	float m_w4;
};
