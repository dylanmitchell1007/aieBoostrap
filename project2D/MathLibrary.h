#pragma once
#pragma once
#include <iostream>		
#include <Windows.h>
#include <math.h>
#include "Application2D.h"
#include "MathLibrary.h"
using namespace std;

class Vector2
{
public:
	Vector2() {};
	Vector2(float xx, float yy)
	{
		vec_x = xx;
		vec_y = yy;
	}


	void Add(Vector2 var)
	{
		vec_x += var.vec_x;
		vec_y += var.vec_y;
	}
	void Sub(Vector2 var)
	{
		vec_x -= var.vec_x;
		vec_y -= var.vec_x;
	}
	void mult(float var)
	{
		vec_x *= var;
		vec_y *= var;
	}
	Vector2 operator + (const Vector2& add)const
	{
		Vector2 work;
		work.vec_x = vec_x + add.vec_x;
		work.vec_y = vec_y + add.vec_y;
		return work;
	}
	Vector2 operator - (const Vector2& sub)const
	{
		Vector2 work;
		work.vec_x = vec_x - sub.vec_x;
		work.vec_y = vec_y - sub.vec_y;
		return work;
	}
	Vector2 operator * (const float& mult)const
	{
		Vector2 work;
		work.vec_x = vec_x * mult;
		work.vec_y = vec_y * mult;
		return work;
	}
	bool operator == (const Vector2&equals)
	{
		return vec_x == equals.vec_x, vec_y == equals.vec_y;

	}
	float magnitude()
	{
		return sqrt((vec_x*vec_x) + (vec_y*vec_y));
	}


	Vector2 Normalize()
	{
		return Vector2(vec_x / magnitude(), vec_y / magnitude());


	}
	float DotProd(Vector2 thing)
	{
		return (vec_x*thing.vec_x) + (vec_y*thing.vec_y);
	}

	float getY()
	{
		return vec_y;
	}
	float getX()
	{
		return vec_x;
	}





private:
	float vec_x;
	float vec_y;
};

class Vector3
{
public:
	Vector3() {};
	Vector3(float xxx, float yyy, float zzz)
	{
		vec_x = xxx;
		vec_y = yyy;
		vec_z = zzz;
	}


	Vector3 operator + (const Vector3& add)const
	{
		Vector3 work;
		work.vec_x = vec_x + add.vec_x;
		work.vec_y = vec_y + add.vec_y;
		work.vec_z = vec_z + add.vec_z;
		return work;
	}
	Vector3 operator - (const Vector3& sub)const
	{
		Vector3 work;
		work.vec_x = vec_x - sub.vec_x;
		work.vec_y = vec_y - sub.vec_y;
		work.vec_z = vec_z - sub.vec_z;
		return work;
	}
	Vector3 operator * (const float& mult)const
	{
		Vector3 work;
		work.vec_x = vec_x * mult;
		work.vec_y = vec_y * mult;
		work.vec_z = vec_z * mult;
		return work;
	}
	bool operator == (const Vector3&equals)
	{
		return vec_x == equals.vec_x, vec_y == equals.vec_y, vec_z == equals.vec_z;

	}

	float magnitude()
	{
		return sqrt((vec_x*vec_x) + (vec_y*vec_y));
	}

	Vector3 Normalize()
	{
		return Vector3(vec_x / magnitude(), vec_y / magnitude(), vec_z / magnitude());
	}

	float DotProd(Vector3 thing)
	{
		return (vec_x*thing.vec_x) + (vec_y*thing.vec_y);


	}

	Vector3 Cross(Vector3 cross)
	{
		return Vector3(((vec_y*cross.vec_z) - (vec_z*cross.vec_y)), ((vec_x*cross.vec_z) - (vec_z*cross.vec_x)), ((vec_x*cross.vec_y) - (vec_y*cross.vec_x)));

	}

private:
	float vec_x;
	float vec_y;
	float vec_z;

};

class Vector4
{
public:
	Vector4() {};
	Vector4(float xxx, float yyy, float zzz, float www)
	{
		vec_x = xxx;
		vec_y = yyy;
		vec_z = zzz;
		vec_w = www;
	}


