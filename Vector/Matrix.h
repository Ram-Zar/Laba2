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
	int m_N;
	int m_M;
	int m_col;
	double *m_A;
	int *m_LI;
	int *m_LJ;
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
	{
	}
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
		cout << sizeof(N);
		if ((((_msize(data) / 4) * (_msize(*data)))/8) != N * M)
		{
			throw OutOfRangeException("no matching of data size and size of created matrix \ncheck your input", ((_msize(data) / 4) * (_msize(*data))) / 8,N,M);
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
	friend istream& operator>>(istream& in, Matrix& m)
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
	friend ostream& operator<<(ostream& out, const Matrix& m)
	{
		for (int i = 0; i < m.m_N; ++i)
		{
			out << endl;
			int line = 0;
			for (int j = 0; j < m.m_M; ++j)
			{
				if (m.m_LI[i] == -1)
				{
					out <<setw(3)<<"0";
				}
				else
				{
                    if (m.m_LJ[m.m_LI[i]+line] == j)
				    {
					    out << setw(3) << m.m_A[m.m_LI[i]+line];
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
	friend Matrix operator*(const Matrix& m, const int a)
	{
		Matrix temp(m);
		for (int i = 0; i < m.m_col; ++i) 
		{
			temp.m_A[i] *= a;
		}
		return temp;
	}
	friend Matrix operator*(const int a,const Matrix& m)
	{
        // ИСПОЛЬЗУЙ Matrix operator*(const Matrix& m, const int a)
        // И УБЕРИ ИЗ ДРУЗЕЙ
		Matrix temp(m);
		for (int i = 0; i < m.m_col; ++i)
		{
			temp.m_A[i] *= a;
		}
		return temp;
	}
	friend Vector operator*(const Matrix& m, const Vector& v)
	{
		double S;
		int line = 0,i = 0;
		Vector temp(m.m_N);
		if (m.m_M == v.m_dim)
		{
			while (i < m.m_N+1)
			{
				line = 0;
				S = 0;
				int j = 0;
				while (j < m.m_M)
				{
					if (m.m_LI[i] != -1)
					{
						if (m.m_LJ[m.m_LI[i] + line] == j)	
						{
							S+=v.m_vector[j]*m.m_A[m.m_LI[i] + line];
							if ((m.m_LI[i + 1] != m.m_LI[i] + 1)||(i==m.m_N-1))
							{
								++line;
							}		
						}
					}
					++j;
				}
				temp.m_vector[i] = S;
				if ((i+1 == m.m_N)&&(j == m.m_M))
				{
					i = m.m_N + 1;
				}
				
				++i;
			}
		}
		else
		{
			throw IncompatibleDimException("no matching of size matrix and vector", m.m_M,v.m_dim);
		}
		return temp;
	}
	int getLenght()
	{
		return m_N;
	}
	int getWidht()
	{
		return m_M;
	}
	int getInfo()
	{
		return m_col;
	}
};
