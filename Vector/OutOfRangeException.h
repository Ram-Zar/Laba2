#pragma once
#include <exception>
#include <iostream>
#pragma warning (disable:4996)
class OutOfRangeException :public std::exception
{
private:
	std::string Data;
public:
	OutOfRangeException(){}
	OutOfRangeException(const char* msg, int index) 
	{
		char buff[10];
		Data +msg+ itoa(index, buff, 10);
	}
	const char* what() const override
	{
		return Data.c_str();
	}
};