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
	 Vector temp = v;
	 temp += w;
	 return temp;//ПЕРЕДЕЛАНО
 }

Vector operator-(const Vector& v, const Vector& w)
{
	return Vector(v +(-w));
}

Vector operator*(const Vector& v, double a)
{
	double* vec = new double[v.GetDim()];
	for (int i = 0; i <v.GetDim() ;++i)
	{ 
		vec[i] = v.GetVec()[i]*a;
	}
	Vector temp(v.GetDim(), vec);
	delete[]vec;
	return temp;
}

Vector operator*(double a, const Vector& v)
{
	Vector temp(v * a);
	return temp;//ПЕРЕДЕЛАНО
}

double operator*(const Vector& v, const Vector& w)
{
    // РАЗМЕРЫ ДОЛЖНЫ БЫТЬ ОДИНАКОВЫМИ, ЕСЛИ НЕТ - БРОСАЕМ ИСКЛЮЧЕНИЕ
	double C = 0;
	if (v.m_dim != w.m_dim)
	{
		throw IncompatibleDimException("Unaccteptable dims!", v.m_dim, w.m_dim);//ПЕРЕДЕЛАНО
	}
	for (int i = 0; i <v.m_dim; ++i)
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
 Vector& Vector::operator=(const Vector& v)
 {
	 if (m_vector != nullptr)
	 {
		 delete[]m_vector;
	 }
	 m_dim = v.m_dim;
	 m_vector = new double[v.m_dim];
	 for (int i = 0; i < m_dim; ++i)
	 {
		 m_vector[i] = v.m_vector[i];
	 }//   ПЕРЕДЕЛАНО  
	 return *this;
 }
 void Vector::operator+=(const Vector& v)//здесь может быть исключение
 {
	 if (this->m_dim ==v.m_dim)
	 {
		 for (int i = 0; i < v.m_dim; ++i)
		 {
			 m_vector[i] += v.m_vector[i];
		 }
	 }
	 else
	 {
		 throw IncompatibleDimException("Impossible to add biger-dim vector to smoller-dim one: ", this->m_dim, v.m_dim);
	 }

 }
 void Vector::operator-=(const Vector& v)//здесь может быть исключение
 {
	 if (this->m_dim = v.m_dim)
	 {
		 for (int i = 0; i < v.m_dim; ++i)
		 {
			 m_vector[i] -= v.m_vector[i];
		 }
	 }
	 else
	 {
		 throw IncompatibleDimException("Impossible to substruct biger-dim vector from smoller-dim one: ", this->m_dim, v.m_dim);
	 }
 }