#pragma once
#include <iostream>
#include <exception>
class IncompatibleDimException :public std::exception
{
private:
	int m_i;
	int m_size1;
	int m_size2;
public:
	IncompatibleDimException(const char *msg, int N, int M):exception(msg)
	{
		 m_size1=N;
		 m_size2=M;
		 m_i = -1;
	}
	IncompatibleDimException(const char* msg, int index):exception(msg)
	{
		m_i = index;
	}
	void getInfo() 
	{
		if (m_i != -1)
		{
			std::cout << "\nException!" << "\nInfo:\nInputed index:"<< m_i;
		}
		else
		{
			std::cout<< "\nException!"<<"\nInfo:\nInputed size1=" << m_size1 << "\nInputed size2=" << m_size2;
		}
	}
};
