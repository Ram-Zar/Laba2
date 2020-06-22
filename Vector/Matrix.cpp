#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix Matrix::operator*(const int a)
{
	Matrix temp = *this;
	for (int i = 0; i < m_col; ++i)
	{
		temp.m_A[i] *= a;
	}
	return temp;
}
istream& operator>>(istream& in, Matrix& m)
{
	double** temp;
	cout << "input matrix size\nN=";
	in >> m.m_N;
	cout << "\nM=";
	in >> m.m_M;
	temp = new double* [m.m_N];
	for (int i = 0; i < m.m_N; ++i)
	{
		temp[i] = new double[m.m_M];
	}
	cout << "Input sparse matrix";
	for (int i = 0; i < m.m_N; ++i)
	{
		for (int j = 0; j < m.m_M; ++j)
		{
			cout << "\nelem[" << i << "][" << j << "]=";
			in >> temp[i][j];
		}
	}
	m.m_LI = new int[m.m_N];
	m.Analiser(temp);
	for (int i = 0; i < m.m_N; ++i)
	{
		delete temp[i];
	}
	delete[]temp;
	return in;
}
 ostream& operator<<(ostream& out, const Matrix& m)
{
	for (int i = 0; i < m.m_N; ++i)
	{
		out << endl;
		int line = 0;
		for (int j = 0; j < m.m_M; ++j)
		{
			if (m.m_LI[i] == -1)
			{
				out << setw(3) << "0";
			}
			else
			{
				if (m.m_LJ[m.m_LI[i] + line] == j)
				{
					out << setw(3) << m.m_A[m.m_LI[i] + line];
					++line;
				}
				else
				{
					out << setw(3) << "0";
				}

			}

		}
	}
	return out;
}
 Vector operator*(const Matrix& m, const Vector& v)
 { 
	 Vector temp(m.m_N);
	 if (m.m_M == v.m_dim)
	 { 
		 for (int i = 0; i < m.m_N; ++i)
	     {
			 int IAA = m.m_LI[i],IAB;
		     if (i == m.m_N - 1)IAB = m.m_col;
		     else IAB= m.m_LI[i + 1];   
		     for (int k = IAA; k < IAB; ++k)
		     {
			     temp[i] += m.m_A[k] * v.m_vector[m.m_LJ[k]];
		     }
	     }
	 }
	 else
	 {
		 throw IncompatibleDimException("no matching of size matrix and vector", m.m_M, v.m_dim);
	 }	
	 
	 return temp;
 }