	Vector4 operator + (const Vector4& add)const
	{
		Vector4 work;
		work.vec_x = vec_x + add.vec_x;
		work.vec_y = vec_y + add.vec_y;
		work.vec_z = vec_z + add.vec_z;
		work.vec_w = vec_w + add.vec_x;
		return work;
	}
	Vector4 operator - (const Vector4& sub)const
	{
		Vector4 work;
		work.vec_x = vec_x - sub.vec_x;
		work.vec_y = vec_y - sub.vec_y;
		work.vec_z = vec_z - sub.vec_z;
		work.vec_w = vec_w - sub.vec_w;
		return work;
	}
	Vector4 operator * (const float& mult)const
	{
		Vector4 work;
		work.vec_x = vec_x * mult;
		work.vec_y = vec_y * mult;
		work.vec_z = vec_z * mult;
		work.vec_w = vec_w * mult;
		return work;
	}
	bool operator == (const Vector4&equals)
	{
		return vec_x == equals.vec_x, vec_y == equals.vec_y, vec_z == equals.vec_z, vec_w == equals.vec_w;

	}

	float magnitude()
	{
		return sqrt((vec_x*vec_x) + (vec_y*vec_y));
	}

	Vector4 Normalize()
	{
		return Vector4(vec_x / magnitude(), vec_y / magnitude(), vec_z / magnitude(), vec_w / magnitude());
	}

	float DotProd(Vector4 thing)
	{
		return (vec_x*thing.vec_x) + (vec_y*thing.vec_y);


	}


private:
	float vec_x;
	float vec_y;
	float vec_z;
	float vec_w;


};

class Matrix2
{
public:
	Matrix2() {}
	Matrix2(float x1, float x2, float y1, float y2)
	{
		m_x1 = x1;
		m_x2 = x2;
		m_y1 = y1;
		m_y2 = y2;
	}

	Vector2 operator*(Vector2 &vec2)const
	{
		Vector2 car = Vector2(


			((vec2.getX() * vec2.getX()) + (vec2.getY() * vec2.getX())), //X 
			((vec2.getY() * vec2.getX()) + (vec2.getY() * vec2.getY()))  //Y 
		);



		return car;
	}

