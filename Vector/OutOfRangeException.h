#pragma once
#include <exception>
#include <iostream>
class OutOfRangeException :public std::exception
{
private:
	int m_data;
	int m_size1;
	int m_size2;
public:
	OutOfRangeException(const char* msg,int data,int size1,int size2):exception(msg)
	{
		m_data = data;
		m_size1 = size1;
		m_size2 = size2;
	}
	OutOfRangeException(const char* msg, int data, int size1) :exception(msg)
	{
		m_data = data;
		m_size1 = size1;
	}
	OutOfRangeException(const char* msg, int size1)
	{
		m_size1 = size1;
	}
    void what()
	{
		std::cout << "Exception!"<<"\nInfo:\nData size=" << m_data << "\nInputed size1=" << m_size1 << "\nInputed size2=" << m_size2;
	}
};