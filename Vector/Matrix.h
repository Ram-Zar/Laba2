#pragma once
#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "OutOfRangeException.h"
using namespace std;
class Vector;
//SPARSE DISSYMMETRICAL MATRIX
class Matrix
{
private:
	int m_N=0;
	int m_M=0;
	int m_col=0;
	double *m_A=nullptr;
	int *m_LI = nullptr;
	int *m_LJ = nullptr;
	void Analiser(double** data)
	{
		int z;
		for (int count = 0, k = 0; k < 2; ++k)
		{
			if (k == 1)
			{
				z = count - 1;
				m_col = count;
				m_A = new double[count];
				m_LJ = new int[count];
			}
			for (int i = m_N - 1; i > -1; --i)
			{
				int line = -1;
				for (int j = m_M - 1; j > -1; --j)
				{
					if (data[i][j] != 0)
					{
						if (k == 0)
						{
							++count;
						}
						else
						{
							m_A[z] = data[i][j];
							m_LJ[z] = j;
							line = z;
							--z;
						}

					}
					if ((j == 0) && (k == 1))
					{
						if (line != -1)
						{
							m_LI[i] = line;
						}
						else
						{
							if (i == m_N - 1)
							{
								m_LI[i] = -1;//last line has zeros
							}
							else
							{
								m_LI[i] = m_LI[i + 1];
							}

						}

					}
				}
			}
		}
	}
public:
	Matrix()
	{}
	Matrix(const Matrix& m)
	{
		m_N = m.m_N;
		m_M = m.m_M;
		m_col = m.m_col;
		m_LI = new int[m_N];
		m_A = new double[m_col];
		m_LJ = new int[m_col];
		for (int i = 0; i < m_col; ++i)
		{
			m_A[i] = m.m_A[i];
			m_LJ[i] = m.m_LJ[i];
		}
		for (int i = 0; i < m_N; ++i)
		{
			m_LI[i] = m.m_LI[i];
		}
	}
	Matrix(int N, int M, double** data)
	{
		if ((((_msize(data) / 4) * (_msize(*data)))/8) != long long(N * M))
		{
			throw IncompatibleDimException("no matching of data size and size of created matrix \ncheck your input: ", int(((_msize(data) / 4) * (_msize(*data))) / 8),N*M);
		}
		
		m_N = N;
		m_M = M;
		m_LI = new int[m_N];
		Analiser(data);	
	}
	~Matrix()
	{
		delete[]m_A;
		delete[]m_LI;
		delete[]m_LJ;
	}
	int GetNonZeroElemAmount()const
	{
		return m_col;
	}
	double* GetNonZeroElem()const
	{
		return m_A;
	}
	int getLenght()const
	{
		return m_N;
	}
	int GetWeight()const
	{
		return m_M;
	}
	void SetNonZeroElems(double* Elems,int size)
	{
		if (m_col != size)
		{
			throw IncompatibleDimException("Unaccteptable sizes: ", m_col, size);
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				m_A[i] = Elems[i];
			}
		}
	}
	friend istream& operator>>(istream& in, Matrix& m);
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend Vector operator*(const Matrix& m, const Vector& v);
	Matrix operator*(const int a);
};