	Matrix2 operator *(const Matrix2& mult) const
	{
		Matrix2 Matt2;
		Matt2.m_x1 = (m_x1 * mult.m_x1) + (m_x2 * mult.m_y1);
		Matt2.m_x2 = (m_x1 * mult.m_x2) + (m_x2 * mult.m_y2);
		Matt2.m_y1 = (m_y1 * mult.m_x1) + (m_y2 * mult.m_y1);
		Matt2.m_y2 = (m_y1 * mult.m_x2) + (m_y2 * mult.m_y2);

		return Matt2;
	}

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
	Matrix3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3)
	{
		m_x1 = x1;
		m_x2 = x2;
		m_x3 = x3;

		m_y1 = y1;
		m_y2 = y2;
		m_y3 = y3;

		m_z1 = z1;
		m_z2 = z2;
		m_z3 = z3;
	}
	Matrix3 operator *(const Matrix3& mult) const
	{
		Matrix3 bank;
		bank.m_x1 = (m_x1 * mult.m_x1) + (m_x2 * mult.m_y1) + (m_x3 * mult.m_z1);
		bank.m_x2 = (m_x1 * mult.m_x2) + (m_x2 * mult.m_y2) + (m_x3 * mult.m_z2);
		bank.m_x3 = (m_x1 * mult.m_x3) + (m_x2 * mult.m_y3) + (m_x3 * mult.m_z3);

		bank.m_y1 = (m_y1 * mult.m_x1) + (m_y2 * mult.m_y1) + (m_y3 * mult.m_z1);
		bank.m_y2 = (m_y1 * mult.m_x2) + (m_y2 * mult.m_y2) + (m_y3 * mult.m_z2);
		bank.m_y3 = (m_y1 * mult.m_x3) + (m_y2 * mult.m_y3) + (m_y3 * mult.m_z3);

		bank.m_z1 = (m_z1 * mult.m_x1) + (m_z2 * mult.m_z1) + (m_z3 * mult.m_z1);
		bank.m_z2 = (m_z1 * mult.m_z2) + (m_z2 * mult.m_z2) + (m_z3 * mult.m_z2);
		bank.m_z3 = (m_z1 * mult.m_z3) + (m_z2 * mult.m_z3) + (m_z3 * mult.m_z3);
	}

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
	Matrix4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4)
	{
		m_x1 = x1;
		m_x2 = x2;
		m_x3 = x3;
		m_x4 = x4;

		m_y1 = y1;
		m_y2 = y2;
		m_y3 = y3;
		m_y4 = y4;

		m_z1 = z1;
		m_z2 = z2;
		m_z3 = z3;
		m_z4 = z4;

		m_w1 = w1;
		m_w2 = w2;
		m_w3 = w3;
		m_w4 = w4;
	}

	Matrix4 operator *(const Matrix4& mult) const
	{
		Matrix4 bus;

		bus.m_x1 = (m_x1 * mult.m_x1) + (m_x2 * mult.m_y1) + (m_x3 * mult.m_z1) + (m_x4 * mult.m_w1);
		bus.m_x2 = (m_x1 * mult.m_x2) + (m_x2 * mult.m_y2) + (m_x3 * mult.m_z2) + (m_x4 * mult.m_w2);
		bus.m_x3 = (m_x1 * mult.m_x3) + (m_x2 * mult.m_y3) + (m_x3 * mult.m_z3) + (m_x4 * mult.m_w3);
		bus.m_x4 = (m_x1 * mult.m_x4) + (m_x2 * mult.m_y4) + (m_x3 * mult.m_z4) + (m_x4 * mult.m_w4);

		bus.m_y1 = (m_y1 * mult.m_x1) + (m_y2 * mult.m_y1) + (m_y3 * mult.m_z1) + (m_y4 * mult.m_w1);
		bus.m_y2 = (m_y1 * mult.m_x2) + (m_y2 * mult.m_y2) + (m_y3 * mult.m_z2) + (m_y4 * mult.m_w2);
		bus.m_y3 = (m_y1 * mult.m_x3) + (m_y2 * mult.m_y3) + (m_y3 * mult.m_z3) + (m_y4 * mult.m_w3);
		bus.m_y4 = (m_y1 * mult.m_x4) + (m_y2 * mult.m_y4) + (m_y4 * mult.m_z4) + (m_y4 * mult.m_w4);

		bus.m_z1 = (m_z1 * mult.m_x1) + (m_z2 * mult.m_z1) + (m_z3 * mult.m_z1) + (m_z4 * mult.m_w1);
		bus.m_z2 = (m_z1 * mult.m_z2) + (m_z2 * mult.m_z2) + (m_z3 * mult.m_z2) + (m_z4 * mult.m_w2);
		bus.m_z3 = (m_z1 * mult.m_z3) + (m_z2 * mult.m_z3) + (m_z3 * mult.m_z3) + (m_z4 * mult.m_w3);
		bus.m_z4 = (m_z1 * mult.m_z4) + (m_z2 * mult.m_z4) + (m_z4 * mult.m_z4) + (m_z4 * mult.m_w4);

		bus.m_w1 = (m_w1 * mult.m_w1) + (m_w2 * mult.m_w1) + (m_w3 * mult.m_w1) + (m_z4 * mult.m_w1);
		bus.m_w2 = (m_w1 * mult.m_w2) + (m_w2 * mult.m_w2) + (m_w3 * mult.m_w2) + (m_z4 * mult.m_w2);
		bus.m_w3 = (m_w1 * mult.m_w3) + (m_w2 * mult.m_w3) + (m_w3 * mult.m_w3) + (m_z4 * mult.m_w3);
		bus.m_w4 = (m_w1 * mult.m_w4) + (m_w2 * mult.m_w4) + (m_w3 * mult.m_w4) + (m_z4 * mult.m_w4);
	}

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
