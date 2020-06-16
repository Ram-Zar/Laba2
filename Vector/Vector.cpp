#include "Vector.h"
 double Vector::getLenght()
{
	double L = 0;
	for (int i = 0; i < m_dim; ++i)
	{
		L += m_vector[i] * m_vector[i];
	}
	return sqrt(L);
}
 Vector Vector::operator-() const
 {
	 Vector v(*this);
	 for (int i = 0; i < m_dim; ++i)
	 {
		 v.m_vector[i] = -v.m_vector[i];
	 }
	 return v;
 }
Vector operator+(const Vector& v, const Vector& w)
{
	int min, max;
	bool F;
	if (v.m_dim > w.m_dim)
	{
		F = true; 
		min = w.m_dim;
		max = v.m_dim;
	}
	else
	{
		F = false;
		min = v.m_dim;
		max = w.m_dim;
	}
	Vector temp(max);
	for (int i = 0; i < max; ++i)
	{
		if (i < min)
		{
			temp.m_vector[i] = v.m_vector[i] + w.m_vector[i];
		}
		else
		{
			if (F == true)
			{
				temp.m_vector[i] += v.m_vector[i];
			}
			else
			{
				temp.m_vector[i] += w.m_vector[i];
			}
		}
	}
	return temp;
}

Vector operator-(const Vector& v, const Vector& w)
{
	return Vector(v +(-w));
}

Vector operator*(const Vector& v, double a)
{
	Vector temp(v);
	for (int i = 0; i < v.m_dim; ++i)
	{
		temp.m_vector[i] *= a;
	}
	return temp;
}

Vector operator*(double a, const Vector& v)
{
	Vector temp(v);
	for (int i = 0; i < v.m_dim; ++i)
	{
		temp.m_vector[i] *= a;
	}
	return temp;
}

double operator*(const Vector& v, const Vector& w)
{
	int min, max;
	double C = 0;
	if (v.m_dim > w.m_dim)
	{
		min = w.m_dim;
		max = v.m_dim;
	}
	else
	{
		min = v.m_dim;
		max = w.m_dim;
	}
	for (int i = 0; i < min; ++i)
	{
		C += v.m_vector[i] * w.m_vector[i];
	}
	return C;
}
 std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << "{";
	for (int i = 0; i < v.m_dim; ++i)
	{
		out << v.m_vector[i];
		if (i < v.m_dim - 1)
		{
			out << ",";
		}
	}
	out << "}";
	return out;
}
 std::istream& operator>>(std::istream& in, Vector& v)
 {
	 if (v.m_dim == -1)
	 {
		 std::cout << "Input vector dimension\ndim=";
		 in >> v.m_dim;
		 v.m_vector = new double[v.m_dim];
	 }
	 for (int i = 0; i < v.m_dim; ++i)
	 {
		 std::cout << "elem[" << i + 1 << "]=";
		 in >> v.m_vector[i];
	 }
	 return in;
 }