#pragma once
#include <exception>
#include <iostream>
#pragma warning (disable:4996)
class OutOfRangeException :public std::exception
{
private:
	char Data[40]="";
public:
	OutOfRangeException(){}
	OutOfRangeException(const char* msg, int index) 
	{
		sprintf(Data, "%s%d", msg, index);
	}
	const char* what() const override
	{
		return Data;
	}
};