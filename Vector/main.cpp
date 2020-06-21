#include "Vector.h"
#include <iostream>
#include "Matrix.h"
#include <malloc.h>
using namespace std;
int main()
{
	int idv = 0, idm = 0,i,dim;
	cout << "v" << ++idv << ":\n";
	Vector v1;
    // РАСКОММЕНТИРУЙ ВЫРАЖЕНИЕ НИЖЕ, И ИСПРАВЬ ОШИБКУ КОМПИЛЯЦИИ
    // ВЫРАЖЕНИЕ НЕ ТРОГАТЬ
//    v1 + 1;
	cin >> v1;
	cout << "\nconst v" << ++idv << ":\n";
	cout << "input vector dimension\ndim=";
	cin >> dim;
	double* A;
	A = new double[dim];
	for (int i = 0; i < dim; ++i)
	{
		cout << "elem[" << i + 1 << "]=";
		cin >> A[i];
	}
	const Vector v2(dim,A);
	cout << "\nv" << ++idv << ":\n";
	Vector v3;
	cin >> v3;
	cout << "\nm" << ++idm << ":\n";
	Matrix m1;
	cin >> m1;
	cout << "\n/////Check vector operations:////";
	cout << "\n+v1=";
	cout << +v1;
	cout << "\n-v1=";
	cout << -v1;
	try
	{
    cout << "\nv3+=v1: ";
	v3 += v1;
	cout <<"v3="<< v3;
	cout << "\nv3-=v1: ";
	v3 -= v1;
	cout <<"v3="<< v3;
	}
	catch (IncompatibleDimException& e)
	{
		cout << e.what();
	}
	try
	{
    cout << "\nInput  index to assecc component in v1\ni=";
	cin >> i;
	cout << "v1[" << i << "]=";
	cin >> v1[i];
	cout << "v1="<<v1;
	cout << "\nInput  index to get component in const v2\ni=";
	cin >> i;
	cout << "v2[" << i << "]="<<v2[i];
	}
	catch (OutOfRangeException& e)
	{
		cout<<e.what();
	}
	cout << "\n\nv3 dimension=" << v3.getDim();
	double* p = (double*)v3;
	cout << "\n\ndouble* p = (double*)v3;\np={";
	for (int i = 0; i < v3.getDim(); ++i)
	{
		cout << p[i] << " ";
	}
	cout << "}";
	cout << "\n\nv3 lenght=" << v3.getLenght();
	cout << "\n\nv1*v2=";
	try
	{
		cout << v1 * v2;
	}
	catch (IncompatibleDimException& e)
	{
		cout << e.what();
	}
	cout << "\nInput number   n=";
	cin >> i;
	cout << "\n" << i << "*v1=" << i * v1 << "\nv1*" << i << "=" << v1 * i;
	try
	{
		cout << "\n\nv3+v2=" << v3 + v2;
	    cout << "\n\nv3-v1=" << v3 - v1;
	}
	catch (IncompatibleDimException& e)
	{
		cout << e.what();
	}
	cout << "\n//////Check matrix operations://////";
	cout << "\nInput a numder   n=";
	cin >> i;
	cout << "m1*" << i << "=" << m1 * i<<endl;
	cout << i << "*m1=" << m1 * i;
	cout << "\nm1:lenght=" << m1.getLenght();
	cout << "\nm1: widght=" << m1.GetWeight();
	cout << "\nm1: amount of nonzero elements=" << m1.GetNonZeroElemAmount();
	cout << "\n/////Check vector amd matrix operation://////";
	cout << "\nm2*v4\nnew v4:";
	Vector v4;
	cin >> v4;
	cout << "Input matrix m2;it's important that m2 has a width as v4 has a dim\n";
	Matrix m2;
	cin >> m2;
	try
	{
    cout << "\nm2*v4=" << m2 * v4;
	}
	catch (IncompatibleDimException& e)
	{
		cout << e.what();
	}
	cout << "\nInput v5 ; it's important that v5  has a dim as m2 has width\nv5 dim=";
	cin >> i;
	double* V;
	V = new double[i];
	for (int j = 0; j < i ;++j)
	{
		cout << "\nelem[" << j + 1 << "]=";
		cin >> V[j];
	}
	Vector v5(i, V);
	cout << "\n\n////////Long expression/////\nvector result=v4-m2*3*(v5+v2*4)";
	cout << "\n\nData:";
	cout << "\nm2=" << m2 << "\nv2=" << v2 << "\nv4=" << v4;
	cout << "\nv5=" << v5;
	cout << "\nvector result=v4-m2*3*(v5+v2*4)";
	try
	{
        cout << "\nresult=" << v4 - m2 * 3 * (v5 + v2 * 4);
	}
	catch (IncompatibleDimException& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}
