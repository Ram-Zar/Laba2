#pragma once
#include <iostream>
#include "cmath"
#include "stdlib.h"
#include "IncompatibleDimException.h"
#include "OutOfRangeException.h"
#include <malloc.h>
class Matrix;

class Vector
{
private:
	double* m_vector=nullptr;
	int m_dim=-1;
public:
	Vector()
	{
	}
	explicit Vector(int dim, double* points)
	{
		if (((_msize(points)) / 8) != dim)
		{
			throw IncompatibleDimException("No matching of dimension and inputed size: ", int((_msize(points)) / 8),(dim));
		}
		m_dim = dim;
		m_vector = new double[dim];
		for (int i = 0; i < m_dim; ++i)
		{
            m_vector[i] = points[i];
		}
	}
	explicit Vector(int dim, double n=0)
	{
		m_dim = dim;
		m_vector = new double[dim];
		for (int i = 0; i < m_dim; ++i)
		{
			m_vector[i] = n;
		}
	}
 Vector(const Vector& vec)
	{
		*this = vec;
	}
	~Vector()
	{
		delete[]m_vector;
	}
	int GetDim()const
	{
		return m_dim;
	}
	double* GetVec()const
	{
		return m_vector;
	}
	 Vector operator+()
	{
		return Vector(*this);
	}
	Vector operator-() const;
	Vector& operator=(const Vector& v);
	void operator+=(const Vector& v);//здесь может быть исключение
	void operator-=(const Vector& v);//здесь может быть исключение
	double & operator[](int i)//может быть исключение
	{
		if ((i < 0) || (i > m_dim - 1))
		{
			{
				throw OutOfRangeException("Incorrect index: ",m_dim);
			}
		}
		return m_vector[i];
	}
	 double operator[](int i)const
	{
		 if ((i < 0) || (i > m_dim))
		 {
			 throw OutOfRangeException("Incorrect index: ", m_dim);
		 }
		return  m_vector[i];
	}
	 int getDim()
	 {
		 return m_dim;
	 }
     // ДОБАВЬ ОПЕРАТОР ПРЕОБРАЗОВАНИЯ В int, ПУСТЬ ОН ВОЗВРАЩАЕТ РАЗМЕР ВЕКТОРА
	operator int()
	 {
		 return m_dim;
	 }
	 operator double*()
	 {
		 return m_vector;
	 }
	 double getLenght();
	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	friend std::istream& operator>>(std::istream& in, Vector& v);
	friend double operator*(const Vector& v, const Vector& w);
	friend Vector operator*(const Matrix& m, const Vector& v);
};
Vector operator+(const Vector& v, const Vector& w);
Vector operator-(const Vector& v, const Vector& w);
Vector operator*(const Vector& v, double a);
Vector operator*(double a, const Vector& v);

