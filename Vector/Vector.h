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
	Vector(int dim, double* points)
	{
		if (((_msize(points)) / 8) != dim)
		{
			throw OutOfRangeException("No matching of dimension and inputed size", (_msize(points)) / 8,dim);
		}
		m_dim = dim;
		m_vector = new double[dim];
		for (int i = 0; i < m_dim; ++i)
		{
            m_vector[i] = points[i];
		}
	}
	Vector(int dim, double n=0)
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
		m_dim = vec.m_dim;
		m_vector = new double[vec.m_dim];
		for (int i = 0; i < m_dim; ++i)
		{
			m_vector[i] = vec.m_vector[i];
		}
	}
	~Vector()
	{
		delete[]m_vector;
	}
	Vector operator-() const;
	Vector operator+()
	{
		return Vector(*this);
	}
	Vector operator=(const Vector& v)
	{
		return Vector(v);
	}
	void operator+=(const Vector & v)//здесь может быть исключение
	{
		if (this->m_dim >= v.m_dim)
		{
			for (int i = 0; i < v.m_dim; ++i)
			{
				m_vector[i] += v.m_vector[i];
			}
		}
		else
		{
			throw IncompatibleDimException("Impossible to add biger-dim vector to smoller-dim one", this->m_dim, v.m_dim);
		}

	}
	void operator-=(const Vector& v)//здесь может быть исключение
	{
		if (this->m_dim >= v.m_dim)
		{
			for (int i = 0; i < v.m_dim; ++i)
			{
				m_vector[i] -= v.m_vector[i];
			}
		}
		else
		{
			throw IncompatibleDimException("Impossible to substruct biger-dim vector from smoller-dim one", this->m_dim, v.m_dim);
		}
	}
	double & operator[](int i)//может быть исключение
	{
		if ((i < 0) || (i > m_dim - 1))
		{
			{
				throw IncompatibleDimException("Incorrect index",m_dim);
			}
		}
		return m_vector[i];
	}
	 double operator[](int i)const
	{
		return  m_vector[i];
	}
	 int getDim()
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
	friend Vector operator*(const Vector& v, double a);
	friend Vector operator*(double a, const Vector& v);
	friend Vector operator+(const Vector& v, const Vector& w);
	friend Vector operator-(const Vector& v, const Vector& w);
	friend Vector operator*(const Matrix& m, const Vector& v);
};
